/*
 * Vulkan hardware capability viewer command line version
 *
 * Copyright (C) 2022-2023 by Sascha Willems (www.saschawillems.de)
 *
 * This code is free software, you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License version 3 as published by the Free Software Foundation.
 *
 * Please review the following information to ensure the GNU Lesser
 * General Public License version 3 requirements will be met:
 * http://opensource.org/licenses/lgpl-3.0.html
 *
 * The code is distributed WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU LGPL 3.0 for more details.
 *
 */

#include "VulkanCapsViewerCmdLine.h"

VulkanInstance instance;

const std::string appVersion = "1.0";
const std::string reportVersion = "3.2";

struct AdditionalReportData {
    std::string submitter = "";
    std::string comment = "";
} additionalReportData;

#ifdef _WIN32
std::string getOsVersion() {
    HMODULE hDll = LoadLibrary(TEXT("Ntdll.dll"));
    typedef NTSTATUS(CALLBACK* RTLGETVERSION) (PRTL_OSVERSIONINFOW lpVersionInformation);
    RTLGETVERSION pRtlGetVersion;
    pRtlGetVersion = (RTLGETVERSION)GetProcAddress(hDll, "RtlGetVersion");
    if (pRtlGetVersion) {
        RTL_OSVERSIONINFOW ovi = { 0 };
        ovi.dwOSVersionInfoSize = sizeof(ovi);
        NTSTATUS ntStatus = pRtlGetVersion(&ovi);
        if (ntStatus == 0) {
            if (ovi.dwMajorVersion == 10) {
                if (ovi.dwBuildNumber >= 22000) {
                    return "11";
                }
                return "10";
            }
            if (ovi.dwMajorVersion == 6) {
                switch (ovi.dwMinorVersion) {
                case 3:
                    return "8.1";
                case 2:
                    return "8";
                case 1:
                    return "7";
                }
            }
        }
    }
    return "unknown";
}
#endif
bool initVulkan()
{
    if (!instance.create()) {
        std::cerr << "Could not create instance, exiting...";
        exit(-1);
    }

    // Function pointers for new features/properties
    if (instance.supportsDeviceProperties2) {
        vulkanContext.vkGetPhysicalDeviceFeatures2KHR = reinterpret_cast<PFN_vkGetPhysicalDeviceFeatures2KHR>(vkGetInstanceProcAddr(vulkanContext.instance, "vkGetPhysicalDeviceFeatures2KHR"));
        if (!vulkanContext.vkGetPhysicalDeviceFeatures2KHR) {
            std::cerr << "Could not get function pointer for vkGetPhysicalDeviceFeatures2KHR (even though extension is enabled!)" << "\n";
            return false;
        }
        vulkanContext.vkGetPhysicalDeviceProperties2KHR = reinterpret_cast<PFN_vkGetPhysicalDeviceProperties2KHR>(vkGetInstanceProcAddr(vulkanContext.instance, "vkGetPhysicalDeviceProperties2KHR"));
        if (!vulkanContext.vkGetPhysicalDeviceProperties2KHR) {
            std::cerr << "Could not get function pointer for vkGetPhysicalDeviceProperties2KHR (even though extension is enabled!)" << "\n";
            return false;
        }
    }

    vulkanContext.vkGetPhysicalDeviceSurfaceSupportKHR = reinterpret_cast<PFN_vkGetPhysicalDeviceSurfaceSupportKHR>(vkGetInstanceProcAddr(vulkanContext.instance, "vkGetPhysicalDeviceSurfaceSupportKHR"));

    return true;
}

bool createSurface(VkPhysicalDevice physicalDevice)
{
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    HINSTANCE platformHandle = GetModuleHandle(nullptr);
    HWND platformWindow = GetConsoleWindow();
    VkWin32SurfaceCreateInfoKHR surfaceCreateInfo = {};
    surfaceCreateInfo.sType = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
    surfaceCreateInfo.hinstance = (HINSTANCE)platformHandle;
    surfaceCreateInfo.hwnd = (HWND)platformWindow;
    if (vkCreateWin32SurfaceKHR(vulkanContext.instance, &surfaceCreateInfo, nullptr, &vulkanContext.surface) != VK_SUCCESS) {
        return false;
    }
#elif defined(_DIRECT2DISPLAY)
   VkDisplayPlanePropertiesKHR plane;
   VkDisplayModePropertiesKHR mode;
   uint32_t planeCount = 1;
   uint32_t modeCount = 1;
   if (vkGetPhysicalDeviceDisplayPlanePropertiesKHR(physicalDevice, &planeCount, &plane) != VK_SUCCESS) {
      return false;
   }
   if (vkGetDisplayModePropertiesKHR(physicalDevice, plane.currentDisplay, &modeCount, &mode) != VK_SUCCESS) {
      return false;
   }
   VkDisplaySurfaceCreateInfoKHR surfaceCreateInfo = {};
   surfaceCreateInfo.sType = VK_STRUCTURE_TYPE_DISPLAY_SURFACE_CREATE_INFO_KHR;
   surfaceCreateInfo.displayMode = mode.displayMode;
   surfaceCreateInfo.transform = VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR;
   surfaceCreateInfo.globalAlpha = 1.0f;
   surfaceCreateInfo.alphaMode = VK_DISPLAY_PLANE_ALPHA_PER_PIXEL_PREMULTIPLIED_BIT_KHR;
   surfaceCreateInfo.imageExtent = mode.parameters.visibleRegion;
   if (vkCreateDisplayPlaneSurfaceKHR(vulkanContext.instance, &surfaceCreateInfo, nullptr, &vulkanContext.surface) != VK_SUCCESS) {
      return false;
   }
#endif
    return true;
}

