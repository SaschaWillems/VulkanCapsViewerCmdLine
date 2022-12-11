/*
 * Vulkan hardware capability viewer command line version
 *
 * Copyright (C) 2022 by Sascha Willems (www.saschawillems.de)
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
            return "unknown";
        }
    }
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

// The environment node contains information on the application (versions, etc.) and the operating system
nlohmann::json getEnvironment()
{
    nlohmann::json json = {
        { "appversion", appVersion },
        { "appvariant", "commandline" },
        { "comment", "" },
        { "submitter", "" },
        { "reportversion", reportVersion},
        // @tdodo: os architecture, version, name for os
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

int main()
{
    initVulkan();

    uint32_t physicalDeviceCount = 0;
    vkEnumeratePhysicalDevices(vulkanContext.instance, &physicalDeviceCount, nullptr);
    std::vector<VkPhysicalDevice> physicalDevices(physicalDeviceCount);
    vkEnumeratePhysicalDevices(vulkanContext.instance, &physicalDeviceCount, &physicalDevices.front());

    // @todo: add device selection
    VulkanPhysicalDevice physicalDevice(physicalDevices[0]);

    saveReport("report.json", physicalDevice);
}
