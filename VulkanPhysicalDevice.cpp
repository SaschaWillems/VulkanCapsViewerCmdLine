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

#include "VulkanPhysicalDevice.h"

VulkanPhysicalDevice::VulkanPhysicalDevice(VkPhysicalDevice handle) {
    this->handle = handle;
    uint32_t extensionCount = 0;
    vkEnumerateDeviceExtensionProperties(handle, nullptr, &extensionCount, nullptr);
    extensions.resize(extensionCount);
    vkEnumerateDeviceExtensionProperties(handle, nullptr, &extensionCount, &extensions.front());
    vkGetPhysicalDeviceProperties(handle, &properties);
}

bool VulkanPhysicalDevice::extensionSupported(const char* extensionName) {
    for (auto& ext : extensions) {
        if (strcmp(ext.extensionName, extensionName) == 0) {
            return true;
        }
    }
    return false;
}

bool VulkanPhysicalDevice::vulkanVersionSupported(uint32_t major, uint32_t minor)
{
    uint32_t deviceMajor = VK_API_VERSION_MAJOR(properties.apiVersion);
    uint32_t deviceMinor = VK_API_VERSION_MINOR(properties.apiVersion);
    return ((deviceMajor > major) || ((deviceMajor == major) && (deviceMinor >= minor)));
}

std::string VulkanPhysicalDevice::getDriverVersion()
{
    // NVIDIA
    if (properties.vendorID == 4318)
    {
        // 10 bits = major version (up to r1023)
        // 8 bits = minor version (up to 255)
        // 8 bits = secondary branch version/build version (up to 255)
        // 6 bits = tertiary branch/build version (up to 63)
        uint32_t major = (properties.driverVersion >> 22) & 0x3ff;
        uint32_t minor = (properties.driverVersion >> 14) & 0x0ff;
        uint32_t secondaryBranch = (properties.driverVersion >> 6) & 0x0ff;
        uint32_t tertiaryBranch = (properties.driverVersion) & 0x003f;
        return std::to_string(major) + "." + std::to_string(minor) + "." + std::to_string(secondaryBranch) + "." + std::to_string(tertiaryBranch);
    }
    else
    {
        // todo : Add mappings for other vendors
        return std::to_string(VK_VERSION_MAJOR(properties.driverVersion)) + "." + std::to_string(VK_VERSION_MINOR(properties.driverVersion)) + "." + std::to_string(VK_VERSION_PATCH(properties.driverVersion));
    }
}

nlohmann::json VulkanPhysicalDevice::getExtensions()
{
    auto jsonArray = nlohmann::json::array();
    for (auto& extension : extensions) {
        jsonArray.push_back({ { "extensionName", extension.extensionName }, { "specVersion", extension.specVersion } });
    }
    return jsonArray;
}

nlohmann::json VulkanPhysicalDevice::getFeatures()
{
    VkPhysicalDeviceFeatures features{};
    vkGetPhysicalDeviceFeatures(handle, &features);

    nlohmann::json json;
    json["robustBufferAccess"] = features.robustBufferAccess;
    json["fullDrawIndexUint32"] = features.fullDrawIndexUint32;
    json["imageCubeArray"] = features.imageCubeArray;
    json["independentBlend"] = features.independentBlend;
    json["geometryShader"] = features.geometryShader;
    json["tessellationShader"] = features.tessellationShader;
    json["sampleRateShading"] = features.sampleRateShading;
    json["dualSrcBlend"] = features.dualSrcBlend;
    json["logicOp"] = features.logicOp;
    json["multiDrawIndirect"] = features.multiDrawIndirect;
    json["drawIndirectFirstInstance"] = features.drawIndirectFirstInstance;
    json["depthClamp"] = features.depthClamp;
    json["depthBiasClamp"] = features.depthBiasClamp;
    json["fillModeNonSolid"] = features.fillModeNonSolid;
    json["depthBounds"] = features.depthBounds;
    json["wideLines"] = features.wideLines;
    json["largePoints"] = features.largePoints;
    json["alphaToOne"] = features.alphaToOne;
    json["multiViewport"] = features.multiViewport;
    json["samplerAnisotropy"] = features.samplerAnisotropy;
    json["textureCompressionETC2"] = features.textureCompressionETC2;
    json["textureCompressionASTC_LDR"] = features.textureCompressionASTC_LDR;
    json["textureCompressionBC"] = features.textureCompressionBC;
    json["occlusionQueryPrecise"] = features.occlusionQueryPrecise;
    json["pipelineStatisticsQuery"] = features.pipelineStatisticsQuery;
    json["vertexPipelineStoresAndAtomics"] = features.vertexPipelineStoresAndAtomics;
    json["fragmentStoresAndAtomics"] = features.fragmentStoresAndAtomics;
    json["shaderTessellationAndGeometryPointSize"] = features.shaderTessellationAndGeometryPointSize;
    json["shaderImageGatherExtended"] = features.shaderImageGatherExtended;
    json["shaderStorageImageExtendedFormats"] = features.shaderStorageImageExtendedFormats;
    json["shaderStorageImageMultisample"] = features.shaderStorageImageMultisample;
    json["shaderStorageImageReadWithoutFormat"] = features.shaderStorageImageReadWithoutFormat;
    json["shaderStorageImageWriteWithoutFormat"] = features.shaderStorageImageWriteWithoutFormat;
    json["shaderUniformBufferArrayDynamicIndexing"] = features.shaderUniformBufferArrayDynamicIndexing;
    json["shaderSampledImageArrayDynamicIndexing"] = features.shaderSampledImageArrayDynamicIndexing;
    json["shaderStorageBufferArrayDynamicIndexing"] = features.shaderStorageBufferArrayDynamicIndexing;
    json["shaderStorageImageArrayDynamicIndexing"] = features.shaderStorageImageArrayDynamicIndexing;
    json["shaderClipDistance"] = features.shaderClipDistance;
    json["shaderCullDistance"] = features.shaderCullDistance;
    json["shaderFloat64"] = features.shaderFloat64;
    json["shaderInt64"] = features.shaderInt64;
    json["shaderInt16"] = features.shaderInt16;
    json["shaderResourceResidency"] = features.shaderResourceResidency;
    json["shaderResourceMinLod"] = features.shaderResourceMinLod;
    json["sparseBinding"] = features.sparseBinding;
    json["sparseResidencyBuffer"] = features.sparseResidencyBuffer;
    json["sparseResidencyImage2D"] = features.sparseResidencyImage2D;
    json["sparseResidencyImage3D"] = features.sparseResidencyImage3D;
    json["sparseResidency2Samples"] = features.sparseResidency2Samples;
    json["sparseResidency4Samples"] = features.sparseResidency4Samples;
    json["sparseResidency8Samples"] = features.sparseResidency8Samples;
    json["sparseResidency16Samples"] = features.sparseResidency16Samples;
    json["sparseResidencyAliased"] = features.sparseResidencyAliased;
    json["variableMultisampleRate"] = features.variableMultisampleRate;
    json["inheritedQueries"] = features.inheritedQueries;

    return json;
}