// The environment node contains information on the application (versions, etc.) and the operating system
nlohmann::json getEnvironment()
{
    nlohmann::json json = {
        { "appversion", appVersion },
        { "appvariant", "commandline" },
        { "comment", additionalReportData.comment },
        { "submitter", additionalReportData.submitter },
        { "reportversion", reportVersion},
    };

#ifdef _WIN32
    json["name"] = "windows";
    json["version"] = getOsVersion();
#ifdef _WIN64
    json["architecture"] = "x86_64";
#else
    json["architecture"] = "i386";
#endif
#endif

#ifdef __linux__
    struct utsname osinfo;
    if (uname(&osinfo) == 0) {
        json["name"] = osinfo.sysname;
        json["version"] = osinfo.version;
        json["architecture"] = osinfo.machine;
    }
#endif

    return json;
}

void saveReport(const std::string filename, VulkanPhysicalDevice physicalDevice)
{
    nlohmann::json json;

    json["environment"] = getEnvironment();
 
    json["instance"]["extensions"] = instance.getExtensions();
    json["instance"]["layers"] = instance.getLayers();

    json["extensions"] = physicalDevice.getExtensions();
    json["extended"] = physicalDevice.getExtended();
    json["features"] = physicalDevice.getFeatures();
    json["formats"] = physicalDevice.getFormats();
    json["layers"] = physicalDevice.getLayers();
    json["memory"] = physicalDevice.getMemoryTypes();
    json["properties"] = physicalDevice.getProperties();
    json["queues"] = physicalDevice.getQueueFamilies();
    json["surfaceCapabilities"] = physicalDevice.getSurfaceCapabilities();
    if (physicalDevice.vulkanVersionSupported(1, 2)) {
        // Check against 1.2 is correct, as the dedicated structs for 1.1 have been added with 1.2 only
        json["core11"] = physicalDevice.getCore11();
    }
    if (physicalDevice.vulkanVersionSupported(1, 2)) {
        json["core12"] = physicalDevice.getCore12();
    }
    if (physicalDevice.vulkanVersionSupported(1, 3)) {
        json["core13"] = physicalDevice.getCore13();
    }

    std::ofstream file(filename);
    file << std::setw(4) << json;
}

int main(int argc, char* argv[])
{
    CommandLineParser commandLineParser{};
    commandLineParser.add("help", { "--help", "-h"}, false, "Show help");
    commandLineParser.add("gpulist", { "--list", "-l"}, false, "List available devices");
    commandLineParser.add("deviceindex", { "--device", "-d" }, true, "Select device (default is 0)");
    commandLineParser.add("submitter", { "--submitter", "-s" }, true, "Add a submitter to the report (will be visible in the database)");
    commandLineParser.add("comment", { "--comment", "-c" }, true, "Add a comment to the report (will be visible in the database)");
    commandLineParser.parse(argc, argv);

    if (commandLineParser.isSet("help")) {
        commandLineParser.printHelp();
        exit(0);
    }

    initVulkan();

    uint32_t physicalDeviceCount = 0;
    vkEnumeratePhysicalDevices(vulkanContext.instance, &physicalDeviceCount, nullptr);
    std::vector<VkPhysicalDevice> physicalDevices(physicalDeviceCount);
    vkEnumeratePhysicalDevices(vulkanContext.instance, &physicalDeviceCount, &physicalDevices.front());

    if (commandLineParser.isSet("gpulist")) {
        std::cout << "Available devices:" << "\n";
        for (uint32_t i = 0; i < physicalDeviceCount; i++) {
            VkPhysicalDeviceProperties properties;
            vkGetPhysicalDeviceProperties(physicalDevices[i], &properties);
            std::cout << "Device [" << i << "] : " << properties.deviceName << " (Vulkan version: " << (properties.apiVersion >> 22) << "." << ((properties.apiVersion >> 12) & 0x3ff) << "." << (properties.apiVersion & 0xfff) << ")\n";
        }
        exit(0);
    }

    uint32_t deviceIndex = 0;

    if (commandLineParser.isSet("deviceindex")) {
        deviceIndex = commandLineParser.getValueAsInt("deviceindex", 0);
        if ((deviceIndex > physicalDeviceCount - 1) || (deviceIndex < 0)) {
            std::cerr << "Error: Selected device index is out of bounds";
            exit(-1);
        }
    
    }

    if (commandLineParser.isSet("submitter")) {
        additionalReportData.submitter = commandLineParser.getValueAsString("submitter", "");
    }

    if (commandLineParser.isSet("comment")) {
        additionalReportData.comment = commandLineParser.getValueAsString("comment", "");
    }

    createSurface(physicalDevices[deviceIndex]);

    VulkanPhysicalDevice physicalDevice(physicalDevices[deviceIndex]);

    std::string filename = "report.json";

    saveReport(filename, physicalDevice);

    std::cout << "Report saved as " << filename << "\n";

    // Cleanup
    if (vulkanContext.surface != VK_NULL_HANDLE) {
        vkDestroySurfaceKHR(vulkanContext.instance, vulkanContext.surface, nullptr);
    }
    if (vulkanContext.instance != VK_NULL_HANDLE) {
        vkDestroyInstance(vulkanContext.instance, nullptr);
    }
}
