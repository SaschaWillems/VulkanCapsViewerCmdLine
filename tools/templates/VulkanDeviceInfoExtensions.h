/*
 * Vulkan hardware capability viewer command line version
 *
 * THIS HEADER IS AUTO-GENERATED, DO NOT CHANGE
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

#ifndef VULKANDEVICEINFOEXTENSIONS_H
#define VULKANDEVICEINFOEXTENSIONS_H

#include <vector>
#include <string>
#include "nlohmann/json.hpp"
#include "vulkan/vulkan.h"
#include "VulkanContext.h"
#include "Utils.h"
#ifdef __ANDROID__
#include <sys/system_properties.h>
#endif

struct Feature2 {
    std::string name;
    VkBool32 supported;
    const char* extension;
    Feature2(std::string n, VkBool32 supp, const char* ext) : name(n), supported(supp), extension(ext) {}
};

struct Property2 {
    nlohmann::json value;
    const char* extension;
    Property2(nlohmann::json val, const char* ext) : value(val), extension(ext) {}
};

class VulkanDeviceInfoExtensions
{
private:
    VkPhysicalDeviceFeatures2 initDeviceFeatures2(void *pNext);
    VkPhysicalDeviceProperties2 initDeviceProperties2(void * pNext);
    void pushProperty2(const char* extension, nlohmann::json value);
    void pushFeature2(const char* extension, std::string name, bool supported);
    bool extensionSupported(const char* extensionName);
{{header_functions}}
public:
    const uint32_t vkHeaderVersion = {{VK_HEADER_VERSION}};
    std::vector<Feature2> features2;
    std::vector<Property2> properties2;
    std::vector<VkExtensionProperties> extensions;
    VkPhysicalDevice handle = VK_NULL_HANDLE;
    void readExtendedFeatures();
    void readExtendedProperties();
};

#endif // VULKANDEVICEINFOEXTENSIONS_H
