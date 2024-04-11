/*
 * Vulkan hardware capability viewer command line version
 *
 * Copyright (C) 2022-2024 by Sascha Willems (www.saschawillems.de)
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
    // Broadcom
    else if (properties.vendorID == 5348)
    {
        // Version encoded as human-readable (10000 * major + 100 * minor)
        uint32_t major = properties.driverVersion / 10000;
        uint32_t minor = (properties.driverVersion % 10000) / 100;
        return std::to_string(major) + "." + std::to_string(minor);
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

// Get extension properties and features from auto-generated source
nlohmann::json VulkanPhysicalDevice::getExtended()
{
    nlohmann::json json;

    // Check if context checks are needed (app should close if fnptr can't be fetched)

    if (vulkanContext.vkGetPhysicalDeviceFeatures2KHR) {
        readExtendedFeatures();

        auto jsonArray = nlohmann::json::array();
        for (auto& extendedFeature : features2) {
            jsonArray.push_back(
                {
                    { "extension", extendedFeature.extension },
                    { "name", extendedFeature.name },
                    { "supported", extendedFeature.supported ? true : false },
                }
            );
        }
        json["devicefeatures2"] = jsonArray;
    }

    if (vulkanContext.vkGetPhysicalDeviceProperties2KHR) {
        readExtendedProperties();

        auto jsonArray = nlohmann::json::array();
        for (auto& extendedProperty : properties2) {
            jsonArray.push_back(extendedProperty.value);
        }
        json["deviceproperties2"] = jsonArray;
    }

    return json;
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
                    { "bufferFeatures", std::to_string(format.properties.bufferFeatures) },
                    { "linearTilingFeatures", std::to_string(format.properties.linearTilingFeatures) },
                    { "optimalTilingFeatures", std::to_string(format.properties.optimalTilingFeatures) },
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
        { "driverVersion", properties.driverVersion },
        { "driverVersionText", getDriverVersion() },
        { "apiVersion", properties.apiVersion },
        { "apiVersionText", Utils::versionToString(properties.apiVersion) },
        { "headerversion", VK_HEADER_VERSION },
        { "vendorID", properties.vendorID },
        { "deviceID", properties.deviceID },
        { "deviceType", properties.deviceType },
        { "deviceTypeText", Utils::physicalDeviceTypeString(properties.deviceType) },
        { "pipelineCacheUUID", properties.pipelineCacheUUID },
        {
            "sparseProperties", {
                { "residencyStandard2DBlockShape", properties.sparseProperties.residencyStandard2DBlockShape },
                { "residencyStandard2DMultisampleBlockShape", properties.sparseProperties.residencyStandard2DMultisampleBlockShape },
                { "residencyStandard3DBlockShape", properties.sparseProperties.residencyStandard3DBlockShape },
                { "residencyAlignedMipSize", properties.sparseProperties.residencyAlignedMipSize },
                { "residencyNonResidentStrict", properties.sparseProperties.residencyNonResidentStrict },
            }
        },
        {
            "limits", {
                { "maxImageDimension1D", properties.limits.maxImageDimension1D },
                { "maxImageDimension2D", properties.limits.maxImageDimension2D },
                { "maxImageDimension3D", properties.limits.maxImageDimension3D },
                { "maxImageDimensionCube", properties.limits.maxImageDimensionCube },
                { "maxImageArrayLayers", properties.limits.maxImageArrayLayers },
                { "maxTexelBufferElements", properties.limits.maxTexelBufferElements },
                { "maxUniformBufferRange", properties.limits.maxUniformBufferRange },
                { "maxStorageBufferRange", properties.limits.maxStorageBufferRange },
                { "maxPushConstantsSize", properties.limits.maxPushConstantsSize },
                { "maxMemoryAllocationCount", properties.limits.maxMemoryAllocationCount },
                { "maxSamplerAllocationCount", properties.limits.maxSamplerAllocationCount },
                { "bufferImageGranularity", properties.limits.bufferImageGranularity },
                { "sparseAddressSpaceSize", properties.limits.sparseAddressSpaceSize },
                { "maxBoundDescriptorSets", properties.limits.maxBoundDescriptorSets },
                { "maxPerStageDescriptorSamplers", properties.limits.maxPerStageDescriptorSamplers },
                { "maxPerStageDescriptorUniformBuffers", properties.limits.maxPerStageDescriptorUniformBuffers },
                { "maxPerStageDescriptorStorageBuffers", properties.limits.maxPerStageDescriptorStorageBuffers },
                { "maxPerStageDescriptorSampledImages", properties.limits.maxPerStageDescriptorSampledImages },
                { "maxPerStageDescriptorStorageImages", properties.limits.maxPerStageDescriptorStorageImages },
                { "maxPerStageDescriptorInputAttachments", properties.limits.maxPerStageDescriptorInputAttachments },
                { "maxPerStageResources", properties.limits.maxPerStageResources },
                { "maxDescriptorSetSamplers", properties.limits.maxDescriptorSetSamplers },
                { "maxDescriptorSetUniformBuffers", properties.limits.maxDescriptorSetUniformBuffers },
                { "maxDescriptorSetUniformBuffersDynamic", properties.limits.maxDescriptorSetUniformBuffersDynamic },
                { "maxDescriptorSetStorageBuffers", properties.limits.maxDescriptorSetStorageBuffers },
                { "maxDescriptorSetStorageBuffersDynamic", properties.limits.maxDescriptorSetStorageBuffersDynamic },
                { "maxDescriptorSetSampledImages", properties.limits.maxDescriptorSetSampledImages },
                { "maxDescriptorSetStorageImages", properties.limits.maxDescriptorSetStorageImages },
                { "maxDescriptorSetInputAttachments", properties.limits.maxDescriptorSetInputAttachments },
                { "maxVertexInputAttributes", properties.limits.maxVertexInputAttributes },
                { "maxVertexInputBindings", properties.limits.maxVertexInputBindings },
                { "maxVertexInputAttributeOffset", properties.limits.maxVertexInputAttributeOffset },
                { "maxVertexInputBindingStride", properties.limits.maxVertexInputBindingStride },
                { "maxVertexOutputComponents", properties.limits.maxVertexOutputComponents },
                { "maxTessellationGenerationLevel", properties.limits.maxTessellationGenerationLevel },
                { "maxTessellationPatchSize", properties.limits.maxTessellationPatchSize },
                { "maxTessellationControlPerVertexInputComponents", properties.limits.maxTessellationControlPerVertexInputComponents },
                { "maxTessellationControlPerVertexOutputComponents", properties.limits.maxTessellationControlPerVertexOutputComponents },
                { "maxTessellationControlPerPatchOutputComponents", properties.limits.maxTessellationControlPerPatchOutputComponents },
                { "maxTessellationControlTotalOutputComponents", properties.limits.maxTessellationControlTotalOutputComponents },
                { "maxTessellationEvaluationInputComponents", properties.limits.maxTessellationEvaluationInputComponents },
                { "maxTessellationEvaluationOutputComponents", properties.limits.maxTessellationEvaluationOutputComponents },
                { "maxGeometryShaderInvocations", properties.limits.maxGeometryShaderInvocations },
                { "maxGeometryInputComponents", properties.limits.maxGeometryInputComponents },
                { "maxGeometryOutputComponents", properties.limits.maxGeometryOutputComponents },
                { "maxGeometryOutputVertices", properties.limits.maxGeometryOutputVertices },
                { "maxGeometryTotalOutputComponents", properties.limits.maxGeometryTotalOutputComponents },
                { "maxFragmentInputComponents", properties.limits.maxFragmentInputComponents },
                { "maxFragmentOutputAttachments", properties.limits.maxFragmentOutputAttachments },
                { "maxFragmentDualSrcAttachments", properties.limits.maxFragmentDualSrcAttachments },
                { "maxFragmentCombinedOutputResources", properties.limits.maxFragmentCombinedOutputResources },
                { "maxComputeSharedMemorySize", properties.limits.maxComputeSharedMemorySize },
                { "maxComputeWorkGroupCount", { properties.limits.maxComputeWorkGroupCount[0], properties.limits.maxComputeWorkGroupCount[1], properties.limits.maxComputeWorkGroupCount[2] } },
                { "maxComputeWorkGroupInvocations", properties.limits.maxComputeWorkGroupInvocations },
                { "maxComputeWorkGroupSize", { properties.limits.maxComputeWorkGroupSize[0], properties.limits.maxComputeWorkGroupSize[1], properties.limits.maxComputeWorkGroupSize[2] } },
                { "subPixelPrecisionBits", properties.limits.subPixelPrecisionBits },
                { "subTexelPrecisionBits", properties.limits.subTexelPrecisionBits },
                { "mipmapPrecisionBits", properties.limits.mipmapPrecisionBits },
                { "maxDrawIndexedIndexValue", properties.limits.maxDrawIndexedIndexValue },
                { "maxDrawIndirectCount", properties.limits.maxDrawIndirectCount },
                { "maxSamplerLodBias", properties.limits.maxSamplerLodBias },
                { "maxSamplerAnisotropy", properties.limits.maxSamplerAnisotropy },
                { "maxViewports", properties.limits.maxViewports },
                { "maxViewportDimensions", { properties.limits.maxViewportDimensions[0], properties.limits.maxViewportDimensions[1] } },
                { "viewportBoundsRange", { properties.limits.viewportBoundsRange[0], properties.limits.viewportBoundsRange[1] } },
                { "viewportSubPixelBits", properties.limits.viewportSubPixelBits },
                { "minMemoryMapAlignment", properties.limits.minMemoryMapAlignment },
                { "minTexelBufferOffsetAlignment", properties.limits.minTexelBufferOffsetAlignment },
                { "minUniformBufferOffsetAlignment", properties.limits.minUniformBufferOffsetAlignment },
                { "minStorageBufferOffsetAlignment", properties.limits.minStorageBufferOffsetAlignment },
                { "minTexelOffset", properties.limits.minTexelOffset },
                { "maxTexelOffset", properties.limits.maxTexelOffset },
                { "minTexelGatherOffset", properties.limits.minTexelGatherOffset },
                { "maxTexelGatherOffset", properties.limits.maxTexelGatherOffset },
                { "minInterpolationOffset", properties.limits.minInterpolationOffset },
                { "maxInterpolationOffset", properties.limits.maxInterpolationOffset },
                { "subPixelInterpolationOffsetBits", properties.limits.subPixelInterpolationOffsetBits },
                { "maxFramebufferWidth", properties.limits.maxFramebufferWidth },
                { "maxFramebufferHeight", properties.limits.maxFramebufferHeight },
                { "maxFramebufferLayers", properties.limits.maxFramebufferLayers },
                { "framebufferColorSampleCounts", properties.limits.framebufferColorSampleCounts },
                { "framebufferDepthSampleCounts", properties.limits.framebufferDepthSampleCounts },
                { "framebufferStencilSampleCounts", properties.limits.framebufferStencilSampleCounts },
                { "framebufferNoAttachmentsSampleCounts", properties.limits.framebufferNoAttachmentsSampleCounts },
                { "maxColorAttachments", properties.limits.maxColorAttachments },
                { "sampledImageColorSampleCounts", properties.limits.sampledImageColorSampleCounts },
                { "sampledImageIntegerSampleCounts", properties.limits.sampledImageIntegerSampleCounts },
                { "sampledImageDepthSampleCounts", properties.limits.sampledImageDepthSampleCounts },
                { "sampledImageStencilSampleCounts", properties.limits.sampledImageStencilSampleCounts },
                { "storageImageSampleCounts", properties.limits.storageImageSampleCounts },
                { "maxSampleMaskWords", properties.limits.maxSampleMaskWords },
                { "timestampComputeAndGraphics", properties.limits.timestampComputeAndGraphics },
                { "timestampPeriod", properties.limits.timestampPeriod },
                { "maxClipDistances", properties.limits.maxClipDistances },
                { "maxCullDistances", properties.limits.maxCullDistances },
                { "maxCombinedClipAndCullDistances", properties.limits.maxCombinedClipAndCullDistances },
                { "discreteQueuePriorities", properties.limits.discreteQueuePriorities },
                { "pointSizeRange", { properties.limits.pointSizeRange[0], properties.limits.pointSizeRange[1] } },
                { "lineWidthRange", { properties.limits.lineWidthRange[0], properties.limits.lineWidthRange[1] } },
                { "pointSizeGranularity", properties.limits.pointSizeGranularity },
                { "lineWidthGranularity", properties.limits.lineWidthGranularity },
                { "strictLines", properties.limits.strictLines },
                { "standardSampleLocations", properties.limits.standardSampleLocations },
                { "optimalBufferCopyOffsetAlignment", properties.limits.optimalBufferCopyOffsetAlignment },
                { "optimalBufferCopyRowPitchAlignment", properties.limits.optimalBufferCopyRowPitchAlignment },
                { "nonCoherentAtomSize", properties.limits.nonCoherentAtomSize },
            }
        },
    };

    if (vulkanVersionSupported(1, 1)) {
        VkPhysicalDeviceProperties2KHR deviceProps2{};
        deviceProps2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR;
        VkPhysicalDeviceSubgroupProperties extProps{};
        extProps.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES;
        deviceProps2.pNext = &extProps;
        vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
        json["subgroupProperties"] = {
            { "subgroupSize", extProps.subgroupSize },
            { "supportedStages", extProps.supportedStages },
            { "supportedOperations", extProps.supportedOperations },
            { "quadOperationsInAllStages", extProps.quadOperationsInAllStages ? true : false },
        };
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
    uint32_t index = 0;
    for (auto& queueFamily : queueFamilyProperties) {
        VkBool32 supportsPresent = false;
        if ((vulkanContext.surface != VK_NULL_HANDLE) && (vulkanContext.vkGetPhysicalDeviceSurfaceSupportKHR)) {
            vulkanContext.vkGetPhysicalDeviceSurfaceSupportKHR(handle, index, vulkanContext.surface, &supportsPresent);
        }
        jsonArray.push_back(
            {
                { "queueCount", queueFamily.queueCount },
                { "queueFlags", queueFamily.queueFlags },
                { "supportsPresent", (bool)supportsPresent },
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
        index++;
    }
    return jsonArray;
}

nlohmann::json VulkanPhysicalDevice::getSurfaceCapabilities()
{
    nlohmann::json json;

    if (vulkanContext.surface == VK_NULL_HANDLE) {
        return json;
    }

    VkSurfaceCapabilitiesKHR surfaceCapabilities{};
    vkGetPhysicalDeviceSurfaceCapabilitiesKHR(handle, vulkanContext.surface, &surfaceCapabilities);

    json = {
        { "maxImageArrayLayers", surfaceCapabilities.maxImageArrayLayers },
        { "minImageCount", surfaceCapabilities.minImageCount },
        { "maxImageCount", surfaceCapabilities.maxImageCount },
        // Only for compatibility
        { "maxImageExtent",
            {
                { "height", surfaceCapabilities.maxImageExtent.height },
                { "width", surfaceCapabilities.maxImageExtent.width },
            }
        },
        // Only for compatibility
        { "minImageExtent",
            {
                { "height", surfaceCapabilities.minImageExtent.height },
                { "width", surfaceCapabilities.minImageExtent.width },
            }
        },
        { "presentmodes", nlohmann::json::array() },
        { "surfaceExtension", vulkanContext.surfaceExtension },
        { "supportedCompositeAlpha", surfaceCapabilities.supportedCompositeAlpha },
        { "supportedTransforms", surfaceCapabilities.supportedTransforms },
        { "supportedUsageFlags", surfaceCapabilities.supportedUsageFlags },
        { "surfaceformats", nlohmann::json::array() },
        // Only for compatibility
        { "validSurface", true }
    };

    // Present modes
    uint32_t presentModeCount;
    if (vkGetPhysicalDeviceSurfacePresentModesKHR(handle, vulkanContext.surface, &presentModeCount, nullptr) == VK_SUCCESS) {
        std::vector<VkPresentModeKHR> presentModes(presentModeCount);
        if (presentModeCount > 0) {
            vkGetPhysicalDeviceSurfacePresentModesKHR(handle, vulkanContext.surface, &presentModeCount, presentModes.data());
            json["presentmodes"] = presentModes;
        }
    }

    // Surface formats
    uint32_t surfaceFormatCount;
    if (vkGetPhysicalDeviceSurfaceFormatsKHR(handle, vulkanContext.surface, &surfaceFormatCount, nullptr) == VK_SUCCESS) {
        std::vector<VkSurfaceFormatKHR> surfaceFormats(surfaceFormatCount);
        if (surfaceFormatCount > 0) {
            vkGetPhysicalDeviceSurfaceFormatsKHR(handle, vulkanContext.surface, &surfaceFormatCount, surfaceFormats.data());
            auto jsonArray = nlohmann::json::array();
            for (auto& surfaceFormat : surfaceFormats) {
                jsonArray.push_back(
                    {
                        { "colorSpace", surfaceFormat.colorSpace },
                        { "format", surfaceFormat.format },
                    }
                );
            }
            json["surfaceformats"] = jsonArray;
        }
    }

    return json;
}

nlohmann::json VulkanPhysicalDevice::getCore11()
{
    // Core 1.1 features and properties are a bit more complicated than 1.2 and newer
    // Dedicated structures for those have only been introduced in Vulkan 1.2

    nlohmann::json json;

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

    VkPhysicalDeviceFeatures2KHR deviceFeatures2{};
    deviceFeatures2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR;

    VkPhysicalDeviceVulkan11Features coreFeatures11{};
    coreFeatures11.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES;
    deviceFeatures2.pNext = &coreFeatures11;
    vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);

    json["features"] = {
        { "storageBuffer16BitAccess", coreFeatures11.storageBuffer16BitAccess },
        { "uniformAndStorageBuffer16BitAccess", coreFeatures11.uniformAndStorageBuffer16BitAccess },
        { "storagePushConstant16", coreFeatures11.storagePushConstant16 },
        { "storageInputOutput16", coreFeatures11.storageInputOutput16 },
        { "multiview", coreFeatures11.multiview },
        { "multiviewGeometryShader", coreFeatures11.multiviewGeometryShader },
        { "multiviewTessellationShader", coreFeatures11.multiviewTessellationShader },
        { "variablePointersStorageBuffer", coreFeatures11.variablePointersStorageBuffer },
        { "variablePointers", coreFeatures11.variablePointers },
        { "protectedMemory", coreFeatures11.protectedMemory },
        { "samplerYcbcrConversion", coreFeatures11.samplerYcbcrConversion },
        { "shaderDrawParameters", coreFeatures11.shaderDrawParameters },
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
