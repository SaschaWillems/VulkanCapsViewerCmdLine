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

#include "VulkanInstance.h"

bool VulkanInstance::create()
{
    VkResult vkRes;

    uint32_t instanceApiVersion = VK_API_VERSION_1_0;

    // Get the max. supported Vulkan Version if vkEnumerateInstanceVersion is available (loader version 1.1 and up)
    PFN_vkEnumerateInstanceVersion vkEnumerateInstanceVersion = reinterpret_cast<PFN_vkEnumerateInstanceVersion>(vkGetInstanceProcAddr(nullptr, "vkEnumerateInstanceVersion"));
    if (vkEnumerateInstanceVersion) {
        vkEnumerateInstanceVersion(&instanceApiVersion);
    }

    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "VulkanCapsViewerCmdLine";
    appInfo.applicationVersion = 1;
    appInfo.pEngineName = "VulkanCapsViewerCmdLine";
    appInfo.engineVersion = 1;
    appInfo.apiVersion = instanceApiVersion;

    // Create Vulkan instance
    VkInstanceCreateInfo instanceCreateInfo = {};
    instanceCreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    instanceCreateInfo.pApplicationInfo = &appInfo;

    // Platform specific surface extensions
    std::vector<std::string> possibleSurfaceExtensions = {
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
      VK_KHR_ANDROID_SURFACE_EXTENSION_NAME,
#endif
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
      VK_KHR_WAYLAND_SURFACE_EXTENSION_NAME,
#endif
#if defined(VK_USE_PLATFORM_WIN32_KHR)
      VK_KHR_WIN32_SURFACE_EXTENSION_NAME,
#endif
#if defined(VK_USE_PLATFORM_XCB_KHR)
      VK_KHR_XCB_SURFACE_EXTENSION_NAME,
#endif
#if defined(VK_USE_PLATFORM_MACOS_MVK)
    VK_MVK_MACOS_SURFACE_EXTENSION_NAME,
#endif

#if defined(VK_USE_PLATFORM_IOS_MVK)
   VK_MVK_IOS_SURFACE_EXTENSION_NAME,
#endif
    };

    std::vector<const char*> enabledExtensions = {};

    uint32_t availableExtensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &availableExtensionCount, nullptr);
    std::vector<VkExtensionProperties> availableExtensions(availableExtensionCount);
    vkEnumerateInstanceExtensionProperties(nullptr, &availableExtensionCount, availableExtensions.data());

    if (availableExtensionCount != 0) {
        enabledExtensions.push_back(VK_KHR_SURFACE_EXTENSION_NAME);
    }

    std::vector<std::string> surfaceExtensionsAvailable = {};

    for (const std::string& possibleExtension : possibleSurfaceExtensions) {
        for (const auto& availableExtension : availableExtensions) {
            if (possibleExtension == availableExtension.extensionName) {
                surfaceExtensionsAvailable.push_back(possibleExtension);
                enabledExtensions.push_back(possibleExtension.c_str());
                break;
            }
        }
    }

    // Get instance extensions
    uint32_t extCount;
    vkRes = vkEnumerateInstanceExtensionProperties(nullptr, &extCount, nullptr);
    extensions.resize(extCount);
    vkRes = vkEnumerateInstanceExtensionProperties(nullptr, &extCount, &extensions.front());

    // Check support for new property and feature queries
    for (auto& ext : extensions) {
        if (strcmp(ext.extensionName, VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME) == 0) {
            supportsDeviceProperties2 = true;
            enabledExtensions.push_back(VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME);
            break;
        }
    }

#if defined(VK_USE_PLATFORM_MACOS_MVK) && (VK_HEADER_VERSION >= 216)
    instanceCreateInfo.flags = VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR;
    enabledExtensions.push_back(VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME);
    enabledExtensions.push_back(VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME);
#endif

    instanceCreateInfo.ppEnabledExtensionNames = enabledExtensions.data();
    instanceCreateInfo.enabledExtensionCount = (uint32_t)enabledExtensions.size();

    // Create vulkan Instance
    vkRes = vkCreateInstance(&instanceCreateInfo, nullptr, &vulkanContext.instance);
    if (vkRes != VK_SUCCESS)
    {
        if (vkRes == VK_ERROR_INCOMPATIBLE_DRIVER) {
            std::cerr << "No compatible Vulkan driver found!\nThis version requires a Vulkan driver that is compatible with at least Vulkan 1.1";
        }
        else {
            //  std::cerr << "Could not create Vulkan instance!\nError: " + QString::fromStdString(vulkanResources::resultString(vkRes));
        }
        return false;
    }

    return true;
}

nlohmann::json VulkanInstance::getLayers()
{
    uint32_t layerCount = 0;
    std::vector<VkLayerProperties> instanceLayerProperties;
    vkEnumerateInstanceLayerProperties(&layerCount, nullptr);
    instanceLayerProperties.resize(layerCount);
    if (layerCount > 0) {
        vkEnumerateInstanceLayerProperties(&layerCount, &instanceLayerProperties.front());
    }

    auto jsonArray = nlohmann::json::array();
    for (auto& layer : instanceLayerProperties) {
        jsonArray.push_back(
            {
                { "description", layer.description },
                { "extensions", nlohmann::json::array() }, // @todo
                { "implementationVersion", layer.implementationVersion },
                { "layerName", layer.layerName },
                { "specVersion", layer.specVersion },
            });
    }

    return jsonArray;
}

nlohmann::json VulkanInstance::getExtensions()
{
    auto jsonArray = nlohmann::json::array();
    for (auto& extension : extensions) {
        jsonArray.push_back(
            { 
                { "extensionName", extension.extensionName }, 
                { "specVersion", extension.specVersion } 
            });
    }
    return jsonArray;
}

