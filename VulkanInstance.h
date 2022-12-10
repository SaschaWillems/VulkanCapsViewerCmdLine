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

#include <iostream>
#include <string>
#include <vector>
#include "nlohmann/json.hpp"
#include "vulkan/vulkan.h"
#include "VulkanContext.h"

#pragma once

class VulkanInstance
{
public:
	std::vector<VkExtensionProperties> extensions{};
	bool supportsDeviceProperties2{ false };
	bool create();
	nlohmann::json getLayers();
	nlohmann::json getExtensions();
};

