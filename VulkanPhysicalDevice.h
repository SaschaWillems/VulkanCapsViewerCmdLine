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

#pragma once

#include <vector>
#include "nlohmann/json.hpp"
#include "vulkan/vulkan.h"
#include "VulkanContext.h"
#include "VulkanDeviceInfoExtensions.h"
#include "Utils.h"

struct VulkanFormatInfo
{
    VkFormat format;
    VkFormatProperties properties;
    bool supported;
};

class VulkanPhysicalDevice : public VulkanDeviceInfoExtensions
{
public:
    VkPhysicalDeviceProperties properties{};

    VulkanPhysicalDevice(VkPhysicalDevice handle);
    bool extensionSupported(const char* extensionName);
    bool vulkanVersionSupported(uint32_t major, uint32_t minor);

    nlohmann::json getExtensions();
    nlohmann::json getExtended();
    nlohmann::json getFeatures();
    nlohmann::json getFormats();
    nlohmann::json getLayers();
    nlohmann::json getMemoryTypes();
    nlohmann::json getProperties();
    nlohmann::json getQueueFamilies();
    nlohmann::json getSurfaceCapabilities();

    nlohmann::json getCore11();
    nlohmann::json getCore12();
    nlohmann::json getCore13();

    std::string getDriverVersion();
};