nlohmann::json VulkanPhysicalDevice::getFormats()
{
    std::vector<VulkanFormatInfo> formats{};

    // Base formats
    int32_t firstFormat = VK_FORMAT_R4G4_UNORM_PACK8;
    int32_t lastFormat = VK_FORMAT_ASTC_12x12_SRGB_BLOCK;
    for (int32_t format = firstFormat; format <= lastFormat; format++) {
        VulkanFormatInfo formatInfo = {};
        formatInfo.format = (VkFormat)format;
        vkGetPhysicalDeviceFormatProperties(handle, formatInfo.format, &formatInfo.properties);
        formatInfo.supported = (formatInfo.properties.linearTilingFeatures != 0) || (formatInfo.properties.optimalTilingFeatures != 0) || (formatInfo.properties.bufferFeatures != 0);
        formats.push_back(formatInfo);
    }

    // VK_KHR_sampler_ycbcr_conversion
    if (extensionSupported(VK_KHR_SAMPLER_YCBCR_CONVERSION_EXTENSION_NAME)) {
        for (int32_t format = VK_FORMAT_G8B8G8R8_422_UNORM; format < VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM; format++) {
            VulkanFormatInfo formatInfo = {};
            formatInfo.format = (VkFormat)format;
            vkGetPhysicalDeviceFormatProperties(handle, formatInfo.format, &formatInfo.properties);
            formatInfo.supported = (formatInfo.properties.linearTilingFeatures != 0) || (formatInfo.properties.optimalTilingFeatures != 0) || (formatInfo.properties.bufferFeatures != 0);
            formats.push_back(formatInfo);
        }
    }

    // VK_IMG_FORMAT_PVRTC_EXTENSION_NAME
    // @todo: Will be deprecated
    if (extensionSupported(VK_IMG_FORMAT_PVRTC_EXTENSION_NAME)) {
        for (int32_t format = VK_FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG; format < VK_FORMAT_PVRTC2_4BPP_SRGB_BLOCK_IMG; format++) {
            VulkanFormatInfo formatInfo = {};
            formatInfo.format = (VkFormat)format;
            vkGetPhysicalDeviceFormatProperties(handle, formatInfo.format, &formatInfo.properties);
            formatInfo.supported = (formatInfo.properties.linearTilingFeatures != 0) || (formatInfo.properties.optimalTilingFeatures != 0) || (formatInfo.properties.bufferFeatures != 0);
            formats.push_back(formatInfo);
        }
    }

    auto jsonArray = nlohmann::json::array();
    for (auto& format : formats) {
        auto jsonObj = nlohmann::json::object();
        jsonArray.push_back(
            { format.format,
                {
                    { "bufferFeatures", format.properties.bufferFeatures },
                    { "linearTilingFeatures", format.properties.linearTilingFeatures },
                    { "optimalTilingFeatures", format.properties.optimalTilingFeatures },
                    { "supported", format.supported }
                }
            }
        );
    }
    return jsonArray;
}

