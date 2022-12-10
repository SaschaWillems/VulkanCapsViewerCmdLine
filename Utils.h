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

#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <vulkan/vulkan.h>

namespace Utils
{
	inline std::string joinString(const char separator, const std::vector<std::string>& stringList)
	{
		std::stringstream ss;
		bool first = true;
		for (const auto& s : stringList) {
			if (!first) ss << separator;
			first = false;
			ss << s;
		}

		return ss.str();
	}

    inline std::string conformanceVersionKHRString(const VkConformanceVersionKHR& conformanceVersion)
    {
        const std::vector<uint8_t> versionAsList = { conformanceVersion.major, conformanceVersion.minor, conformanceVersion.subminor, conformanceVersion.patch };
        std::vector<std::string> versionAsStringList;
        const auto u8ToString = [](const uint8_t num) {
            return std::to_string(static_cast<unsigned>(num));
        };
        std::transform(versionAsList.begin(), versionAsList.end(), std::back_inserter(versionAsStringList), u8ToString);

        return joinString('.', versionAsStringList);
    }

    inline const std::string versionToString(const uint32_t version)
    {
        std::stringstream ss;
        ss << VK_VERSION_MAJOR(version) << "." << VK_VERSION_MINOR(version) << "." << VK_VERSION_PATCH(version);
        return ss.str();
    }

	template<typename Number>
	inline std::string toHexString(const Number number)
	{
		std::stringstream ss;
		ss << std::hex << std::showbase << number;
		return ss.str();
	}

	inline std::string physicalDeviceTypeString(const VkPhysicalDeviceType type)
	{
		switch (type)
		{
#define STR(r) case VK_PHYSICAL_DEVICE_TYPE_##r: return #r
			STR(OTHER);
			STR(INTEGRATED_GPU);
			STR(DISCRETE_GPU);
			STR(VIRTUAL_GPU);
			STR(CPU);
#undef STR
		default: return "UNKNOWN_DEVICE_TYPE (" + toHexString(type) + ")";
		}
	}

};