nlohmann::json VulkanPhysicalDevice::getLayers()
{
    uint32_t layerCount = 0;
    std::vector<VkLayerProperties> layerProperties;
    vkEnumerateDeviceLayerProperties(handle, &layerCount, nullptr);
    layerProperties.resize(layerCount);
    if (layerCount > 0) {
        vkEnumerateDeviceLayerProperties(handle, &layerCount, &layerProperties.front());
    }

    auto jsonArray = nlohmann::json::array();
    for (auto& layer : layerProperties) {
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

nlohmann::json VulkanPhysicalDevice::getMemoryTypes()
{

    VkPhysicalDeviceMemoryProperties memoryProperties{};
    vkGetPhysicalDeviceMemoryProperties(handle, &memoryProperties);

    nlohmann::json json;
    auto jsonArrayHeaps = nlohmann::json::array();
    auto jsonArrayTypes = nlohmann::json::array();

    for (uint32_t i = 0; i < memoryProperties.memoryHeapCount; i++) {
        jsonArrayHeaps.push_back(
            {
                { "flags", memoryProperties.memoryHeaps[i].flags },
                // @todo: databae expects heap size as hex
                { "size", memoryProperties.memoryHeaps[i].size },
            }
        );
    }

    for (uint32_t i = 0; i < memoryProperties.memoryTypeCount; i++) {
        jsonArrayTypes.push_back(
            {
                { "heapIndex", memoryProperties.memoryTypes[i].heapIndex },
                { "propertyFlags", memoryProperties.memoryTypes[i].propertyFlags },
            }
        );
    }

    json = {
        { "memoryHeapCount", memoryProperties.memoryHeapCount },
        { "memoryHeaps", jsonArrayHeaps },
        { "memoryTypeCount", memoryProperties.memoryTypeCount },
        { "memoryTypes", jsonArrayTypes },
    };

    return json;
}

nlohmann::json VulkanPhysicalDevice::getProperties()
{
    VkPhysicalDeviceProperties properties{};
    vkGetPhysicalDeviceProperties(handle, &properties);

    nlohmann::json json = {
        { "deviceName", properties.deviceName },
        { "driverVersion",properties.driverVersion },
        //"driverVersionText", QString::fromStdString(getDriverVersion() },
        { "apiVersion", properties.apiVersion },
        //"apiVersionText", QString::fromStdString(vulkanResources::versionToString(props.apiVersion) },
        { "headerversion", VK_HEADER_VERSION },
        { "vendorID", properties.vendorID },
        { "deviceID", properties.deviceID },
        { "deviceType", properties.deviceType },
        //"deviceTypeText",  QString::fromStdString(vulkanResources::physicalDeviceTypeString(props.deviceType) },
    };

    // @todo
    // Sparse residency properties
    //sparseProperties.clear();
    //sparseProperties["residencyStandard2DBlockShape"] = props.sparseProperties.residencyStandard2DBlockShape;
    //sparseProperties["residencyStandard2DMultisampleBlockShape"] = props.sparseProperties.residencyStandard2DMultisampleBlockShape;
    //sparseProperties["residencyStandard3DBlockShape"] = props.sparseProperties.residencyStandard3DBlockShape;
    //sparseProperties["residencyAlignedMipSize"] = props.sparseProperties.residencyAlignedMipSize;
    //sparseProperties["residencyNonResidentStrict"] = props.sparseProperties.residencyNonResidentStrict;

    if (vulkanVersionSupported(1, 1)) {
        VkPhysicalDeviceProperties2KHR deviceProps2{};
        deviceProps2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR;
        VkPhysicalDeviceSubgroupProperties extProps{};
        extProps.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES;
        deviceProps2.pNext = &extProps;
        vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
        //subgroupProperties["subgroupSize"] = extProps.subgroupSize;
        //subgroupProperties["supportedStages"] = extProps.supportedStages;
        //subgroupProperties["supportedOperations"] = extProps.supportedOperations;
        //subgroupProperties["quadOperationsInAllStages"] = QVariant(bool(extProps.quadOperationsInAllStages));
        // VK_KHR_maintenance3
        if (extensionSupported(VK_KHR_MAINTENANCE3_EXTENSION_NAME)) {
            const char* extName(VK_KHR_MAINTENANCE3_EXTENSION_NAME);
            VkPhysicalDeviceProperties2KHR deviceProps2{};
            VkPhysicalDeviceMaintenance3Properties extProps{};
            extProps.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES;
            deviceProps2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR;
            deviceProps2.pNext = &extProps;
            vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
            //properties2.push_back(Property2("maxPerSetDescriptors", QVariant::fromValue(extProps.maxPerSetDescriptors), extName));
            //properties2.push_back(Property2("maxMemoryAllocationSize", QVariant::fromValue(extProps.maxMemoryAllocationSize), extName));
        }
    }
    return json;
}

nlohmann::json VulkanPhysicalDevice::getQueueFamilies()
{
    uint32_t queueFamilyCount;
    vkGetPhysicalDeviceQueueFamilyProperties(handle, &queueFamilyCount, nullptr);
    std::vector<VkQueueFamilyProperties> queueFamilyProperties(queueFamilyCount);
    vkGetPhysicalDeviceQueueFamilyProperties(handle, &queueFamilyCount, &queueFamilyProperties.front());

    auto jsonArray = nlohmann::json::array();
    for (auto& queueFamily : queueFamilyProperties) {
        bool supportsPresent = false;
        // @todo
        //if ((surface != VK_NULL_HANDLE) && (pfnGetPhysicalDeviceSurfaceSupportKHR)) {
        //    vkGetPhysicalDeviceSurfaceSupportKHR(device, index, surface, &queueFamilyInfo.supportsPresent);
        //}
        jsonArray.push_back(
            {
                { "queueCount", queueFamily.queueCount },
                { "queueFlags", queueFamily.queueFlags },
                { "supportsPresent", supportsPresent },
                { "timestampValidBits", queueFamily.timestampValidBits },
                { "minImageTransferGranularity",
                    {
                        { "depth",  queueFamily.minImageTransferGranularity.depth },
                        { "height",  queueFamily.minImageTransferGranularity.height },
                        { "width",  queueFamily.minImageTransferGranularity.width },
                    },
                },
            }
        );
    }
    return jsonArray;
}

nlohmann::json VulkanPhysicalDevice::getCore11()
{
    // Core 1.1 features and properties are a bit more complicated than 1.2 and newer
    // Dedicated structures for those have only been introduced in Vulkan 1.2

    /*
    // @todo
    VkPhysicalDeviceProperties2KHR deviceProps2{};
    deviceProps2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR;
    VkPhysicalDeviceSubgroupProperties extProps{};
    extProps.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES;
    deviceProps2.pNext = &extProps;
    vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
    //subgroupProperties["subgroupSize"] = extProps.subgroupSize;
    //subgroupProperties["supportedStages"] = extProps.supportedStages;
    //subgroupProperties["supportedOperations"] = extProps.supportedOperations;
    //subgroupProperties["quadOperationsInAllStages"] = QVariant(bool(extProps.quadOperationsInAllStages));
    // VK_KHR_maintenance3
    if (extensionSupported(VK_KHR_MAINTENANCE3_EXTENSION_NAME)) {
        const char* extName(VK_KHR_MAINTENANCE3_EXTENSION_NAME);
        VkPhysicalDeviceProperties2KHR deviceProps2{};
        VkPhysicalDeviceMaintenance3Properties extProps{};
        extProps.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES;
        deviceProps2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR;
        deviceProps2.pNext = &extProps;
        vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
        //properties2.push_back(Property2("maxPerSetDescriptors", QVariant::fromValue(extProps.maxPerSetDescriptors), extName));
        //properties2.push_back(Property2("maxMemoryAllocationSize", QVariant::fromValue(extProps.maxMemoryAllocationSize), extName));
    }
    */
    nlohmann::json json;

    // Vulkan 1.2 introduced dedicated structures for properties promoted to core in 1.1 and 1.2
    VkPhysicalDeviceProperties2KHR deviceProps2{};
    deviceProps2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR;

    VkPhysicalDeviceVulkan11Properties coreProps11{};
    coreProps11.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES;
    deviceProps2.pNext = &coreProps11;
    vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);

    json["properties"] = {
        { "deviceUUID", coreProps11.deviceUUID },
        { "driverUUID", coreProps11.driverUUID },
        { "deviceLUID", coreProps11.deviceLUID },
        { "deviceNodeMask", coreProps11.deviceNodeMask },
        { "deviceLUIDValid", coreProps11.deviceLUIDValid },
        { "subgroupSize", coreProps11.subgroupSize },
        { "subgroupSupportedStages", coreProps11.subgroupSupportedStages },
        { "subgroupSupportedOperations", coreProps11.subgroupSupportedOperations },
        { "subgroupQuadOperationsInAllStages", coreProps11.subgroupQuadOperationsInAllStages },
        { "pointClippingBehavior", coreProps11.pointClippingBehavior },
        { "maxMultiviewViewCount", coreProps11.maxMultiviewViewCount },
        { "maxMultiviewInstanceIndex", coreProps11.maxMultiviewInstanceIndex },
        { "protectedNoFault", coreProps11.protectedNoFault },
        { "maxPerSetDescriptors", coreProps11.maxPerSetDescriptors },
        { "maxMemoryAllocationSize", coreProps11.maxMemoryAllocationSize },
    };

    return json;
}

nlohmann::json VulkanPhysicalDevice::getCore12()
{
    nlohmann::json json;

    // Properties

    VkPhysicalDeviceProperties2KHR deviceProps2{};
    deviceProps2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR;

    VkPhysicalDeviceVulkan12Properties coreProps12{};
    coreProps12.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES;
    deviceProps2.pNext = &coreProps12;
    vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);

    json["properties"] = {
        { "driverID", coreProps12.driverID },
        { "driverName", coreProps12.driverName },
        { "driverInfo", coreProps12.driverInfo },
        { "conformanceVersion", Utils::conformanceVersionKHRString(coreProps12.conformanceVersion) },
        { "denormBehaviorIndependence", coreProps12.denormBehaviorIndependence },
        { "roundingModeIndependence", coreProps12.roundingModeIndependence },
        { "shaderSignedZeroInfNanPreserveFloat16", coreProps12.shaderSignedZeroInfNanPreserveFloat16 },
        { "shaderSignedZeroInfNanPreserveFloat32", coreProps12.shaderSignedZeroInfNanPreserveFloat32 },
        { "shaderSignedZeroInfNanPreserveFloat64", coreProps12.shaderSignedZeroInfNanPreserveFloat64 },
        { "shaderDenormPreserveFloat16", coreProps12.shaderDenormPreserveFloat16 },
        { "shaderDenormPreserveFloat32", coreProps12.shaderDenormPreserveFloat32 },
        { "shaderDenormPreserveFloat64", coreProps12.shaderDenormPreserveFloat64 },
        { "shaderDenormFlushToZeroFloat16", coreProps12.shaderDenormFlushToZeroFloat16 },
        { "shaderDenormFlushToZeroFloat32", coreProps12.shaderDenormFlushToZeroFloat32 },
        { "shaderDenormFlushToZeroFloat64", coreProps12.shaderDenormFlushToZeroFloat64 },
        { "shaderRoundingModeRTEFloat16", coreProps12.shaderRoundingModeRTEFloat16 },
        { "shaderRoundingModeRTEFloat32", coreProps12.shaderRoundingModeRTEFloat32 },
        { "shaderRoundingModeRTEFloat64", coreProps12.shaderRoundingModeRTEFloat64 },
        { "shaderRoundingModeRTZFloat16", coreProps12.shaderRoundingModeRTZFloat16 },
        { "shaderRoundingModeRTZFloat32", coreProps12.shaderRoundingModeRTZFloat32 },
        { "shaderRoundingModeRTZFloat64", coreProps12.shaderRoundingModeRTZFloat64 },
        { "maxUpdateAfterBindDescriptorsInAllPools", coreProps12.maxUpdateAfterBindDescriptorsInAllPools },
        { "shaderUniformBufferArrayNonUniformIndexingNative", coreProps12.shaderUniformBufferArrayNonUniformIndexingNative },
        { "shaderSampledImageArrayNonUniformIndexingNative", coreProps12.shaderSampledImageArrayNonUniformIndexingNative },
        { "shaderStorageBufferArrayNonUniformIndexingNative", coreProps12.shaderStorageBufferArrayNonUniformIndexingNative },
        { "shaderStorageImageArrayNonUniformIndexingNative", coreProps12.shaderStorageImageArrayNonUniformIndexingNative },
        { "shaderInputAttachmentArrayNonUniformIndexingNative", coreProps12.shaderInputAttachmentArrayNonUniformIndexingNative },
        { "robustBufferAccessUpdateAfterBind", coreProps12.robustBufferAccessUpdateAfterBind },
        { "quadDivergentImplicitLod", coreProps12.quadDivergentImplicitLod },
        { "maxPerStageDescriptorUpdateAfterBindSamplers", coreProps12.maxPerStageDescriptorUpdateAfterBindSamplers },
        { "maxPerStageDescriptorUpdateAfterBindUniformBuffers", coreProps12.maxPerStageDescriptorUpdateAfterBindUniformBuffers },
        { "maxPerStageDescriptorUpdateAfterBindStorageBuffers", coreProps12.maxPerStageDescriptorUpdateAfterBindStorageBuffers },
        { "maxPerStageDescriptorUpdateAfterBindSampledImages", coreProps12.maxPerStageDescriptorUpdateAfterBindSampledImages },
        { "maxPerStageDescriptorUpdateAfterBindStorageImages", coreProps12.maxPerStageDescriptorUpdateAfterBindStorageImages },
        { "maxPerStageDescriptorUpdateAfterBindInputAttachments", coreProps12.maxPerStageDescriptorUpdateAfterBindInputAttachments },
        { "maxPerStageUpdateAfterBindResources", coreProps12.maxPerStageUpdateAfterBindResources },
        { "maxDescriptorSetUpdateAfterBindSamplers", coreProps12.maxDescriptorSetUpdateAfterBindSamplers },
        { "maxDescriptorSetUpdateAfterBindUniformBuffers", coreProps12.maxDescriptorSetUpdateAfterBindUniformBuffers },
        { "maxDescriptorSetUpdateAfterBindUniformBuffersDynamic", coreProps12.maxDescriptorSetUpdateAfterBindUniformBuffersDynamic },
        { "maxDescriptorSetUpdateAfterBindStorageBuffers", coreProps12.maxDescriptorSetUpdateAfterBindStorageBuffers },
        { "maxDescriptorSetUpdateAfterBindStorageBuffersDynamic", coreProps12.maxDescriptorSetUpdateAfterBindStorageBuffersDynamic },
        { "maxDescriptorSetUpdateAfterBindSampledImages", coreProps12.maxDescriptorSetUpdateAfterBindSampledImages },
        { "maxDescriptorSetUpdateAfterBindStorageImages", coreProps12.maxDescriptorSetUpdateAfterBindStorageImages },
        { "maxDescriptorSetUpdateAfterBindInputAttachments", coreProps12.maxDescriptorSetUpdateAfterBindInputAttachments },
        { "supportedDepthResolveModes", coreProps12.supportedDepthResolveModes },
        { "supportedStencilResolveModes", coreProps12.supportedStencilResolveModes },
        { "independentResolveNone", coreProps12.independentResolveNone },
        { "independentResolve", coreProps12.independentResolve },
        { "filterMinmaxSingleComponentFormats", coreProps12.filterMinmaxSingleComponentFormats },
        { "filterMinmaxImageComponentMapping", coreProps12.filterMinmaxImageComponentMapping },
        { "maxTimelineSemaphoreValueDifference", std::to_string(coreProps12.maxTimelineSemaphoreValueDifference) },
        { "framebufferIntegerColorSampleCounts", coreProps12.framebufferIntegerColorSampleCounts },
    };

    // Features

    VkPhysicalDeviceFeatures2KHR deviceFeatures2{};
    deviceFeatures2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR;

    VkPhysicalDeviceVulkan12Features coreFeatures12{};
    coreFeatures12.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES;
    deviceFeatures2.pNext = &coreFeatures12;
    vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);

    json["features"] = {
        { "samplerMirrorClampToEdge", coreFeatures12.samplerMirrorClampToEdge },
        { "drawIndirectCount", coreFeatures12.drawIndirectCount },
        { "storageBuffer8BitAccess", coreFeatures12.storageBuffer8BitAccess },
        { "uniformAndStorageBuffer8BitAccess", coreFeatures12.uniformAndStorageBuffer8BitAccess },
        { "storagePushConstant8", coreFeatures12.storagePushConstant8 },
        { "shaderBufferInt64Atomics", coreFeatures12.shaderBufferInt64Atomics },
        { "shaderSharedInt64Atomics", coreFeatures12.shaderSharedInt64Atomics },
        { "shaderFloat16", coreFeatures12.shaderFloat16 },
        { "shaderInt8", coreFeatures12.shaderInt8 },
        { "descriptorIndexing", coreFeatures12.descriptorIndexing },
        { "shaderInputAttachmentArrayDynamicIndexing", coreFeatures12.shaderInputAttachmentArrayDynamicIndexing },
        { "shaderUniformTexelBufferArrayDynamicIndexing", coreFeatures12.shaderUniformTexelBufferArrayDynamicIndexing },
        { "shaderStorageTexelBufferArrayDynamicIndexing", coreFeatures12.shaderStorageTexelBufferArrayDynamicIndexing },
        { "shaderUniformBufferArrayNonUniformIndexing", coreFeatures12.shaderUniformBufferArrayNonUniformIndexing },
        { "shaderSampledImageArrayNonUniformIndexing", coreFeatures12.shaderSampledImageArrayNonUniformIndexing },
        { "shaderStorageBufferArrayNonUniformIndexing", coreFeatures12.shaderStorageBufferArrayNonUniformIndexing },
        { "shaderStorageImageArrayNonUniformIndexing", coreFeatures12.shaderStorageImageArrayNonUniformIndexing },
        { "shaderInputAttachmentArrayNonUniformIndexing", coreFeatures12.shaderInputAttachmentArrayNonUniformIndexing },
        { "shaderUniformTexelBufferArrayNonUniformIndexing", coreFeatures12.shaderUniformTexelBufferArrayNonUniformIndexing },
        { "shaderStorageTexelBufferArrayNonUniformIndexing", coreFeatures12.shaderStorageTexelBufferArrayNonUniformIndexing },
        { "descriptorBindingUniformBufferUpdateAfterBind", coreFeatures12.descriptorBindingUniformBufferUpdateAfterBind },
        { "descriptorBindingSampledImageUpdateAfterBind", coreFeatures12.descriptorBindingSampledImageUpdateAfterBind },
        { "descriptorBindingStorageImageUpdateAfterBind", coreFeatures12.descriptorBindingStorageImageUpdateAfterBind },
        { "descriptorBindingStorageBufferUpdateAfterBind", coreFeatures12.descriptorBindingStorageBufferUpdateAfterBind },
        { "descriptorBindingUniformTexelBufferUpdateAfterBind", coreFeatures12.descriptorBindingUniformTexelBufferUpdateAfterBind },
        { "descriptorBindingStorageTexelBufferUpdateAfterBind", coreFeatures12.descriptorBindingStorageTexelBufferUpdateAfterBind },
        { "descriptorBindingUpdateUnusedWhilePending", coreFeatures12.descriptorBindingUpdateUnusedWhilePending },
        { "descriptorBindingPartiallyBound", coreFeatures12.descriptorBindingPartiallyBound },
        { "descriptorBindingVariableDescriptorCount", coreFeatures12.descriptorBindingVariableDescriptorCount },
        { "runtimeDescriptorArray", coreFeatures12.runtimeDescriptorArray },
        { "samplerFilterMinmax", coreFeatures12.samplerFilterMinmax },
        { "scalarBlockLayout", coreFeatures12.scalarBlockLayout },
        { "imagelessFramebuffer", coreFeatures12.imagelessFramebuffer },
        { "uniformBufferStandardLayout", coreFeatures12.uniformBufferStandardLayout },
        { "shaderSubgroupExtendedTypes", coreFeatures12.shaderSubgroupExtendedTypes },
        { "separateDepthStencilLayouts", coreFeatures12.separateDepthStencilLayouts },
        { "hostQueryReset", coreFeatures12.hostQueryReset },
        { "timelineSemaphore", coreFeatures12.timelineSemaphore },
        { "bufferDeviceAddress", coreFeatures12.bufferDeviceAddress },
        { "bufferDeviceAddressCaptureReplay", coreFeatures12.bufferDeviceAddressCaptureReplay },
        { "bufferDeviceAddressMultiDevice", coreFeatures12.bufferDeviceAddressMultiDevice },
        { "vulkanMemoryModel", coreFeatures12.vulkanMemoryModel },
        { "vulkanMemoryModelDeviceScope", coreFeatures12.vulkanMemoryModelDeviceScope },
        { "vulkanMemoryModelAvailabilityVisibilityChains", coreFeatures12.vulkanMemoryModelAvailabilityVisibilityChains },
        { "shaderOutputViewportIndex", coreFeatures12.shaderOutputViewportIndex },
        { "shaderOutputLayer", coreFeatures12.shaderOutputLayer },
        { "subgroupBroadcastDynamicId", coreFeatures12.subgroupBroadcastDynamicId },
    };

    return json;
}

nlohmann::json VulkanPhysicalDevice::getCore13()
{
    nlohmann::json json;

    // Properties

    VkPhysicalDeviceProperties2KHR deviceProps2{};
    deviceProps2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR;

    VkPhysicalDeviceVulkan13Properties coreProps13{};
    coreProps13.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES;
    deviceProps2.pNext = &coreProps13;
    vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);

    json["properties"] = {
        { "minSubgroupSize", coreProps13.minSubgroupSize },
        { "maxSubgroupSize", coreProps13.maxSubgroupSize },
        { "maxComputeWorkgroupSubgroups", coreProps13.maxComputeWorkgroupSubgroups },
        { "requiredSubgroupSizeStages", coreProps13.requiredSubgroupSizeStages },
        { "maxInlineUniformBlockSize", coreProps13.maxInlineUniformBlockSize },
        { "maxPerStageDescriptorInlineUniformBlocks", coreProps13.maxPerStageDescriptorInlineUniformBlocks },
        { "maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks", coreProps13.maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks },
        { "maxDescriptorSetInlineUniformBlocks", coreProps13.maxDescriptorSetInlineUniformBlocks },
        { "maxDescriptorSetUpdateAfterBindInlineUniformBlocks", coreProps13.maxDescriptorSetUpdateAfterBindInlineUniformBlocks },
        { "maxInlineUniformTotalSize", coreProps13.maxInlineUniformTotalSize },
        { "integerDotProduct8BitUnsignedAccelerated", coreProps13.integerDotProduct8BitUnsignedAccelerated },
        { "integerDotProduct8BitSignedAccelerated", coreProps13.integerDotProduct8BitSignedAccelerated },
        { "integerDotProduct8BitMixedSignednessAccelerated", coreProps13.integerDotProduct8BitMixedSignednessAccelerated },
        { "integerDotProduct4x8BitPackedUnsignedAccelerated", coreProps13.integerDotProduct4x8BitPackedUnsignedAccelerated },
        { "integerDotProduct4x8BitPackedSignedAccelerated", coreProps13.integerDotProduct4x8BitPackedSignedAccelerated },
        { "integerDotProduct4x8BitPackedMixedSignednessAccelerated", coreProps13.integerDotProduct4x8BitPackedMixedSignednessAccelerated },
        { "integerDotProduct16BitUnsignedAccelerated", coreProps13.integerDotProduct16BitUnsignedAccelerated },
        { "integerDotProduct16BitSignedAccelerated", coreProps13.integerDotProduct16BitSignedAccelerated },
        { "integerDotProduct16BitMixedSignednessAccelerated", coreProps13.integerDotProduct16BitMixedSignednessAccelerated },
        { "integerDotProduct32BitUnsignedAccelerated", coreProps13.integerDotProduct32BitUnsignedAccelerated },
        { "integerDotProduct32BitSignedAccelerated", coreProps13.integerDotProduct32BitSignedAccelerated },
        { "integerDotProduct32BitMixedSignednessAccelerated", coreProps13.integerDotProduct32BitMixedSignednessAccelerated },
        { "integerDotProduct64BitUnsignedAccelerated", coreProps13.integerDotProduct64BitUnsignedAccelerated },
        { "integerDotProduct64BitSignedAccelerated", coreProps13.integerDotProduct64BitSignedAccelerated },
        { "integerDotProduct64BitMixedSignednessAccelerated", coreProps13.integerDotProduct64BitMixedSignednessAccelerated },
        { "integerDotProductAccumulatingSaturating8BitUnsignedAccelerated", coreProps13.integerDotProductAccumulatingSaturating8BitUnsignedAccelerated },
        { "integerDotProductAccumulatingSaturating8BitSignedAccelerated", coreProps13.integerDotProductAccumulatingSaturating8BitSignedAccelerated },
        { "integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated", coreProps13.integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated },
        { "integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated", coreProps13.integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated },
        { "integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated", coreProps13.integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated },
        { "integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated", coreProps13.integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated },
        { "integerDotProductAccumulatingSaturating16BitUnsignedAccelerated", coreProps13.integerDotProductAccumulatingSaturating16BitUnsignedAccelerated },
        { "integerDotProductAccumulatingSaturating16BitSignedAccelerated", coreProps13.integerDotProductAccumulatingSaturating16BitSignedAccelerated },
        { "integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated", coreProps13.integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated },
        { "integerDotProductAccumulatingSaturating32BitUnsignedAccelerated", coreProps13.integerDotProductAccumulatingSaturating32BitUnsignedAccelerated },
        { "integerDotProductAccumulatingSaturating32BitSignedAccelerated", coreProps13.integerDotProductAccumulatingSaturating32BitSignedAccelerated },
        { "integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated", coreProps13.integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated },
        { "integerDotProductAccumulatingSaturating64BitUnsignedAccelerated", coreProps13.integerDotProductAccumulatingSaturating64BitUnsignedAccelerated },
        { "integerDotProductAccumulatingSaturating64BitSignedAccelerated", coreProps13.integerDotProductAccumulatingSaturating64BitSignedAccelerated },
        { "integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated", coreProps13.integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated },
        { "storageTexelBufferOffsetAlignmentBytes", coreProps13.storageTexelBufferOffsetAlignmentBytes },
        { "storageTexelBufferOffsetSingleTexelAlignment", coreProps13.storageTexelBufferOffsetSingleTexelAlignment },
        { "uniformTexelBufferOffsetAlignmentBytes", coreProps13.uniformTexelBufferOffsetAlignmentBytes },
        { "uniformTexelBufferOffsetSingleTexelAlignment", coreProps13.uniformTexelBufferOffsetSingleTexelAlignment },
        { "maxBufferSize", std::to_string(coreProps13.maxBufferSize) },
    };

    // Features

    VkPhysicalDeviceFeatures2KHR deviceFeatures2{};
    deviceFeatures2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR;

    VkPhysicalDeviceVulkan13Features coreFeatures13{};
    coreFeatures13.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES;
    deviceFeatures2.pNext = &coreFeatures13;
    vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);

    json["features"] = {
        { "robustImageAccess", coreFeatures13.robustImageAccess },
        { "inlineUniformBlock", coreFeatures13.inlineUniformBlock },
        { "descriptorBindingInlineUniformBlockUpdateAfterBind", coreFeatures13.descriptorBindingInlineUniformBlockUpdateAfterBind },
        { "pipelineCreationCacheControl", coreFeatures13.pipelineCreationCacheControl },
        { "privateData", coreFeatures13.privateData },
        { "shaderDemoteToHelperInvocation", coreFeatures13.shaderDemoteToHelperInvocation },
        { "shaderTerminateInvocation", coreFeatures13.shaderTerminateInvocation },
        { "subgroupSizeControl", coreFeatures13.subgroupSizeControl },
        { "computeFullSubgroups", coreFeatures13.computeFullSubgroups },
        { "synchronization2", coreFeatures13.synchronization2 },
        { "textureCompressionASTC_HDR", coreFeatures13.textureCompressionASTC_HDR },
        { "shaderZeroInitializeWorkgroupMemory", coreFeatures13.shaderZeroInitializeWorkgroupMemory },
        { "dynamicRendering", coreFeatures13.dynamicRendering },
        { "shaderIntegerDotProduct", coreFeatures13.shaderIntegerDotProduct },
        { "maintenance4", coreFeatures13.maintenance4 },
    };

    return json;
}
