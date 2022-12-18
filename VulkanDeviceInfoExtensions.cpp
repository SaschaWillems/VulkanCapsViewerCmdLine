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

#include "VulkanDeviceInfoExtensions.h"

bool VulkanDeviceInfoExtensions::extensionSupported(const char* extensionName)
{
    for (auto& ext : extensions) {
        if (strcmp(ext.extensionName, extensionName) == 0) {
            return true;
        }
    }
    return false;
}

VkPhysicalDeviceProperties2 VulkanDeviceInfoExtensions::initDeviceProperties2(void * pNext) {
    VkPhysicalDeviceProperties2 props2{};
    props2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR;
    props2.pNext = pNext;
    return props2;
}

void VulkanDeviceInfoExtensions::pushProperty2(const char* extension, nlohmann::json value) {
    properties2.push_back(Property2(value, extension));
}

void VulkanDeviceInfoExtensions::readPhysicalProperties_AMD() {
	if (extensionSupported("VK_AMD_shader_core_properties")) {
		const char* extension("VK_AMD_shader_core_properties");
		VkPhysicalDeviceShaderCorePropertiesAMD extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_AMD_shader_core_properties" }, { "name", "shaderEngineCount" }, { "value", extProps.shaderEngineCount } });
		pushProperty2(extension, { { "extension", "VK_AMD_shader_core_properties" }, { "name", "shaderArraysPerEngineCount" }, { "value", extProps.shaderArraysPerEngineCount } });
		pushProperty2(extension, { { "extension", "VK_AMD_shader_core_properties" }, { "name", "computeUnitsPerShaderArray" }, { "value", extProps.computeUnitsPerShaderArray } });
		pushProperty2(extension, { { "extension", "VK_AMD_shader_core_properties" }, { "name", "simdPerComputeUnit" }, { "value", extProps.simdPerComputeUnit } });
		pushProperty2(extension, { { "extension", "VK_AMD_shader_core_properties" }, { "name", "wavefrontsPerSimd" }, { "value", extProps.wavefrontsPerSimd } });
		pushProperty2(extension, { { "extension", "VK_AMD_shader_core_properties" }, { "name", "wavefrontSize" }, { "value", extProps.wavefrontSize } });
		pushProperty2(extension, { { "extension", "VK_AMD_shader_core_properties" }, { "name", "sgprsPerSimd" }, { "value", extProps.sgprsPerSimd } });
		pushProperty2(extension, { { "extension", "VK_AMD_shader_core_properties" }, { "name", "minSgprAllocation" }, { "value", extProps.minSgprAllocation } });
		pushProperty2(extension, { { "extension", "VK_AMD_shader_core_properties" }, { "name", "maxSgprAllocation" }, { "value", extProps.maxSgprAllocation } });
		pushProperty2(extension, { { "extension", "VK_AMD_shader_core_properties" }, { "name", "sgprAllocationGranularity" }, { "value", extProps.sgprAllocationGranularity } });
		pushProperty2(extension, { { "extension", "VK_AMD_shader_core_properties" }, { "name", "vgprsPerSimd" }, { "value", extProps.vgprsPerSimd } });
		pushProperty2(extension, { { "extension", "VK_AMD_shader_core_properties" }, { "name", "minVgprAllocation" }, { "value", extProps.minVgprAllocation } });
		pushProperty2(extension, { { "extension", "VK_AMD_shader_core_properties" }, { "name", "maxVgprAllocation" }, { "value", extProps.maxVgprAllocation } });
		pushProperty2(extension, { { "extension", "VK_AMD_shader_core_properties" }, { "name", "vgprAllocationGranularity" }, { "value", extProps.vgprAllocationGranularity } });
	}
	if (extensionSupported("VK_AMD_shader_core_properties2")) {
		const char* extension("VK_AMD_shader_core_properties2");
		VkPhysicalDeviceShaderCoreProperties2AMD extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_AMD_shader_core_properties2" }, { "name", "shaderCoreFeatures" }, { "value", extProps.shaderCoreFeatures } });
		pushProperty2(extension, { { "extension", "VK_AMD_shader_core_properties2" }, { "name", "activeComputeUnitCount" }, { "value", extProps.activeComputeUnitCount } });
	}
}
void VulkanDeviceInfoExtensions::readPhysicalProperties_ARM() {
	if (extensionSupported("VK_ARM_shader_core_builtins")) {
		const char* extension("VK_ARM_shader_core_builtins");
		VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_PROPERTIES_ARM };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_ARM_shader_core_builtins" }, { "name", "shaderCoreMask" }, { "value", extProps.shaderCoreMask } });
		pushProperty2(extension, { { "extension", "VK_ARM_shader_core_builtins" }, { "name", "shaderCoreCount" }, { "value", extProps.shaderCoreCount } });
		pushProperty2(extension, { { "extension", "VK_ARM_shader_core_builtins" }, { "name", "shaderWarpsPerCore" }, { "value", extProps.shaderWarpsPerCore } });
	}
}
void VulkanDeviceInfoExtensions::readPhysicalProperties_EXT() {
	if (extensionSupported("VK_EXT_transform_feedback")) {
		const char* extension("VK_EXT_transform_feedback");
		VkPhysicalDeviceTransformFeedbackPropertiesEXT extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_transform_feedback" }, { "name", "maxTransformFeedbackStreams" }, { "value", extProps.maxTransformFeedbackStreams } });
		pushProperty2(extension, { { "extension", "VK_EXT_transform_feedback" }, { "name", "maxTransformFeedbackBuffers" }, { "value", extProps.maxTransformFeedbackBuffers } });
		pushProperty2(extension, { { "extension", "VK_EXT_transform_feedback" }, { "name", "maxTransformFeedbackBufferSize" }, { "value", extProps.maxTransformFeedbackBufferSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_transform_feedback" }, { "name", "maxTransformFeedbackStreamDataSize" }, { "value", extProps.maxTransformFeedbackStreamDataSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_transform_feedback" }, { "name", "maxTransformFeedbackBufferDataSize" }, { "value", extProps.maxTransformFeedbackBufferDataSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_transform_feedback" }, { "name", "maxTransformFeedbackBufferDataStride" }, { "value", extProps.maxTransformFeedbackBufferDataStride } });
		pushProperty2(extension, { { "extension", "VK_EXT_transform_feedback" }, { "name", "transformFeedbackQueries" }, { "value", extProps.transformFeedbackQueries } });
		pushProperty2(extension, { { "extension", "VK_EXT_transform_feedback" }, { "name", "transformFeedbackStreamsLinesTriangles" }, { "value", extProps.transformFeedbackStreamsLinesTriangles } });
		pushProperty2(extension, { { "extension", "VK_EXT_transform_feedback" }, { "name", "transformFeedbackRasterizationStreamSelect" }, { "value", extProps.transformFeedbackRasterizationStreamSelect } });
		pushProperty2(extension, { { "extension", "VK_EXT_transform_feedback" }, { "name", "transformFeedbackDraw" }, { "value", extProps.transformFeedbackDraw } });
	}
	if (extensionSupported("VK_EXT_pipeline_robustness")) {
		const char* extension("VK_EXT_pipeline_robustness");
		VkPhysicalDevicePipelineRobustnessPropertiesEXT extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_PROPERTIES_EXT };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_pipeline_robustness" }, { "name", "defaultRobustnessStorageBuffers" }, { "value", extProps.defaultRobustnessStorageBuffers } });
		pushProperty2(extension, { { "extension", "VK_EXT_pipeline_robustness" }, { "name", "defaultRobustnessUniformBuffers" }, { "value", extProps.defaultRobustnessUniformBuffers } });
		pushProperty2(extension, { { "extension", "VK_EXT_pipeline_robustness" }, { "name", "defaultRobustnessVertexInputs" }, { "value", extProps.defaultRobustnessVertexInputs } });
		pushProperty2(extension, { { "extension", "VK_EXT_pipeline_robustness" }, { "name", "defaultRobustnessImages" }, { "value", extProps.defaultRobustnessImages } });
	}
	if (extensionSupported("VK_EXT_discard_rectangles")) {
		const char* extension("VK_EXT_discard_rectangles");
		VkPhysicalDeviceDiscardRectanglePropertiesEXT extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_discard_rectangles" }, { "name", "maxDiscardRectangles" }, { "value", extProps.maxDiscardRectangles } });
	}
	if (extensionSupported("VK_EXT_conservative_rasterization")) {
		const char* extension("VK_EXT_conservative_rasterization");
		VkPhysicalDeviceConservativeRasterizationPropertiesEXT extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_conservative_rasterization" }, { "name", "primitiveOverestimationSize" }, { "value", extProps.primitiveOverestimationSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_conservative_rasterization" }, { "name", "maxExtraPrimitiveOverestimationSize" }, { "value", extProps.maxExtraPrimitiveOverestimationSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_conservative_rasterization" }, { "name", "extraPrimitiveOverestimationSizeGranularity" }, { "value", extProps.extraPrimitiveOverestimationSizeGranularity } });
		pushProperty2(extension, { { "extension", "VK_EXT_conservative_rasterization" }, { "name", "primitiveUnderestimation" }, { "value", extProps.primitiveUnderestimation } });
		pushProperty2(extension, { { "extension", "VK_EXT_conservative_rasterization" }, { "name", "conservativePointAndLineRasterization" }, { "value", extProps.conservativePointAndLineRasterization } });
		pushProperty2(extension, { { "extension", "VK_EXT_conservative_rasterization" }, { "name", "degenerateTrianglesRasterized" }, { "value", extProps.degenerateTrianglesRasterized } });
		pushProperty2(extension, { { "extension", "VK_EXT_conservative_rasterization" }, { "name", "degenerateLinesRasterized" }, { "value", extProps.degenerateLinesRasterized } });
		pushProperty2(extension, { { "extension", "VK_EXT_conservative_rasterization" }, { "name", "fullyCoveredFragmentShaderInputVariable" }, { "value", extProps.fullyCoveredFragmentShaderInputVariable } });
		pushProperty2(extension, { { "extension", "VK_EXT_conservative_rasterization" }, { "name", "conservativeRasterizationPostDepthCoverage" }, { "value", extProps.conservativeRasterizationPostDepthCoverage } });
	}
	if (extensionSupported("VK_EXT_sampler_filter_minmax")) {
		const char* extension("VK_EXT_sampler_filter_minmax");
		VkPhysicalDeviceSamplerFilterMinmaxProperties extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_sampler_filter_minmax" }, { "name", "filterMinmaxSingleComponentFormats" }, { "value", extProps.filterMinmaxSingleComponentFormats } });
		pushProperty2(extension, { { "extension", "VK_EXT_sampler_filter_minmax" }, { "name", "filterMinmaxImageComponentMapping" }, { "value", extProps.filterMinmaxImageComponentMapping } });
	}
	if (extensionSupported("VK_EXT_inline_uniform_block")) {
		const char* extension("VK_EXT_inline_uniform_block");
		VkPhysicalDeviceInlineUniformBlockProperties extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_inline_uniform_block" }, { "name", "maxInlineUniformBlockSize" }, { "value", extProps.maxInlineUniformBlockSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_inline_uniform_block" }, { "name", "maxPerStageDescriptorInlineUniformBlocks" }, { "value", extProps.maxPerStageDescriptorInlineUniformBlocks } });
		pushProperty2(extension, { { "extension", "VK_EXT_inline_uniform_block" }, { "name", "maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks" }, { "value", extProps.maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks } });
		pushProperty2(extension, { { "extension", "VK_EXT_inline_uniform_block" }, { "name", "maxDescriptorSetInlineUniformBlocks" }, { "value", extProps.maxDescriptorSetInlineUniformBlocks } });
		pushProperty2(extension, { { "extension", "VK_EXT_inline_uniform_block" }, { "name", "maxDescriptorSetUpdateAfterBindInlineUniformBlocks" }, { "value", extProps.maxDescriptorSetUpdateAfterBindInlineUniformBlocks } });
	}
	if (extensionSupported("VK_EXT_sample_locations")) {
		const char* extension("VK_EXT_sample_locations");
		VkPhysicalDeviceSampleLocationsPropertiesEXT extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_sample_locations" }, { "name", "sampleLocationSampleCounts" }, { "value", extProps.sampleLocationSampleCounts } });
		pushProperty2(extension, { { "extension", "VK_EXT_sample_locations" }, { "name", "maxSampleLocationGridSize" }, { "value", { extProps.maxSampleLocationGridSize.width, extProps.maxSampleLocationGridSize.height } } });
		pushProperty2(extension, { { "extension", "VK_EXT_sample_locations" }, { "name", "sampleLocationCoordinateRange" }, { "value", extProps.sampleLocationCoordinateRange } });
		pushProperty2(extension, { { "extension", "VK_EXT_sample_locations" }, { "name", "sampleLocationSubPixelBits" }, { "value", extProps.sampleLocationSubPixelBits } });
		pushProperty2(extension, { { "extension", "VK_EXT_sample_locations" }, { "name", "variableSampleLocations" }, { "value", extProps.variableSampleLocations } });
	}
	if (extensionSupported("VK_EXT_blend_operation_advanced")) {
		const char* extension("VK_EXT_blend_operation_advanced");
		VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_blend_operation_advanced" }, { "name", "advancedBlendMaxColorAttachments" }, { "value", extProps.advancedBlendMaxColorAttachments } });
		pushProperty2(extension, { { "extension", "VK_EXT_blend_operation_advanced" }, { "name", "advancedBlendIndependentBlend" }, { "value", extProps.advancedBlendIndependentBlend } });
		pushProperty2(extension, { { "extension", "VK_EXT_blend_operation_advanced" }, { "name", "advancedBlendNonPremultipliedSrcColor" }, { "value", extProps.advancedBlendNonPremultipliedSrcColor } });
		pushProperty2(extension, { { "extension", "VK_EXT_blend_operation_advanced" }, { "name", "advancedBlendNonPremultipliedDstColor" }, { "value", extProps.advancedBlendNonPremultipliedDstColor } });
		pushProperty2(extension, { { "extension", "VK_EXT_blend_operation_advanced" }, { "name", "advancedBlendCorrelatedOverlap" }, { "value", extProps.advancedBlendCorrelatedOverlap } });
		pushProperty2(extension, { { "extension", "VK_EXT_blend_operation_advanced" }, { "name", "advancedBlendAllOperations" }, { "value", extProps.advancedBlendAllOperations } });
	}
	if (extensionSupported("VK_EXT_descriptor_indexing")) {
		const char* extension("VK_EXT_descriptor_indexing");
		VkPhysicalDeviceDescriptorIndexingProperties extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_indexing" }, { "name", "maxUpdateAfterBindDescriptorsInAllPools" }, { "value", extProps.maxUpdateAfterBindDescriptorsInAllPools } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_indexing" }, { "name", "shaderUniformBufferArrayNonUniformIndexingNative" }, { "value", extProps.shaderUniformBufferArrayNonUniformIndexingNative } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_indexing" }, { "name", "shaderSampledImageArrayNonUniformIndexingNative" }, { "value", extProps.shaderSampledImageArrayNonUniformIndexingNative } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_indexing" }, { "name", "shaderStorageBufferArrayNonUniformIndexingNative" }, { "value", extProps.shaderStorageBufferArrayNonUniformIndexingNative } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_indexing" }, { "name", "shaderStorageImageArrayNonUniformIndexingNative" }, { "value", extProps.shaderStorageImageArrayNonUniformIndexingNative } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_indexing" }, { "name", "shaderInputAttachmentArrayNonUniformIndexingNative" }, { "value", extProps.shaderInputAttachmentArrayNonUniformIndexingNative } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_indexing" }, { "name", "robustBufferAccessUpdateAfterBind" }, { "value", extProps.robustBufferAccessUpdateAfterBind } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_indexing" }, { "name", "quadDivergentImplicitLod" }, { "value", extProps.quadDivergentImplicitLod } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_indexing" }, { "name", "maxPerStageDescriptorUpdateAfterBindSamplers" }, { "value", extProps.maxPerStageDescriptorUpdateAfterBindSamplers } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_indexing" }, { "name", "maxPerStageDescriptorUpdateAfterBindUniformBuffers" }, { "value", extProps.maxPerStageDescriptorUpdateAfterBindUniformBuffers } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_indexing" }, { "name", "maxPerStageDescriptorUpdateAfterBindStorageBuffers" }, { "value", extProps.maxPerStageDescriptorUpdateAfterBindStorageBuffers } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_indexing" }, { "name", "maxPerStageDescriptorUpdateAfterBindSampledImages" }, { "value", extProps.maxPerStageDescriptorUpdateAfterBindSampledImages } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_indexing" }, { "name", "maxPerStageDescriptorUpdateAfterBindStorageImages" }, { "value", extProps.maxPerStageDescriptorUpdateAfterBindStorageImages } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_indexing" }, { "name", "maxPerStageDescriptorUpdateAfterBindInputAttachments" }, { "value", extProps.maxPerStageDescriptorUpdateAfterBindInputAttachments } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_indexing" }, { "name", "maxPerStageUpdateAfterBindResources" }, { "value", extProps.maxPerStageUpdateAfterBindResources } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_indexing" }, { "name", "maxDescriptorSetUpdateAfterBindSamplers" }, { "value", extProps.maxDescriptorSetUpdateAfterBindSamplers } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_indexing" }, { "name", "maxDescriptorSetUpdateAfterBindUniformBuffers" }, { "value", extProps.maxDescriptorSetUpdateAfterBindUniformBuffers } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_indexing" }, { "name", "maxDescriptorSetUpdateAfterBindUniformBuffersDynamic" }, { "value", extProps.maxDescriptorSetUpdateAfterBindUniformBuffersDynamic } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_indexing" }, { "name", "maxDescriptorSetUpdateAfterBindStorageBuffers" }, { "value", extProps.maxDescriptorSetUpdateAfterBindStorageBuffers } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_indexing" }, { "name", "maxDescriptorSetUpdateAfterBindStorageBuffersDynamic" }, { "value", extProps.maxDescriptorSetUpdateAfterBindStorageBuffersDynamic } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_indexing" }, { "name", "maxDescriptorSetUpdateAfterBindSampledImages" }, { "value", extProps.maxDescriptorSetUpdateAfterBindSampledImages } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_indexing" }, { "name", "maxDescriptorSetUpdateAfterBindStorageImages" }, { "value", extProps.maxDescriptorSetUpdateAfterBindStorageImages } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_indexing" }, { "name", "maxDescriptorSetUpdateAfterBindInputAttachments" }, { "value", extProps.maxDescriptorSetUpdateAfterBindInputAttachments } });
	}
	if (extensionSupported("VK_EXT_external_memory_host")) {
		const char* extension("VK_EXT_external_memory_host");
		VkPhysicalDeviceExternalMemoryHostPropertiesEXT extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_external_memory_host" }, { "name", "minImportedHostPointerAlignment" }, { "value", extProps.minImportedHostPointerAlignment } });
	}
	if (extensionSupported("VK_EXT_vertex_attribute_divisor")) {
		const char* extension("VK_EXT_vertex_attribute_divisor");
		VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_vertex_attribute_divisor" }, { "name", "maxVertexAttribDivisor" }, { "value", extProps.maxVertexAttribDivisor } });
	}
	if (extensionSupported("VK_EXT_pci_bus_info")) {
		const char* extension("VK_EXT_pci_bus_info");
		VkPhysicalDevicePCIBusInfoPropertiesEXT extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_pci_bus_info" }, { "name", "pciDomain" }, { "value", extProps.pciDomain } });
		pushProperty2(extension, { { "extension", "VK_EXT_pci_bus_info" }, { "name", "pciBus" }, { "value", extProps.pciBus } });
		pushProperty2(extension, { { "extension", "VK_EXT_pci_bus_info" }, { "name", "pciDevice" }, { "value", extProps.pciDevice } });
		pushProperty2(extension, { { "extension", "VK_EXT_pci_bus_info" }, { "name", "pciFunction" }, { "value", extProps.pciFunction } });
	}
	if (extensionSupported("VK_EXT_fragment_density_map")) {
		const char* extension("VK_EXT_fragment_density_map");
		VkPhysicalDeviceFragmentDensityMapPropertiesEXT extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_fragment_density_map" }, { "name", "minFragmentDensityTexelSize" }, { "value", { extProps.minFragmentDensityTexelSize.width, extProps.minFragmentDensityTexelSize.height } } });
		pushProperty2(extension, { { "extension", "VK_EXT_fragment_density_map" }, { "name", "maxFragmentDensityTexelSize" }, { "value", { extProps.maxFragmentDensityTexelSize.width, extProps.maxFragmentDensityTexelSize.height } } });
		pushProperty2(extension, { { "extension", "VK_EXT_fragment_density_map" }, { "name", "fragmentDensityInvocations" }, { "value", extProps.fragmentDensityInvocations } });
	}
	if (extensionSupported("VK_EXT_subgroup_size_control")) {
		const char* extension("VK_EXT_subgroup_size_control");
		VkPhysicalDeviceSubgroupSizeControlProperties extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_subgroup_size_control" }, { "name", "minSubgroupSize" }, { "value", extProps.minSubgroupSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_subgroup_size_control" }, { "name", "maxSubgroupSize" }, { "value", extProps.maxSubgroupSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_subgroup_size_control" }, { "name", "maxComputeWorkgroupSubgroups" }, { "value", extProps.maxComputeWorkgroupSubgroups } });
		pushProperty2(extension, { { "extension", "VK_EXT_subgroup_size_control" }, { "name", "requiredSubgroupSizeStages" }, { "value", extProps.requiredSubgroupSizeStages } });
	}
	if (extensionSupported("VK_EXT_provoking_vertex")) {
		const char* extension("VK_EXT_provoking_vertex");
		VkPhysicalDeviceProvokingVertexPropertiesEXT extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_PROPERTIES_EXT };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_provoking_vertex" }, { "name", "provokingVertexModePerPipeline" }, { "value", extProps.provokingVertexModePerPipeline } });
		pushProperty2(extension, { { "extension", "VK_EXT_provoking_vertex" }, { "name", "transformFeedbackPreservesTriangleFanProvokingVertex" }, { "value", extProps.transformFeedbackPreservesTriangleFanProvokingVertex } });
	}
	if (extensionSupported("VK_EXT_line_rasterization")) {
		const char* extension("VK_EXT_line_rasterization");
		VkPhysicalDeviceLineRasterizationPropertiesEXT extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES_EXT };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_line_rasterization" }, { "name", "lineSubPixelPrecisionBits" }, { "value", extProps.lineSubPixelPrecisionBits } });
	}
	if (extensionSupported("VK_EXT_texel_buffer_alignment")) {
		const char* extension("VK_EXT_texel_buffer_alignment");
		VkPhysicalDeviceTexelBufferAlignmentProperties extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_texel_buffer_alignment" }, { "name", "storageTexelBufferOffsetAlignmentBytes" }, { "value", extProps.storageTexelBufferOffsetAlignmentBytes } });
		pushProperty2(extension, { { "extension", "VK_EXT_texel_buffer_alignment" }, { "name", "storageTexelBufferOffsetSingleTexelAlignment" }, { "value", extProps.storageTexelBufferOffsetSingleTexelAlignment } });
		pushProperty2(extension, { { "extension", "VK_EXT_texel_buffer_alignment" }, { "name", "uniformTexelBufferOffsetAlignmentBytes" }, { "value", extProps.uniformTexelBufferOffsetAlignmentBytes } });
		pushProperty2(extension, { { "extension", "VK_EXT_texel_buffer_alignment" }, { "name", "uniformTexelBufferOffsetSingleTexelAlignment" }, { "value", extProps.uniformTexelBufferOffsetSingleTexelAlignment } });
	}
	if (extensionSupported("VK_EXT_robustness2")) {
		const char* extension("VK_EXT_robustness2");
		VkPhysicalDeviceRobustness2PropertiesEXT extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_EXT };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_robustness2" }, { "name", "robustStorageBufferAccessSizeAlignment" }, { "value", extProps.robustStorageBufferAccessSizeAlignment } });
		pushProperty2(extension, { { "extension", "VK_EXT_robustness2" }, { "name", "robustUniformBufferAccessSizeAlignment" }, { "value", extProps.robustUniformBufferAccessSizeAlignment } });
	}
	if (extensionSupported("VK_EXT_custom_border_color")) {
		const char* extension("VK_EXT_custom_border_color");
		VkPhysicalDeviceCustomBorderColorPropertiesEXT extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_custom_border_color" }, { "name", "maxCustomBorderColorSamplers" }, { "value", extProps.maxCustomBorderColorSamplers } });
	}
	if (extensionSupported("VK_EXT_descriptor_buffer")) {
		const char* extension("VK_EXT_descriptor_buffer");
		VkPhysicalDeviceDescriptorBufferPropertiesEXT extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_PROPERTIES_EXT };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "combinedImageSamplerDescriptorSingleArray" }, { "value", extProps.combinedImageSamplerDescriptorSingleArray } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "bufferlessPushDescriptors" }, { "value", extProps.bufferlessPushDescriptors } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "allowSamplerImageViewPostSubmitCreation" }, { "value", extProps.allowSamplerImageViewPostSubmitCreation } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "descriptorBufferOffsetAlignment" }, { "value", extProps.descriptorBufferOffsetAlignment } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "maxDescriptorBufferBindings" }, { "value", extProps.maxDescriptorBufferBindings } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "maxResourceDescriptorBufferBindings" }, { "value", extProps.maxResourceDescriptorBufferBindings } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "maxSamplerDescriptorBufferBindings" }, { "value", extProps.maxSamplerDescriptorBufferBindings } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "maxEmbeddedImmutableSamplerBindings" }, { "value", extProps.maxEmbeddedImmutableSamplerBindings } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "maxEmbeddedImmutableSamplers" }, { "value", extProps.maxEmbeddedImmutableSamplers } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "bufferCaptureReplayDescriptorDataSize" }, { "value", extProps.bufferCaptureReplayDescriptorDataSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "imageCaptureReplayDescriptorDataSize" }, { "value", extProps.imageCaptureReplayDescriptorDataSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "imageViewCaptureReplayDescriptorDataSize" }, { "value", extProps.imageViewCaptureReplayDescriptorDataSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "samplerCaptureReplayDescriptorDataSize" }, { "value", extProps.samplerCaptureReplayDescriptorDataSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "accelerationStructureCaptureReplayDescriptorDataSize" }, { "value", extProps.accelerationStructureCaptureReplayDescriptorDataSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "samplerDescriptorSize" }, { "value", extProps.samplerDescriptorSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "combinedImageSamplerDescriptorSize" }, { "value", extProps.combinedImageSamplerDescriptorSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "sampledImageDescriptorSize" }, { "value", extProps.sampledImageDescriptorSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "storageImageDescriptorSize" }, { "value", extProps.storageImageDescriptorSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "uniformTexelBufferDescriptorSize" }, { "value", extProps.uniformTexelBufferDescriptorSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "robustUniformTexelBufferDescriptorSize" }, { "value", extProps.robustUniformTexelBufferDescriptorSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "storageTexelBufferDescriptorSize" }, { "value", extProps.storageTexelBufferDescriptorSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "robustStorageTexelBufferDescriptorSize" }, { "value", extProps.robustStorageTexelBufferDescriptorSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "uniformBufferDescriptorSize" }, { "value", extProps.uniformBufferDescriptorSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "robustUniformBufferDescriptorSize" }, { "value", extProps.robustUniformBufferDescriptorSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "storageBufferDescriptorSize" }, { "value", extProps.storageBufferDescriptorSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "robustStorageBufferDescriptorSize" }, { "value", extProps.robustStorageBufferDescriptorSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "inputAttachmentDescriptorSize" }, { "value", extProps.inputAttachmentDescriptorSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "accelerationStructureDescriptorSize" }, { "value", extProps.accelerationStructureDescriptorSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "maxSamplerDescriptorBufferRange" }, { "value", extProps.maxSamplerDescriptorBufferRange } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "maxResourceDescriptorBufferRange" }, { "value", extProps.maxResourceDescriptorBufferRange } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "samplerDescriptorBufferAddressSpaceSize" }, { "value", extProps.samplerDescriptorBufferAddressSpaceSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "resourceDescriptorBufferAddressSpaceSize" }, { "value", extProps.resourceDescriptorBufferAddressSpaceSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "descriptorBufferAddressSpaceSize" }, { "value", extProps.descriptorBufferAddressSpaceSize } });
	}
	if (extensionSupported("VK_EXT_graphics_pipeline_library")) {
		const char* extension("VK_EXT_graphics_pipeline_library");
		VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_PROPERTIES_EXT };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_graphics_pipeline_library" }, { "name", "graphicsPipelineLibraryFastLinking" }, { "value", extProps.graphicsPipelineLibraryFastLinking } });
		pushProperty2(extension, { { "extension", "VK_EXT_graphics_pipeline_library" }, { "name", "graphicsPipelineLibraryIndependentInterpolationDecoration" }, { "value", extProps.graphicsPipelineLibraryIndependentInterpolationDecoration } });
	}
	if (extensionSupported("VK_EXT_mesh_shader")) {
		const char* extension("VK_EXT_mesh_shader");
		VkPhysicalDeviceMeshShaderPropertiesEXT extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_EXT };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "maxTaskWorkGroupTotalCount" }, { "value", extProps.maxTaskWorkGroupTotalCount } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "maxTaskWorkGroupCount" }, { "value", extProps.maxTaskWorkGroupCount } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "maxTaskWorkGroupInvocations" }, { "value", extProps.maxTaskWorkGroupInvocations } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "maxTaskWorkGroupSize" }, { "value", extProps.maxTaskWorkGroupSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "maxTaskPayloadSize" }, { "value", extProps.maxTaskPayloadSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "maxTaskSharedMemorySize" }, { "value", extProps.maxTaskSharedMemorySize } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "maxTaskPayloadAndSharedMemorySize" }, { "value", extProps.maxTaskPayloadAndSharedMemorySize } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "maxMeshWorkGroupTotalCount" }, { "value", extProps.maxMeshWorkGroupTotalCount } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "maxMeshWorkGroupCount" }, { "value", extProps.maxMeshWorkGroupCount } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "maxMeshWorkGroupInvocations" }, { "value", extProps.maxMeshWorkGroupInvocations } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "maxMeshWorkGroupSize" }, { "value", extProps.maxMeshWorkGroupSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "maxMeshSharedMemorySize" }, { "value", extProps.maxMeshSharedMemorySize } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "maxMeshPayloadAndSharedMemorySize" }, { "value", extProps.maxMeshPayloadAndSharedMemorySize } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "maxMeshOutputMemorySize" }, { "value", extProps.maxMeshOutputMemorySize } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "maxMeshPayloadAndOutputMemorySize" }, { "value", extProps.maxMeshPayloadAndOutputMemorySize } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "maxMeshOutputComponents" }, { "value", extProps.maxMeshOutputComponents } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "maxMeshOutputVertices" }, { "value", extProps.maxMeshOutputVertices } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "maxMeshOutputPrimitives" }, { "value", extProps.maxMeshOutputPrimitives } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "maxMeshOutputLayers" }, { "value", extProps.maxMeshOutputLayers } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "maxMeshMultiviewViewCount" }, { "value", extProps.maxMeshMultiviewViewCount } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "meshOutputPerVertexGranularity" }, { "value", extProps.meshOutputPerVertexGranularity } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "meshOutputPerPrimitiveGranularity" }, { "value", extProps.meshOutputPerPrimitiveGranularity } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "maxPreferredTaskWorkGroupInvocations" }, { "value", extProps.maxPreferredTaskWorkGroupInvocations } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "maxPreferredMeshWorkGroupInvocations" }, { "value", extProps.maxPreferredMeshWorkGroupInvocations } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "prefersLocalInvocationVertexOutput" }, { "value", extProps.prefersLocalInvocationVertexOutput } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "prefersLocalInvocationPrimitiveOutput" }, { "value", extProps.prefersLocalInvocationPrimitiveOutput } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "prefersCompactVertexOutput" }, { "value", extProps.prefersCompactVertexOutput } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "prefersCompactPrimitiveOutput" }, { "value", extProps.prefersCompactPrimitiveOutput } });
	}
	if (extensionSupported("VK_EXT_fragment_density_map2")) {
		const char* extension("VK_EXT_fragment_density_map2");
		VkPhysicalDeviceFragmentDensityMap2PropertiesEXT extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_PROPERTIES_EXT };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_fragment_density_map2" }, { "name", "subsampledLoads" }, { "value", extProps.subsampledLoads } });
		pushProperty2(extension, { { "extension", "VK_EXT_fragment_density_map2" }, { "name", "subsampledCoarseReconstructionEarlyAccess" }, { "value", extProps.subsampledCoarseReconstructionEarlyAccess } });
		pushProperty2(extension, { { "extension", "VK_EXT_fragment_density_map2" }, { "name", "maxSubsampledArrayLayers" }, { "value", extProps.maxSubsampledArrayLayers } });
		pushProperty2(extension, { { "extension", "VK_EXT_fragment_density_map2" }, { "name", "maxDescriptorSetSubsampledSamplers" }, { "value", extProps.maxDescriptorSetSubsampledSamplers } });
	}
	if (extensionSupported("VK_EXT_physical_device_drm")) {
		const char* extension("VK_EXT_physical_device_drm");
		VkPhysicalDeviceDrmPropertiesEXT extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRM_PROPERTIES_EXT };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_physical_device_drm" }, { "name", "hasPrimary" }, { "value", extProps.hasPrimary } });
		pushProperty2(extension, { { "extension", "VK_EXT_physical_device_drm" }, { "name", "hasRender" }, { "value", extProps.hasRender } });
		pushProperty2(extension, { { "extension", "VK_EXT_physical_device_drm" }, { "name", "primaryMajor" }, { "value", extProps.primaryMajor } });
		pushProperty2(extension, { { "extension", "VK_EXT_physical_device_drm" }, { "name", "primaryMinor" }, { "value", extProps.primaryMinor } });
		pushProperty2(extension, { { "extension", "VK_EXT_physical_device_drm" }, { "name", "renderMajor" }, { "value", extProps.renderMajor } });
		pushProperty2(extension, { { "extension", "VK_EXT_physical_device_drm" }, { "name", "renderMinor" }, { "value", extProps.renderMinor } });
	}
	if (extensionSupported("VK_EXT_multi_draw")) {
		const char* extension("VK_EXT_multi_draw");
		VkPhysicalDeviceMultiDrawPropertiesEXT extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_PROPERTIES_EXT };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_multi_draw" }, { "name", "maxMultiDrawCount" }, { "value", extProps.maxMultiDrawCount } });
	}
	if (extensionSupported("VK_EXT_opacity_micromap")) {
		const char* extension("VK_EXT_opacity_micromap");
		VkPhysicalDeviceOpacityMicromapPropertiesEXT extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_PROPERTIES_EXT };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_opacity_micromap" }, { "name", "maxOpacity2StateSubdivisionLevel" }, { "value", extProps.maxOpacity2StateSubdivisionLevel } });
		pushProperty2(extension, { { "extension", "VK_EXT_opacity_micromap" }, { "name", "maxOpacity4StateSubdivisionLevel" }, { "value", extProps.maxOpacity4StateSubdivisionLevel } });
	}
	if (extensionSupported("VK_EXT_extended_dynamic_state3")) {
		const char* extension("VK_EXT_extended_dynamic_state3");
		VkPhysicalDeviceExtendedDynamicState3PropertiesEXT extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_PROPERTIES_EXT };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_extended_dynamic_state3" }, { "name", "dynamicPrimitiveTopologyUnrestricted" }, { "value", extProps.dynamicPrimitiveTopologyUnrestricted } });
	}
	if (extensionSupported("VK_EXT_shader_module_identifier")) {
		const char* extension("VK_EXT_shader_module_identifier");
		VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_PROPERTIES_EXT };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_shader_module_identifier" }, { "name", "shaderModuleIdentifierAlgorithmUUID" }, { "value", extProps.shaderModuleIdentifierAlgorithmUUID } });
	}
}
void VulkanDeviceInfoExtensions::readPhysicalProperties_HUAWEI() {
	if (extensionSupported("VK_HUAWEI_subpass_shading")) {
		const char* extension("VK_HUAWEI_subpass_shading");
		VkPhysicalDeviceSubpassShadingPropertiesHUAWEI extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_SHADING_PROPERTIES_HUAWEI };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_HUAWEI_subpass_shading" }, { "name", "maxSubpassShadingWorkgroupSizeAspectRatio" }, { "value", extProps.maxSubpassShadingWorkgroupSizeAspectRatio } });
	}
}
void VulkanDeviceInfoExtensions::readPhysicalProperties_KHR() {
	if (extensionSupported("VK_KHR_multiview")) {
		const char* extension("VK_KHR_multiview");
		VkPhysicalDeviceMultiviewProperties extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_KHR_multiview" }, { "name", "maxMultiviewViewCount" }, { "value", extProps.maxMultiviewViewCount } });
		pushProperty2(extension, { { "extension", "VK_KHR_multiview" }, { "name", "maxMultiviewInstanceIndex" }, { "value", extProps.maxMultiviewInstanceIndex } });
	}
	if (extensionSupported("VK_KHR_external_memory_capabilities")) {
		const char* extension("VK_KHR_external_memory_capabilities");
		VkPhysicalDeviceIDProperties extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_KHR_external_memory_capabilities" }, { "name", "deviceUUID" }, { "value", extProps.deviceUUID } });
		pushProperty2(extension, { { "extension", "VK_KHR_external_memory_capabilities" }, { "name", "driverUUID" }, { "value", extProps.driverUUID } });
		pushProperty2(extension, { { "extension", "VK_KHR_external_memory_capabilities" }, { "name", "deviceLUID" }, { "value", extProps.deviceLUID } });
		pushProperty2(extension, { { "extension", "VK_KHR_external_memory_capabilities" }, { "name", "deviceNodeMask" }, { "value", extProps.deviceNodeMask } });
		pushProperty2(extension, { { "extension", "VK_KHR_external_memory_capabilities" }, { "name", "deviceLUIDValid" }, { "value", extProps.deviceLUIDValid } });
	}
	if (extensionSupported("VK_KHR_external_semaphore_capabilities")) {
		const char* extension("VK_KHR_external_semaphore_capabilities");
		VkPhysicalDeviceIDProperties extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_KHR_external_semaphore_capabilities" }, { "name", "deviceUUID" }, { "value", extProps.deviceUUID } });
		pushProperty2(extension, { { "extension", "VK_KHR_external_semaphore_capabilities" }, { "name", "driverUUID" }, { "value", extProps.driverUUID } });
		pushProperty2(extension, { { "extension", "VK_KHR_external_semaphore_capabilities" }, { "name", "deviceLUID" }, { "value", extProps.deviceLUID } });
		pushProperty2(extension, { { "extension", "VK_KHR_external_semaphore_capabilities" }, { "name", "deviceNodeMask" }, { "value", extProps.deviceNodeMask } });
		pushProperty2(extension, { { "extension", "VK_KHR_external_semaphore_capabilities" }, { "name", "deviceLUIDValid" }, { "value", extProps.deviceLUIDValid } });
	}
	if (extensionSupported("VK_KHR_push_descriptor")) {
		const char* extension("VK_KHR_push_descriptor");
		VkPhysicalDevicePushDescriptorPropertiesKHR extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_KHR_push_descriptor" }, { "name", "maxPushDescriptors" }, { "value", extProps.maxPushDescriptors } });
	}
	if (extensionSupported("VK_KHR_external_fence_capabilities")) {
		const char* extension("VK_KHR_external_fence_capabilities");
		VkPhysicalDeviceIDProperties extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_KHR_external_fence_capabilities" }, { "name", "deviceUUID" }, { "value", extProps.deviceUUID } });
		pushProperty2(extension, { { "extension", "VK_KHR_external_fence_capabilities" }, { "name", "driverUUID" }, { "value", extProps.driverUUID } });
		pushProperty2(extension, { { "extension", "VK_KHR_external_fence_capabilities" }, { "name", "deviceLUID" }, { "value", extProps.deviceLUID } });
		pushProperty2(extension, { { "extension", "VK_KHR_external_fence_capabilities" }, { "name", "deviceNodeMask" }, { "value", extProps.deviceNodeMask } });
		pushProperty2(extension, { { "extension", "VK_KHR_external_fence_capabilities" }, { "name", "deviceLUIDValid" }, { "value", extProps.deviceLUIDValid } });
	}
	if (extensionSupported("VK_KHR_performance_query")) {
		const char* extension("VK_KHR_performance_query");
		VkPhysicalDevicePerformanceQueryPropertiesKHR extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_KHR_performance_query" }, { "name", "allowCommandBufferQueryCopies" }, { "value", extProps.allowCommandBufferQueryCopies } });
	}
	if (extensionSupported("VK_KHR_maintenance2")) {
		const char* extension("VK_KHR_maintenance2");
		VkPhysicalDevicePointClippingProperties extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_KHR_maintenance2" }, { "name", "pointClippingBehavior" }, { "value", extProps.pointClippingBehavior } });
	}
	if (extensionSupported("VK_KHR_acceleration_structure")) {
		const char* extension("VK_KHR_acceleration_structure");
		VkPhysicalDeviceAccelerationStructurePropertiesKHR extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_PROPERTIES_KHR };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_KHR_acceleration_structure" }, { "name", "maxGeometryCount" }, { "value", extProps.maxGeometryCount } });
		pushProperty2(extension, { { "extension", "VK_KHR_acceleration_structure" }, { "name", "maxInstanceCount" }, { "value", extProps.maxInstanceCount } });
		pushProperty2(extension, { { "extension", "VK_KHR_acceleration_structure" }, { "name", "maxPrimitiveCount" }, { "value", extProps.maxPrimitiveCount } });
		pushProperty2(extension, { { "extension", "VK_KHR_acceleration_structure" }, { "name", "maxPerStageDescriptorAccelerationStructures" }, { "value", extProps.maxPerStageDescriptorAccelerationStructures } });
		pushProperty2(extension, { { "extension", "VK_KHR_acceleration_structure" }, { "name", "maxPerStageDescriptorUpdateAfterBindAccelerationStructures" }, { "value", extProps.maxPerStageDescriptorUpdateAfterBindAccelerationStructures } });
		pushProperty2(extension, { { "extension", "VK_KHR_acceleration_structure" }, { "name", "maxDescriptorSetAccelerationStructures" }, { "value", extProps.maxDescriptorSetAccelerationStructures } });
		pushProperty2(extension, { { "extension", "VK_KHR_acceleration_structure" }, { "name", "maxDescriptorSetUpdateAfterBindAccelerationStructures" }, { "value", extProps.maxDescriptorSetUpdateAfterBindAccelerationStructures } });
		pushProperty2(extension, { { "extension", "VK_KHR_acceleration_structure" }, { "name", "minAccelerationStructureScratchOffsetAlignment" }, { "value", extProps.minAccelerationStructureScratchOffsetAlignment } });
	}
	if (extensionSupported("VK_KHR_ray_tracing_pipeline")) {
		const char* extension("VK_KHR_ray_tracing_pipeline");
		VkPhysicalDeviceRayTracingPipelinePropertiesKHR extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_PROPERTIES_KHR };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_KHR_ray_tracing_pipeline" }, { "name", "shaderGroupHandleSize" }, { "value", extProps.shaderGroupHandleSize } });
		pushProperty2(extension, { { "extension", "VK_KHR_ray_tracing_pipeline" }, { "name", "maxRayRecursionDepth" }, { "value", extProps.maxRayRecursionDepth } });
		pushProperty2(extension, { { "extension", "VK_KHR_ray_tracing_pipeline" }, { "name", "maxShaderGroupStride" }, { "value", extProps.maxShaderGroupStride } });
		pushProperty2(extension, { { "extension", "VK_KHR_ray_tracing_pipeline" }, { "name", "shaderGroupBaseAlignment" }, { "value", extProps.shaderGroupBaseAlignment } });
		pushProperty2(extension, { { "extension", "VK_KHR_ray_tracing_pipeline" }, { "name", "shaderGroupHandleCaptureReplaySize" }, { "value", extProps.shaderGroupHandleCaptureReplaySize } });
		pushProperty2(extension, { { "extension", "VK_KHR_ray_tracing_pipeline" }, { "name", "maxRayDispatchInvocationCount" }, { "value", extProps.maxRayDispatchInvocationCount } });
		pushProperty2(extension, { { "extension", "VK_KHR_ray_tracing_pipeline" }, { "name", "shaderGroupHandleAlignment" }, { "value", extProps.shaderGroupHandleAlignment } });
		pushProperty2(extension, { { "extension", "VK_KHR_ray_tracing_pipeline" }, { "name", "maxRayHitAttributeSize" }, { "value", extProps.maxRayHitAttributeSize } });
	}
	if (extensionSupported("VK_KHR_portability_subset")) {
		const char* extension("VK_KHR_portability_subset");
		VkPhysicalDevicePortabilitySubsetPropertiesKHR extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_PROPERTIES_KHR };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_KHR_portability_subset" }, { "name", "minVertexInputBindingStrideAlignment" }, { "value", extProps.minVertexInputBindingStrideAlignment } });
	}
	if (extensionSupported("VK_KHR_maintenance3")) {
		const char* extension("VK_KHR_maintenance3");
		VkPhysicalDeviceMaintenance3Properties extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_KHR_maintenance3" }, { "name", "maxPerSetDescriptors" }, { "value", extProps.maxPerSetDescriptors } });
		pushProperty2(extension, { { "extension", "VK_KHR_maintenance3" }, { "name", "maxMemoryAllocationSize" }, { "value", extProps.maxMemoryAllocationSize } });
	}
	if (extensionSupported("VK_KHR_driver_properties")) {
		const char* extension("VK_KHR_driver_properties");
		VkPhysicalDeviceDriverProperties extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_KHR_driver_properties" }, { "name", "driverID" }, { "value", extProps.driverID } });
		pushProperty2(extension, { { "extension", "VK_KHR_driver_properties" }, { "name", "driverName" }, { "value", extProps.driverName } });
		pushProperty2(extension, { { "extension", "VK_KHR_driver_properties" }, { "name", "driverInfo" }, { "value", extProps.driverInfo } });
		pushProperty2(extension, { { "extension", "VK_KHR_driver_properties" }, { "name", "conformanceVersion" }, { "value", Utils::conformanceVersionKHRString(extProps.conformanceVersion) } });
	}
	if (extensionSupported("VK_KHR_shader_float_controls")) {
		const char* extension("VK_KHR_shader_float_controls");
		VkPhysicalDeviceFloatControlsProperties extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_KHR_shader_float_controls" }, { "name", "denormBehaviorIndependence" }, { "value", extProps.denormBehaviorIndependence } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_float_controls" }, { "name", "roundingModeIndependence" }, { "value", extProps.roundingModeIndependence } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_float_controls" }, { "name", "shaderSignedZeroInfNanPreserveFloat16" }, { "value", extProps.shaderSignedZeroInfNanPreserveFloat16 } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_float_controls" }, { "name", "shaderSignedZeroInfNanPreserveFloat32" }, { "value", extProps.shaderSignedZeroInfNanPreserveFloat32 } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_float_controls" }, { "name", "shaderSignedZeroInfNanPreserveFloat64" }, { "value", extProps.shaderSignedZeroInfNanPreserveFloat64 } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_float_controls" }, { "name", "shaderDenormPreserveFloat16" }, { "value", extProps.shaderDenormPreserveFloat16 } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_float_controls" }, { "name", "shaderDenormPreserveFloat32" }, { "value", extProps.shaderDenormPreserveFloat32 } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_float_controls" }, { "name", "shaderDenormPreserveFloat64" }, { "value", extProps.shaderDenormPreserveFloat64 } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_float_controls" }, { "name", "shaderDenormFlushToZeroFloat16" }, { "value", extProps.shaderDenormFlushToZeroFloat16 } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_float_controls" }, { "name", "shaderDenormFlushToZeroFloat32" }, { "value", extProps.shaderDenormFlushToZeroFloat32 } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_float_controls" }, { "name", "shaderDenormFlushToZeroFloat64" }, { "value", extProps.shaderDenormFlushToZeroFloat64 } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_float_controls" }, { "name", "shaderRoundingModeRTEFloat16" }, { "value", extProps.shaderRoundingModeRTEFloat16 } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_float_controls" }, { "name", "shaderRoundingModeRTEFloat32" }, { "value", extProps.shaderRoundingModeRTEFloat32 } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_float_controls" }, { "name", "shaderRoundingModeRTEFloat64" }, { "value", extProps.shaderRoundingModeRTEFloat64 } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_float_controls" }, { "name", "shaderRoundingModeRTZFloat16" }, { "value", extProps.shaderRoundingModeRTZFloat16 } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_float_controls" }, { "name", "shaderRoundingModeRTZFloat32" }, { "value", extProps.shaderRoundingModeRTZFloat32 } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_float_controls" }, { "name", "shaderRoundingModeRTZFloat64" }, { "value", extProps.shaderRoundingModeRTZFloat64 } });
	}
	if (extensionSupported("VK_KHR_depth_stencil_resolve")) {
		const char* extension("VK_KHR_depth_stencil_resolve");
		VkPhysicalDeviceDepthStencilResolveProperties extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_KHR_depth_stencil_resolve" }, { "name", "supportedDepthResolveModes" }, { "value", extProps.supportedDepthResolveModes } });
		pushProperty2(extension, { { "extension", "VK_KHR_depth_stencil_resolve" }, { "name", "supportedStencilResolveModes" }, { "value", extProps.supportedStencilResolveModes } });
		pushProperty2(extension, { { "extension", "VK_KHR_depth_stencil_resolve" }, { "name", "independentResolveNone" }, { "value", extProps.independentResolveNone } });
		pushProperty2(extension, { { "extension", "VK_KHR_depth_stencil_resolve" }, { "name", "independentResolve" }, { "value", extProps.independentResolve } });
	}
	if (extensionSupported("VK_KHR_timeline_semaphore")) {
		const char* extension("VK_KHR_timeline_semaphore");
		VkPhysicalDeviceTimelineSemaphoreProperties extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_KHR_timeline_semaphore" }, { "name", "maxTimelineSemaphoreValueDifference" }, { "value", extProps.maxTimelineSemaphoreValueDifference } });
	}
	if (extensionSupported("VK_KHR_fragment_shading_rate")) {
		const char* extension("VK_KHR_fragment_shading_rate");
		VkPhysicalDeviceFragmentShadingRatePropertiesKHR extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_KHR_fragment_shading_rate" }, { "name", "minFragmentShadingRateAttachmentTexelSize" }, { "value", { extProps.minFragmentShadingRateAttachmentTexelSize.width, extProps.minFragmentShadingRateAttachmentTexelSize.height } } });
		pushProperty2(extension, { { "extension", "VK_KHR_fragment_shading_rate" }, { "name", "maxFragmentShadingRateAttachmentTexelSize" }, { "value", { extProps.maxFragmentShadingRateAttachmentTexelSize.width, extProps.maxFragmentShadingRateAttachmentTexelSize.height } } });
		pushProperty2(extension, { { "extension", "VK_KHR_fragment_shading_rate" }, { "name", "maxFragmentShadingRateAttachmentTexelSizeAspectRatio" }, { "value", extProps.maxFragmentShadingRateAttachmentTexelSizeAspectRatio } });
		pushProperty2(extension, { { "extension", "VK_KHR_fragment_shading_rate" }, { "name", "primitiveFragmentShadingRateWithMultipleViewports" }, { "value", extProps.primitiveFragmentShadingRateWithMultipleViewports } });
		pushProperty2(extension, { { "extension", "VK_KHR_fragment_shading_rate" }, { "name", "layeredShadingRateAttachments" }, { "value", extProps.layeredShadingRateAttachments } });
		pushProperty2(extension, { { "extension", "VK_KHR_fragment_shading_rate" }, { "name", "fragmentShadingRateNonTrivialCombinerOps" }, { "value", extProps.fragmentShadingRateNonTrivialCombinerOps } });
		pushProperty2(extension, { { "extension", "VK_KHR_fragment_shading_rate" }, { "name", "maxFragmentSize" }, { "value", { extProps.maxFragmentSize.width, extProps.maxFragmentSize.height } } });
		pushProperty2(extension, { { "extension", "VK_KHR_fragment_shading_rate" }, { "name", "maxFragmentSizeAspectRatio" }, { "value", extProps.maxFragmentSizeAspectRatio } });
		pushProperty2(extension, { { "extension", "VK_KHR_fragment_shading_rate" }, { "name", "maxFragmentShadingRateCoverageSamples" }, { "value", extProps.maxFragmentShadingRateCoverageSamples } });
		pushProperty2(extension, { { "extension", "VK_KHR_fragment_shading_rate" }, { "name", "maxFragmentShadingRateRasterizationSamples" }, { "value", extProps.maxFragmentShadingRateRasterizationSamples } });
		pushProperty2(extension, { { "extension", "VK_KHR_fragment_shading_rate" }, { "name", "fragmentShadingRateWithShaderDepthStencilWrites" }, { "value", extProps.fragmentShadingRateWithShaderDepthStencilWrites } });
		pushProperty2(extension, { { "extension", "VK_KHR_fragment_shading_rate" }, { "name", "fragmentShadingRateWithSampleMask" }, { "value", extProps.fragmentShadingRateWithSampleMask } });
		pushProperty2(extension, { { "extension", "VK_KHR_fragment_shading_rate" }, { "name", "fragmentShadingRateWithShaderSampleMask" }, { "value", extProps.fragmentShadingRateWithShaderSampleMask } });
		pushProperty2(extension, { { "extension", "VK_KHR_fragment_shading_rate" }, { "name", "fragmentShadingRateWithConservativeRasterization" }, { "value", extProps.fragmentShadingRateWithConservativeRasterization } });
		pushProperty2(extension, { { "extension", "VK_KHR_fragment_shading_rate" }, { "name", "fragmentShadingRateWithFragmentShaderInterlock" }, { "value", extProps.fragmentShadingRateWithFragmentShaderInterlock } });
		pushProperty2(extension, { { "extension", "VK_KHR_fragment_shading_rate" }, { "name", "fragmentShadingRateWithCustomSampleLocations" }, { "value", extProps.fragmentShadingRateWithCustomSampleLocations } });
		pushProperty2(extension, { { "extension", "VK_KHR_fragment_shading_rate" }, { "name", "fragmentShadingRateStrictMultiplyCombiner" }, { "value", extProps.fragmentShadingRateStrictMultiplyCombiner } });
	}
	if (extensionSupported("VK_KHR_shader_integer_dot_product")) {
		const char* extension("VK_KHR_shader_integer_dot_product");
		VkPhysicalDeviceShaderIntegerDotProductProperties extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProduct8BitUnsignedAccelerated" }, { "value", extProps.integerDotProduct8BitUnsignedAccelerated } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProduct8BitSignedAccelerated" }, { "value", extProps.integerDotProduct8BitSignedAccelerated } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProduct8BitMixedSignednessAccelerated" }, { "value", extProps.integerDotProduct8BitMixedSignednessAccelerated } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProduct4x8BitPackedUnsignedAccelerated" }, { "value", extProps.integerDotProduct4x8BitPackedUnsignedAccelerated } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProduct4x8BitPackedSignedAccelerated" }, { "value", extProps.integerDotProduct4x8BitPackedSignedAccelerated } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProduct4x8BitPackedMixedSignednessAccelerated" }, { "value", extProps.integerDotProduct4x8BitPackedMixedSignednessAccelerated } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProduct16BitUnsignedAccelerated" }, { "value", extProps.integerDotProduct16BitUnsignedAccelerated } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProduct16BitSignedAccelerated" }, { "value", extProps.integerDotProduct16BitSignedAccelerated } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProduct16BitMixedSignednessAccelerated" }, { "value", extProps.integerDotProduct16BitMixedSignednessAccelerated } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProduct32BitUnsignedAccelerated" }, { "value", extProps.integerDotProduct32BitUnsignedAccelerated } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProduct32BitSignedAccelerated" }, { "value", extProps.integerDotProduct32BitSignedAccelerated } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProduct32BitMixedSignednessAccelerated" }, { "value", extProps.integerDotProduct32BitMixedSignednessAccelerated } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProduct64BitUnsignedAccelerated" }, { "value", extProps.integerDotProduct64BitUnsignedAccelerated } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProduct64BitSignedAccelerated" }, { "value", extProps.integerDotProduct64BitSignedAccelerated } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProduct64BitMixedSignednessAccelerated" }, { "value", extProps.integerDotProduct64BitMixedSignednessAccelerated } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProductAccumulatingSaturating8BitUnsignedAccelerated" }, { "value", extProps.integerDotProductAccumulatingSaturating8BitUnsignedAccelerated } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProductAccumulatingSaturating8BitSignedAccelerated" }, { "value", extProps.integerDotProductAccumulatingSaturating8BitSignedAccelerated } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated" }, { "value", extProps.integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated" }, { "value", extProps.integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated" }, { "value", extProps.integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated" }, { "value", extProps.integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProductAccumulatingSaturating16BitUnsignedAccelerated" }, { "value", extProps.integerDotProductAccumulatingSaturating16BitUnsignedAccelerated } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProductAccumulatingSaturating16BitSignedAccelerated" }, { "value", extProps.integerDotProductAccumulatingSaturating16BitSignedAccelerated } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated" }, { "value", extProps.integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProductAccumulatingSaturating32BitUnsignedAccelerated" }, { "value", extProps.integerDotProductAccumulatingSaturating32BitUnsignedAccelerated } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProductAccumulatingSaturating32BitSignedAccelerated" }, { "value", extProps.integerDotProductAccumulatingSaturating32BitSignedAccelerated } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated" }, { "value", extProps.integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProductAccumulatingSaturating64BitUnsignedAccelerated" }, { "value", extProps.integerDotProductAccumulatingSaturating64BitUnsignedAccelerated } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProductAccumulatingSaturating64BitSignedAccelerated" }, { "value", extProps.integerDotProductAccumulatingSaturating64BitSignedAccelerated } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated" }, { "value", extProps.integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated } });
	}
	if (extensionSupported("VK_KHR_fragment_shader_barycentric")) {
		const char* extension("VK_KHR_fragment_shader_barycentric");
		VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_PROPERTIES_KHR };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_KHR_fragment_shader_barycentric" }, { "name", "triStripVertexOrderIndependentOfProvokingVertex" }, { "value", extProps.triStripVertexOrderIndependentOfProvokingVertex } });
	}
	if (extensionSupported("VK_KHR_maintenance4")) {
		const char* extension("VK_KHR_maintenance4");
		VkPhysicalDeviceMaintenance4Properties extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_KHR_maintenance4" }, { "name", "maxBufferSize" }, { "value", extProps.maxBufferSize } });
	}
}
void VulkanDeviceInfoExtensions::readPhysicalProperties_NV() {
	if (extensionSupported("VK_NV_shader_sm_builtins")) {
		const char* extension("VK_NV_shader_sm_builtins");
		VkPhysicalDeviceShaderSMBuiltinsPropertiesNV extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_NV_shader_sm_builtins" }, { "name", "shaderSMCount" }, { "value", extProps.shaderSMCount } });
		pushProperty2(extension, { { "extension", "VK_NV_shader_sm_builtins" }, { "name", "shaderWarpsPerSM" }, { "value", extProps.shaderWarpsPerSM } });
	}
	if (extensionSupported("VK_NV_shading_rate_image")) {
		const char* extension("VK_NV_shading_rate_image");
		VkPhysicalDeviceShadingRateImagePropertiesNV extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_NV_shading_rate_image" }, { "name", "shadingRateTexelSize" }, { "value", { extProps.shadingRateTexelSize.width, extProps.shadingRateTexelSize.height } } });
		pushProperty2(extension, { { "extension", "VK_NV_shading_rate_image" }, { "name", "shadingRatePaletteSize" }, { "value", extProps.shadingRatePaletteSize } });
		pushProperty2(extension, { { "extension", "VK_NV_shading_rate_image" }, { "name", "shadingRateMaxCoarseSamples" }, { "value", extProps.shadingRateMaxCoarseSamples } });
	}
	if (extensionSupported("VK_NV_ray_tracing")) {
		const char* extension("VK_NV_ray_tracing");
		VkPhysicalDeviceRayTracingPropertiesNV extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_NV_ray_tracing" }, { "name", "shaderGroupHandleSize" }, { "value", extProps.shaderGroupHandleSize } });
		pushProperty2(extension, { { "extension", "VK_NV_ray_tracing" }, { "name", "maxRecursionDepth" }, { "value", extProps.maxRecursionDepth } });
		pushProperty2(extension, { { "extension", "VK_NV_ray_tracing" }, { "name", "maxShaderGroupStride" }, { "value", extProps.maxShaderGroupStride } });
		pushProperty2(extension, { { "extension", "VK_NV_ray_tracing" }, { "name", "shaderGroupBaseAlignment" }, { "value", extProps.shaderGroupBaseAlignment } });
		pushProperty2(extension, { { "extension", "VK_NV_ray_tracing" }, { "name", "maxGeometryCount" }, { "value", extProps.maxGeometryCount } });
		pushProperty2(extension, { { "extension", "VK_NV_ray_tracing" }, { "name", "maxInstanceCount" }, { "value", extProps.maxInstanceCount } });
		pushProperty2(extension, { { "extension", "VK_NV_ray_tracing" }, { "name", "maxTriangleCount" }, { "value", extProps.maxTriangleCount } });
		pushProperty2(extension, { { "extension", "VK_NV_ray_tracing" }, { "name", "maxDescriptorSetAccelerationStructures" }, { "value", extProps.maxDescriptorSetAccelerationStructures } });
	}
	if (extensionSupported("VK_NV_mesh_shader")) {
		const char* extension("VK_NV_mesh_shader");
		VkPhysicalDeviceMeshShaderPropertiesNV extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_NV_mesh_shader" }, { "name", "maxDrawMeshTasksCount" }, { "value", extProps.maxDrawMeshTasksCount } });
		pushProperty2(extension, { { "extension", "VK_NV_mesh_shader" }, { "name", "maxTaskWorkGroupInvocations" }, { "value", extProps.maxTaskWorkGroupInvocations } });
		pushProperty2(extension, { { "extension", "VK_NV_mesh_shader" }, { "name", "maxTaskWorkGroupSize" }, { "value", extProps.maxTaskWorkGroupSize } });
		pushProperty2(extension, { { "extension", "VK_NV_mesh_shader" }, { "name", "maxTaskTotalMemorySize" }, { "value", extProps.maxTaskTotalMemorySize } });
		pushProperty2(extension, { { "extension", "VK_NV_mesh_shader" }, { "name", "maxTaskOutputCount" }, { "value", extProps.maxTaskOutputCount } });
		pushProperty2(extension, { { "extension", "VK_NV_mesh_shader" }, { "name", "maxMeshWorkGroupInvocations" }, { "value", extProps.maxMeshWorkGroupInvocations } });
		pushProperty2(extension, { { "extension", "VK_NV_mesh_shader" }, { "name", "maxMeshWorkGroupSize" }, { "value", extProps.maxMeshWorkGroupSize } });
		pushProperty2(extension, { { "extension", "VK_NV_mesh_shader" }, { "name", "maxMeshTotalMemorySize" }, { "value", extProps.maxMeshTotalMemorySize } });
		pushProperty2(extension, { { "extension", "VK_NV_mesh_shader" }, { "name", "maxMeshOutputVertices" }, { "value", extProps.maxMeshOutputVertices } });
		pushProperty2(extension, { { "extension", "VK_NV_mesh_shader" }, { "name", "maxMeshOutputPrimitives" }, { "value", extProps.maxMeshOutputPrimitives } });
		pushProperty2(extension, { { "extension", "VK_NV_mesh_shader" }, { "name", "maxMeshMultiviewViewCount" }, { "value", extProps.maxMeshMultiviewViewCount } });
		pushProperty2(extension, { { "extension", "VK_NV_mesh_shader" }, { "name", "meshOutputPerVertexGranularity" }, { "value", extProps.meshOutputPerVertexGranularity } });
		pushProperty2(extension, { { "extension", "VK_NV_mesh_shader" }, { "name", "meshOutputPerPrimitiveGranularity" }, { "value", extProps.meshOutputPerPrimitiveGranularity } });
	}
	if (extensionSupported("VK_NV_cooperative_matrix")) {
		const char* extension("VK_NV_cooperative_matrix");
		VkPhysicalDeviceCooperativeMatrixPropertiesNV extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_NV_cooperative_matrix" }, { "name", "cooperativeMatrixSupportedStages" }, { "value", extProps.cooperativeMatrixSupportedStages } });
	}
	if (extensionSupported("VK_NV_device_generated_commands")) {
		const char* extension("VK_NV_device_generated_commands");
		VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_NV };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_NV_device_generated_commands" }, { "name", "maxGraphicsShaderGroupCount" }, { "value", extProps.maxGraphicsShaderGroupCount } });
		pushProperty2(extension, { { "extension", "VK_NV_device_generated_commands" }, { "name", "maxIndirectSequenceCount" }, { "value", extProps.maxIndirectSequenceCount } });
		pushProperty2(extension, { { "extension", "VK_NV_device_generated_commands" }, { "name", "maxIndirectCommandsTokenCount" }, { "value", extProps.maxIndirectCommandsTokenCount } });
		pushProperty2(extension, { { "extension", "VK_NV_device_generated_commands" }, { "name", "maxIndirectCommandsStreamCount" }, { "value", extProps.maxIndirectCommandsStreamCount } });
		pushProperty2(extension, { { "extension", "VK_NV_device_generated_commands" }, { "name", "maxIndirectCommandsTokenOffset" }, { "value", extProps.maxIndirectCommandsTokenOffset } });
		pushProperty2(extension, { { "extension", "VK_NV_device_generated_commands" }, { "name", "maxIndirectCommandsStreamStride" }, { "value", extProps.maxIndirectCommandsStreamStride } });
		pushProperty2(extension, { { "extension", "VK_NV_device_generated_commands" }, { "name", "minSequencesCountBufferOffsetAlignment" }, { "value", extProps.minSequencesCountBufferOffsetAlignment } });
		pushProperty2(extension, { { "extension", "VK_NV_device_generated_commands" }, { "name", "minSequencesIndexBufferOffsetAlignment" }, { "value", extProps.minSequencesIndexBufferOffsetAlignment } });
		pushProperty2(extension, { { "extension", "VK_NV_device_generated_commands" }, { "name", "minIndirectCommandsBufferOffsetAlignment" }, { "value", extProps.minIndirectCommandsBufferOffsetAlignment } });
	}
	if (extensionSupported("VK_NV_fragment_shading_rate_enums")) {
		const char* extension("VK_NV_fragment_shading_rate_enums");
		VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_PROPERTIES_NV };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_NV_fragment_shading_rate_enums" }, { "name", "maxFragmentShadingRateInvocationCount" }, { "value", extProps.maxFragmentShadingRateInvocationCount } });
	}
	if (extensionSupported("VK_NV_copy_memory_indirect")) {
		const char* extension("VK_NV_copy_memory_indirect");
		VkPhysicalDeviceCopyMemoryIndirectPropertiesNV extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_PROPERTIES_NV };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_NV_copy_memory_indirect" }, { "name", "supportedQueues" }, { "value", extProps.supportedQueues } });
	}
	if (extensionSupported("VK_NV_memory_decompression")) {
		const char* extension("VK_NV_memory_decompression");
		VkPhysicalDeviceMemoryDecompressionPropertiesNV extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_PROPERTIES_NV };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_NV_memory_decompression" }, { "name", "decompressionMethods" }, { "value", extProps.decompressionMethods } });
		pushProperty2(extension, { { "extension", "VK_NV_memory_decompression" }, { "name", "maxDecompressionIndirectCount" }, { "value", extProps.maxDecompressionIndirectCount } });
	}
	if (extensionSupported("VK_NV_optical_flow")) {
		const char* extension("VK_NV_optical_flow");
		VkPhysicalDeviceOpticalFlowPropertiesNV extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_PROPERTIES_NV };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_NV_optical_flow" }, { "name", "supportedOutputGridSizes" }, { "value", extProps.supportedOutputGridSizes } });
		pushProperty2(extension, { { "extension", "VK_NV_optical_flow" }, { "name", "supportedHintGridSizes" }, { "value", extProps.supportedHintGridSizes } });
		pushProperty2(extension, { { "extension", "VK_NV_optical_flow" }, { "name", "hintSupported" }, { "value", extProps.hintSupported } });
		pushProperty2(extension, { { "extension", "VK_NV_optical_flow" }, { "name", "costSupported" }, { "value", extProps.costSupported } });
		pushProperty2(extension, { { "extension", "VK_NV_optical_flow" }, { "name", "bidirectionalFlowSupported" }, { "value", extProps.bidirectionalFlowSupported } });
		pushProperty2(extension, { { "extension", "VK_NV_optical_flow" }, { "name", "globalFlowSupported" }, { "value", extProps.globalFlowSupported } });
		pushProperty2(extension, { { "extension", "VK_NV_optical_flow" }, { "name", "minWidth" }, { "value", extProps.minWidth } });
		pushProperty2(extension, { { "extension", "VK_NV_optical_flow" }, { "name", "minHeight" }, { "value", extProps.minHeight } });
		pushProperty2(extension, { { "extension", "VK_NV_optical_flow" }, { "name", "maxWidth" }, { "value", extProps.maxWidth } });
		pushProperty2(extension, { { "extension", "VK_NV_optical_flow" }, { "name", "maxHeight" }, { "value", extProps.maxHeight } });
		pushProperty2(extension, { { "extension", "VK_NV_optical_flow" }, { "name", "maxNumRegionsOfInterest" }, { "value", extProps.maxNumRegionsOfInterest } });
	}
	if (extensionSupported("VK_NV_ray_tracing_invocation_reorder")) {
		const char* extension("VK_NV_ray_tracing_invocation_reorder");
		VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_PROPERTIES_NV };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_NV_ray_tracing_invocation_reorder" }, { "name", "rayTracingInvocationReorderReorderingHint" }, { "value", extProps.rayTracingInvocationReorderReorderingHint } });
	}
}
void VulkanDeviceInfoExtensions::readPhysicalProperties_NVX() {
	if (extensionSupported("VK_NVX_multiview_per_view_attributes")) {
		const char* extension("VK_NVX_multiview_per_view_attributes");
		VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_NVX_multiview_per_view_attributes" }, { "name", "perViewPositionAllComponents" }, { "value", extProps.perViewPositionAllComponents } });
	}
}
void VulkanDeviceInfoExtensions::readPhysicalProperties_QCOM() {
	if (extensionSupported("VK_QCOM_fragment_density_map_offset")) {
		const char* extension("VK_QCOM_fragment_density_map_offset");
		VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_PROPERTIES_QCOM };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_QCOM_fragment_density_map_offset" }, { "name", "fragmentDensityOffsetGranularity" }, { "value", { extProps.fragmentDensityOffsetGranularity.width, extProps.fragmentDensityOffsetGranularity.height } } });
	}
	if (extensionSupported("VK_QCOM_image_processing")) {
		const char* extension("VK_QCOM_image_processing");
		VkPhysicalDeviceImageProcessingPropertiesQCOM extProps { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_PROPERTIES_QCOM };
		VkPhysicalDeviceProperties2 deviceProps2(initDeviceProperties2(&extProps));
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_QCOM_image_processing" }, { "name", "maxWeightFilterPhases" }, { "value", extProps.maxWeightFilterPhases } });
		pushProperty2(extension, { { "extension", "VK_QCOM_image_processing" }, { "name", "maxWeightFilterDimension" }, { "value", { extProps.maxWeightFilterDimension.width, extProps.maxWeightFilterDimension.height } } });
		pushProperty2(extension, { { "extension", "VK_QCOM_image_processing" }, { "name", "maxBlockMatchRegion" }, { "value", { extProps.maxBlockMatchRegion.width, extProps.maxBlockMatchRegion.height } } });
		pushProperty2(extension, { { "extension", "VK_QCOM_image_processing" }, { "name", "maxBoxFilterBlockSize" }, { "value", { extProps.maxBoxFilterBlockSize.width, extProps.maxBoxFilterBlockSize.height } } });
	}
}


void VulkanDeviceInfoExtensions::readExtendedProperties() {
    readPhysicalProperties_AMD();
    readPhysicalProperties_ARM();
    readPhysicalProperties_EXT();
    readPhysicalProperties_HUAWEI();
    readPhysicalProperties_KHR();
    readPhysicalProperties_NV();
    readPhysicalProperties_NVX();
    readPhysicalProperties_QCOM();
}

VkPhysicalDeviceFeatures2 VulkanDeviceInfoExtensions::initDeviceFeatures2(void *pNext) {
    VkPhysicalDeviceFeatures2 features2{};
    features2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR;
    features2.pNext = pNext;
    return features2;
}

void VulkanDeviceInfoExtensions::pushFeature2(const char* extension, std::string name, bool supported) {
    features2.push_back(Feature2(name, supported, extension));
}

void VulkanDeviceInfoExtensions::readPhysicalFeatures_AMD() {
	if (extensionSupported("VK_AMD_device_coherent_memory")) {
		const char* extension("VK_AMD_device_coherent_memory");
		VkPhysicalDeviceCoherentMemoryFeaturesAMD extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "deviceCoherentMemory", extFeatures.deviceCoherentMemory);
	}
	if (extensionSupported("VK_AMD_shader_early_and_late_fragment_tests")) {
		const char* extension("VK_AMD_shader_early_and_late_fragment_tests");
		VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_FEATURES_AMD };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "shaderEarlyAndLateFragmentTests", extFeatures.shaderEarlyAndLateFragmentTests);
	}
}
void VulkanDeviceInfoExtensions::readPhysicalFeatures_ARM() {
	if (extensionSupported("VK_ARM_rasterization_order_attachment_access")) {
		const char* extension("VK_ARM_rasterization_order_attachment_access");
		VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "rasterizationOrderColorAttachmentAccess", extFeatures.rasterizationOrderColorAttachmentAccess);
		pushFeature2(extension, "rasterizationOrderDepthAttachmentAccess", extFeatures.rasterizationOrderDepthAttachmentAccess);
		pushFeature2(extension, "rasterizationOrderStencilAttachmentAccess", extFeatures.rasterizationOrderStencilAttachmentAccess);
	}
	if (extensionSupported("VK_ARM_shader_core_builtins")) {
		const char* extension("VK_ARM_shader_core_builtins");
		VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_FEATURES_ARM };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "shaderCoreBuiltins", extFeatures.shaderCoreBuiltins);
	}
}
void VulkanDeviceInfoExtensions::readPhysicalFeatures_EXT() {
	if (extensionSupported("VK_EXT_transform_feedback")) {
		const char* extension("VK_EXT_transform_feedback");
		VkPhysicalDeviceTransformFeedbackFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "transformFeedback", extFeatures.transformFeedback);
		pushFeature2(extension, "geometryStreams", extFeatures.geometryStreams);
	}
	if (extensionSupported("VK_EXT_texture_compression_astc_hdr")) {
		const char* extension("VK_EXT_texture_compression_astc_hdr");
		VkPhysicalDeviceTextureCompressionASTCHDRFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "textureCompressionASTC_HDR", extFeatures.textureCompressionASTC_HDR);
	}
	if (extensionSupported("VK_EXT_astc_decode_mode")) {
		const char* extension("VK_EXT_astc_decode_mode");
		VkPhysicalDeviceASTCDecodeFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "decodeModeSharedExponent", extFeatures.decodeModeSharedExponent);
	}
	if (extensionSupported("VK_EXT_pipeline_robustness")) {
		const char* extension("VK_EXT_pipeline_robustness");
		VkPhysicalDevicePipelineRobustnessFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "pipelineRobustness", extFeatures.pipelineRobustness);
	}
	if (extensionSupported("VK_EXT_conditional_rendering")) {
		const char* extension("VK_EXT_conditional_rendering");
		VkPhysicalDeviceConditionalRenderingFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "conditionalRendering", extFeatures.conditionalRendering);
		pushFeature2(extension, "inheritedConditionalRendering", extFeatures.inheritedConditionalRendering);
	}
	if (extensionSupported("VK_EXT_depth_clip_enable")) {
		const char* extension("VK_EXT_depth_clip_enable");
		VkPhysicalDeviceDepthClipEnableFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "depthClipEnable", extFeatures.depthClipEnable);
	}
	if (extensionSupported("VK_EXT_inline_uniform_block")) {
		const char* extension("VK_EXT_inline_uniform_block");
		VkPhysicalDeviceInlineUniformBlockFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "inlineUniformBlock", extFeatures.inlineUniformBlock);
		pushFeature2(extension, "descriptorBindingInlineUniformBlockUpdateAfterBind", extFeatures.descriptorBindingInlineUniformBlockUpdateAfterBind);
	}
	if (extensionSupported("VK_EXT_blend_operation_advanced")) {
		const char* extension("VK_EXT_blend_operation_advanced");
		VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "advancedBlendCoherentOperations", extFeatures.advancedBlendCoherentOperations);
	}
	if (extensionSupported("VK_EXT_descriptor_indexing")) {
		const char* extension("VK_EXT_descriptor_indexing");
		VkPhysicalDeviceDescriptorIndexingFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "shaderInputAttachmentArrayDynamicIndexing", extFeatures.shaderInputAttachmentArrayDynamicIndexing);
		pushFeature2(extension, "shaderUniformTexelBufferArrayDynamicIndexing", extFeatures.shaderUniformTexelBufferArrayDynamicIndexing);
		pushFeature2(extension, "shaderStorageTexelBufferArrayDynamicIndexing", extFeatures.shaderStorageTexelBufferArrayDynamicIndexing);
		pushFeature2(extension, "shaderUniformBufferArrayNonUniformIndexing", extFeatures.shaderUniformBufferArrayNonUniformIndexing);
		pushFeature2(extension, "shaderSampledImageArrayNonUniformIndexing", extFeatures.shaderSampledImageArrayNonUniformIndexing);
		pushFeature2(extension, "shaderStorageBufferArrayNonUniformIndexing", extFeatures.shaderStorageBufferArrayNonUniformIndexing);
		pushFeature2(extension, "shaderStorageImageArrayNonUniformIndexing", extFeatures.shaderStorageImageArrayNonUniformIndexing);
		pushFeature2(extension, "shaderInputAttachmentArrayNonUniformIndexing", extFeatures.shaderInputAttachmentArrayNonUniformIndexing);
		pushFeature2(extension, "shaderUniformTexelBufferArrayNonUniformIndexing", extFeatures.shaderUniformTexelBufferArrayNonUniformIndexing);
		pushFeature2(extension, "shaderStorageTexelBufferArrayNonUniformIndexing", extFeatures.shaderStorageTexelBufferArrayNonUniformIndexing);
		pushFeature2(extension, "descriptorBindingUniformBufferUpdateAfterBind", extFeatures.descriptorBindingUniformBufferUpdateAfterBind);
		pushFeature2(extension, "descriptorBindingSampledImageUpdateAfterBind", extFeatures.descriptorBindingSampledImageUpdateAfterBind);
		pushFeature2(extension, "descriptorBindingStorageImageUpdateAfterBind", extFeatures.descriptorBindingStorageImageUpdateAfterBind);
		pushFeature2(extension, "descriptorBindingStorageBufferUpdateAfterBind", extFeatures.descriptorBindingStorageBufferUpdateAfterBind);
		pushFeature2(extension, "descriptorBindingUniformTexelBufferUpdateAfterBind", extFeatures.descriptorBindingUniformTexelBufferUpdateAfterBind);
		pushFeature2(extension, "descriptorBindingStorageTexelBufferUpdateAfterBind", extFeatures.descriptorBindingStorageTexelBufferUpdateAfterBind);
		pushFeature2(extension, "descriptorBindingUpdateUnusedWhilePending", extFeatures.descriptorBindingUpdateUnusedWhilePending);
		pushFeature2(extension, "descriptorBindingPartiallyBound", extFeatures.descriptorBindingPartiallyBound);
		pushFeature2(extension, "descriptorBindingVariableDescriptorCount", extFeatures.descriptorBindingVariableDescriptorCount);
		pushFeature2(extension, "runtimeDescriptorArray", extFeatures.runtimeDescriptorArray);
	}
	if (extensionSupported("VK_EXT_vertex_attribute_divisor")) {
		const char* extension("VK_EXT_vertex_attribute_divisor");
		VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "vertexAttributeInstanceRateDivisor", extFeatures.vertexAttributeInstanceRateDivisor);
		pushFeature2(extension, "vertexAttributeInstanceRateZeroDivisor", extFeatures.vertexAttributeInstanceRateZeroDivisor);
	}
	if (extensionSupported("VK_EXT_fragment_density_map")) {
		const char* extension("VK_EXT_fragment_density_map");
		VkPhysicalDeviceFragmentDensityMapFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "fragmentDensityMap", extFeatures.fragmentDensityMap);
		pushFeature2(extension, "fragmentDensityMapDynamic", extFeatures.fragmentDensityMapDynamic);
		pushFeature2(extension, "fragmentDensityMapNonSubsampledImages", extFeatures.fragmentDensityMapNonSubsampledImages);
	}
	if (extensionSupported("VK_EXT_scalar_block_layout")) {
		const char* extension("VK_EXT_scalar_block_layout");
		VkPhysicalDeviceScalarBlockLayoutFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "scalarBlockLayout", extFeatures.scalarBlockLayout);
	}
	if (extensionSupported("VK_EXT_subgroup_size_control")) {
		const char* extension("VK_EXT_subgroup_size_control");
		VkPhysicalDeviceSubgroupSizeControlFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "subgroupSizeControl", extFeatures.subgroupSizeControl);
		pushFeature2(extension, "computeFullSubgroups", extFeatures.computeFullSubgroups);
	}
	if (extensionSupported("VK_EXT_shader_image_atomic_int64")) {
		const char* extension("VK_EXT_shader_image_atomic_int64");
		VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "shaderImageInt64Atomics", extFeatures.shaderImageInt64Atomics);
		pushFeature2(extension, "sparseImageInt64Atomics", extFeatures.sparseImageInt64Atomics);
	}
	if (extensionSupported("VK_EXT_memory_priority")) {
		const char* extension("VK_EXT_memory_priority");
		VkPhysicalDeviceMemoryPriorityFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "memoryPriority", extFeatures.memoryPriority);
	}
	if (extensionSupported("VK_EXT_buffer_device_address")) {
		const char* extension("VK_EXT_buffer_device_address");
		VkPhysicalDeviceBufferDeviceAddressFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "bufferDeviceAddress", extFeatures.bufferDeviceAddress);
		pushFeature2(extension, "bufferDeviceAddressCaptureReplay", extFeatures.bufferDeviceAddressCaptureReplay);
		pushFeature2(extension, "bufferDeviceAddressMultiDevice", extFeatures.bufferDeviceAddressMultiDevice);
	}
	if (extensionSupported("VK_EXT_fragment_shader_interlock")) {
		const char* extension("VK_EXT_fragment_shader_interlock");
		VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "fragmentShaderSampleInterlock", extFeatures.fragmentShaderSampleInterlock);
		pushFeature2(extension, "fragmentShaderPixelInterlock", extFeatures.fragmentShaderPixelInterlock);
		pushFeature2(extension, "fragmentShaderShadingRateInterlock", extFeatures.fragmentShaderShadingRateInterlock);
	}
	if (extensionSupported("VK_EXT_ycbcr_image_arrays")) {
		const char* extension("VK_EXT_ycbcr_image_arrays");
		VkPhysicalDeviceYcbcrImageArraysFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "ycbcrImageArrays", extFeatures.ycbcrImageArrays);
	}
	if (extensionSupported("VK_EXT_provoking_vertex")) {
		const char* extension("VK_EXT_provoking_vertex");
		VkPhysicalDeviceProvokingVertexFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "provokingVertexLast", extFeatures.provokingVertexLast);
		pushFeature2(extension, "transformFeedbackPreservesProvokingVertex", extFeatures.transformFeedbackPreservesProvokingVertex);
	}
	if (extensionSupported("VK_EXT_line_rasterization")) {
		const char* extension("VK_EXT_line_rasterization");
		VkPhysicalDeviceLineRasterizationFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "rectangularLines", extFeatures.rectangularLines);
		pushFeature2(extension, "bresenhamLines", extFeatures.bresenhamLines);
		pushFeature2(extension, "smoothLines", extFeatures.smoothLines);
		pushFeature2(extension, "stippledRectangularLines", extFeatures.stippledRectangularLines);
		pushFeature2(extension, "stippledBresenhamLines", extFeatures.stippledBresenhamLines);
		pushFeature2(extension, "stippledSmoothLines", extFeatures.stippledSmoothLines);
	}
	if (extensionSupported("VK_EXT_shader_atomic_float")) {
		const char* extension("VK_EXT_shader_atomic_float");
		VkPhysicalDeviceShaderAtomicFloatFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "shaderBufferFloat32Atomics", extFeatures.shaderBufferFloat32Atomics);
		pushFeature2(extension, "shaderBufferFloat32AtomicAdd", extFeatures.shaderBufferFloat32AtomicAdd);
		pushFeature2(extension, "shaderBufferFloat64Atomics", extFeatures.shaderBufferFloat64Atomics);
		pushFeature2(extension, "shaderBufferFloat64AtomicAdd", extFeatures.shaderBufferFloat64AtomicAdd);
		pushFeature2(extension, "shaderSharedFloat32Atomics", extFeatures.shaderSharedFloat32Atomics);
		pushFeature2(extension, "shaderSharedFloat32AtomicAdd", extFeatures.shaderSharedFloat32AtomicAdd);
		pushFeature2(extension, "shaderSharedFloat64Atomics", extFeatures.shaderSharedFloat64Atomics);
		pushFeature2(extension, "shaderSharedFloat64AtomicAdd", extFeatures.shaderSharedFloat64AtomicAdd);
		pushFeature2(extension, "shaderImageFloat32Atomics", extFeatures.shaderImageFloat32Atomics);
		pushFeature2(extension, "shaderImageFloat32AtomicAdd", extFeatures.shaderImageFloat32AtomicAdd);
		pushFeature2(extension, "sparseImageFloat32Atomics", extFeatures.sparseImageFloat32Atomics);
		pushFeature2(extension, "sparseImageFloat32AtomicAdd", extFeatures.sparseImageFloat32AtomicAdd);
	}
	if (extensionSupported("VK_EXT_host_query_reset")) {
		const char* extension("VK_EXT_host_query_reset");
		VkPhysicalDeviceHostQueryResetFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "hostQueryReset", extFeatures.hostQueryReset);
	}
	if (extensionSupported("VK_EXT_index_type_uint8")) {
		const char* extension("VK_EXT_index_type_uint8");
		VkPhysicalDeviceIndexTypeUint8FeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "indexTypeUint8", extFeatures.indexTypeUint8);
	}
	if (extensionSupported("VK_EXT_extended_dynamic_state")) {
		const char* extension("VK_EXT_extended_dynamic_state");
		VkPhysicalDeviceExtendedDynamicStateFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "extendedDynamicState", extFeatures.extendedDynamicState);
	}
	if (extensionSupported("VK_EXT_shader_atomic_float2")) {
		const char* extension("VK_EXT_shader_atomic_float2");
		VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_2_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "shaderBufferFloat16Atomics", extFeatures.shaderBufferFloat16Atomics);
		pushFeature2(extension, "shaderBufferFloat16AtomicAdd", extFeatures.shaderBufferFloat16AtomicAdd);
		pushFeature2(extension, "shaderBufferFloat16AtomicMinMax", extFeatures.shaderBufferFloat16AtomicMinMax);
		pushFeature2(extension, "shaderBufferFloat32AtomicMinMax", extFeatures.shaderBufferFloat32AtomicMinMax);
		pushFeature2(extension, "shaderBufferFloat64AtomicMinMax", extFeatures.shaderBufferFloat64AtomicMinMax);
		pushFeature2(extension, "shaderSharedFloat16Atomics", extFeatures.shaderSharedFloat16Atomics);
		pushFeature2(extension, "shaderSharedFloat16AtomicAdd", extFeatures.shaderSharedFloat16AtomicAdd);
		pushFeature2(extension, "shaderSharedFloat16AtomicMinMax", extFeatures.shaderSharedFloat16AtomicMinMax);
		pushFeature2(extension, "shaderSharedFloat32AtomicMinMax", extFeatures.shaderSharedFloat32AtomicMinMax);
		pushFeature2(extension, "shaderSharedFloat64AtomicMinMax", extFeatures.shaderSharedFloat64AtomicMinMax);
		pushFeature2(extension, "shaderImageFloat32AtomicMinMax", extFeatures.shaderImageFloat32AtomicMinMax);
		pushFeature2(extension, "sparseImageFloat32AtomicMinMax", extFeatures.sparseImageFloat32AtomicMinMax);
	}
	if (extensionSupported("VK_EXT_swapchain_maintenance1")) {
		const char* extension("VK_EXT_swapchain_maintenance1");
		VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SWAPCHAIN_MAINTENANCE_1_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "swapchainMaintenance1", extFeatures.swapchainMaintenance1);
	}
	if (extensionSupported("VK_EXT_shader_demote_to_helper_invocation")) {
		const char* extension("VK_EXT_shader_demote_to_helper_invocation");
		VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "shaderDemoteToHelperInvocation", extFeatures.shaderDemoteToHelperInvocation);
	}
	if (extensionSupported("VK_EXT_texel_buffer_alignment")) {
		const char* extension("VK_EXT_texel_buffer_alignment");
		VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "texelBufferAlignment", extFeatures.texelBufferAlignment);
	}
	if (extensionSupported("VK_EXT_device_memory_report")) {
		const char* extension("VK_EXT_device_memory_report");
		VkPhysicalDeviceDeviceMemoryReportFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_MEMORY_REPORT_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "deviceMemoryReport", extFeatures.deviceMemoryReport);
	}
	if (extensionSupported("VK_EXT_robustness2")) {
		const char* extension("VK_EXT_robustness2");
		VkPhysicalDeviceRobustness2FeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "robustBufferAccess2", extFeatures.robustBufferAccess2);
		pushFeature2(extension, "robustImageAccess2", extFeatures.robustImageAccess2);
		pushFeature2(extension, "nullDescriptor", extFeatures.nullDescriptor);
	}
	if (extensionSupported("VK_EXT_custom_border_color")) {
		const char* extension("VK_EXT_custom_border_color");
		VkPhysicalDeviceCustomBorderColorFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "customBorderColors", extFeatures.customBorderColors);
		pushFeature2(extension, "customBorderColorWithoutFormat", extFeatures.customBorderColorWithoutFormat);
	}
	if (extensionSupported("VK_EXT_private_data")) {
		const char* extension("VK_EXT_private_data");
		VkPhysicalDevicePrivateDataFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "privateData", extFeatures.privateData);
	}
	if (extensionSupported("VK_EXT_pipeline_creation_cache_control")) {
		const char* extension("VK_EXT_pipeline_creation_cache_control");
		VkPhysicalDevicePipelineCreationCacheControlFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "pipelineCreationCacheControl", extFeatures.pipelineCreationCacheControl);
	}
	if (extensionSupported("VK_EXT_descriptor_buffer")) {
		const char* extension("VK_EXT_descriptor_buffer");
		VkPhysicalDeviceDescriptorBufferFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "descriptorBuffer", extFeatures.descriptorBuffer);
		pushFeature2(extension, "descriptorBufferCaptureReplay", extFeatures.descriptorBufferCaptureReplay);
		pushFeature2(extension, "descriptorBufferImageLayoutIgnored", extFeatures.descriptorBufferImageLayoutIgnored);
		pushFeature2(extension, "descriptorBufferPushDescriptors", extFeatures.descriptorBufferPushDescriptors);
	}
	if (extensionSupported("VK_EXT_graphics_pipeline_library")) {
		const char* extension("VK_EXT_graphics_pipeline_library");
		VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "graphicsPipelineLibrary", extFeatures.graphicsPipelineLibrary);
	}
	if (extensionSupported("VK_EXT_mesh_shader")) {
		const char* extension("VK_EXT_mesh_shader");
		VkPhysicalDeviceMeshShaderFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "taskShader", extFeatures.taskShader);
		pushFeature2(extension, "meshShader", extFeatures.meshShader);
		pushFeature2(extension, "multiviewMeshShader", extFeatures.multiviewMeshShader);
		pushFeature2(extension, "primitiveFragmentShadingRateMeshShader", extFeatures.primitiveFragmentShadingRateMeshShader);
		pushFeature2(extension, "meshShaderQueries", extFeatures.meshShaderQueries);
	}
	if (extensionSupported("VK_EXT_ycbcr_2plane_444_formats")) {
		const char* extension("VK_EXT_ycbcr_2plane_444_formats");
		VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "ycbcr2plane444Formats", extFeatures.ycbcr2plane444Formats);
	}
	if (extensionSupported("VK_EXT_fragment_density_map2")) {
		const char* extension("VK_EXT_fragment_density_map2");
		VkPhysicalDeviceFragmentDensityMap2FeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "fragmentDensityMapDeferred", extFeatures.fragmentDensityMapDeferred);
	}
	if (extensionSupported("VK_EXT_image_robustness")) {
		const char* extension("VK_EXT_image_robustness");
		VkPhysicalDeviceImageRobustnessFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "robustImageAccess", extFeatures.robustImageAccess);
	}
	if (extensionSupported("VK_EXT_image_compression_control")) {
		const char* extension("VK_EXT_image_compression_control");
		VkPhysicalDeviceImageCompressionControlFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "imageCompressionControl", extFeatures.imageCompressionControl);
	}
	if (extensionSupported("VK_EXT_attachment_feedback_loop_layout")) {
		const char* extension("VK_EXT_attachment_feedback_loop_layout");
		VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_LAYOUT_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "attachmentFeedbackLoopLayout", extFeatures.attachmentFeedbackLoopLayout);
	}
	if (extensionSupported("VK_EXT_4444_formats")) {
		const char* extension("VK_EXT_4444_formats");
		VkPhysicalDevice4444FormatsFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "formatA4R4G4B4", extFeatures.formatA4R4G4B4);
		pushFeature2(extension, "formatA4B4G4R4", extFeatures.formatA4B4G4R4);
	}
	if (extensionSupported("VK_EXT_device_fault")) {
		const char* extension("VK_EXT_device_fault");
		VkPhysicalDeviceFaultFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "deviceFault", extFeatures.deviceFault);
		pushFeature2(extension, "deviceFaultVendorBinary", extFeatures.deviceFaultVendorBinary);
	}
	if (extensionSupported("VK_EXT_rgba10x6_formats")) {
		const char* extension("VK_EXT_rgba10x6_formats");
		VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RGBA10X6_FORMATS_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "formatRgba10x6WithoutYCbCrSampler", extFeatures.formatRgba10x6WithoutYCbCrSampler);
	}
	if (extensionSupported("VK_EXT_vertex_input_dynamic_state")) {
		const char* extension("VK_EXT_vertex_input_dynamic_state");
		VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "vertexInputDynamicState", extFeatures.vertexInputDynamicState);
	}
	if (extensionSupported("VK_EXT_device_address_binding_report")) {
		const char* extension("VK_EXT_device_address_binding_report");
		VkPhysicalDeviceAddressBindingReportFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ADDRESS_BINDING_REPORT_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "reportAddressBinding", extFeatures.reportAddressBinding);
	}
	if (extensionSupported("VK_EXT_depth_clip_control")) {
		const char* extension("VK_EXT_depth_clip_control");
		VkPhysicalDeviceDepthClipControlFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_CONTROL_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "depthClipControl", extFeatures.depthClipControl);
	}
	if (extensionSupported("VK_EXT_primitive_topology_list_restart")) {
		const char* extension("VK_EXT_primitive_topology_list_restart");
		VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_TOPOLOGY_LIST_RESTART_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "primitiveTopologyListRestart", extFeatures.primitiveTopologyListRestart);
		pushFeature2(extension, "primitiveTopologyPatchListRestart", extFeatures.primitiveTopologyPatchListRestart);
	}
	if (extensionSupported("VK_EXT_pipeline_properties")) {
		const char* extension("VK_EXT_pipeline_properties");
		VkPhysicalDevicePipelinePropertiesFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROPERTIES_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "pipelinePropertiesIdentifier", extFeatures.pipelinePropertiesIdentifier);
	}
	if (extensionSupported("VK_EXT_multisampled_render_to_single_sampled")) {
		const char* extension("VK_EXT_multisampled_render_to_single_sampled");
		VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "multisampledRenderToSingleSampled", extFeatures.multisampledRenderToSingleSampled);
	}
	if (extensionSupported("VK_EXT_extended_dynamic_state2")) {
		const char* extension("VK_EXT_extended_dynamic_state2");
		VkPhysicalDeviceExtendedDynamicState2FeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "extendedDynamicState2", extFeatures.extendedDynamicState2);
		pushFeature2(extension, "extendedDynamicState2LogicOp", extFeatures.extendedDynamicState2LogicOp);
		pushFeature2(extension, "extendedDynamicState2PatchControlPoints", extFeatures.extendedDynamicState2PatchControlPoints);
	}
	if (extensionSupported("VK_EXT_color_write_enable")) {
		const char* extension("VK_EXT_color_write_enable");
		VkPhysicalDeviceColorWriteEnableFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "colorWriteEnable", extFeatures.colorWriteEnable);
	}
	if (extensionSupported("VK_EXT_primitives_generated_query")) {
		const char* extension("VK_EXT_primitives_generated_query");
		VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVES_GENERATED_QUERY_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "primitivesGeneratedQuery", extFeatures.primitivesGeneratedQuery);
		pushFeature2(extension, "primitivesGeneratedQueryWithRasterizerDiscard", extFeatures.primitivesGeneratedQueryWithRasterizerDiscard);
		pushFeature2(extension, "primitivesGeneratedQueryWithNonZeroStreams", extFeatures.primitivesGeneratedQueryWithNonZeroStreams);
	}
	if (extensionSupported("VK_EXT_global_priority_query")) {
		const char* extension("VK_EXT_global_priority_query");
		VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES_KHR };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "globalPriorityQuery", extFeatures.globalPriorityQuery);
	}
	if (extensionSupported("VK_EXT_image_view_min_lod")) {
		const char* extension("VK_EXT_image_view_min_lod");
		VkPhysicalDeviceImageViewMinLodFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_MIN_LOD_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "minLod", extFeatures.minLod);
	}
	if (extensionSupported("VK_EXT_multi_draw")) {
		const char* extension("VK_EXT_multi_draw");
		VkPhysicalDeviceMultiDrawFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "multiDraw", extFeatures.multiDraw);
	}
	if (extensionSupported("VK_EXT_image_2d_view_of_3d")) {
		const char* extension("VK_EXT_image_2d_view_of_3d");
		VkPhysicalDeviceImage2DViewOf3DFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_2D_VIEW_OF_3D_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "image2DViewOf3D", extFeatures.image2DViewOf3D);
		pushFeature2(extension, "sampler2DViewOf3D", extFeatures.sampler2DViewOf3D);
	}
	if (extensionSupported("VK_EXT_opacity_micromap")) {
		const char* extension("VK_EXT_opacity_micromap");
		VkPhysicalDeviceOpacityMicromapFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "micromap", extFeatures.micromap);
		pushFeature2(extension, "micromapCaptureReplay", extFeatures.micromapCaptureReplay);
		pushFeature2(extension, "micromapHostCommands", extFeatures.micromapHostCommands);
	}
	if (extensionSupported("VK_EXT_border_color_swizzle")) {
		const char* extension("VK_EXT_border_color_swizzle");
		VkPhysicalDeviceBorderColorSwizzleFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BORDER_COLOR_SWIZZLE_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "borderColorSwizzle", extFeatures.borderColorSwizzle);
		pushFeature2(extension, "borderColorSwizzleFromImage", extFeatures.borderColorSwizzleFromImage);
	}
	if (extensionSupported("VK_EXT_pageable_device_local_memory")) {
		const char* extension("VK_EXT_pageable_device_local_memory");
		VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PAGEABLE_DEVICE_LOCAL_MEMORY_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "pageableDeviceLocalMemory", extFeatures.pageableDeviceLocalMemory);
	}
	if (extensionSupported("VK_EXT_depth_clamp_zero_one")) {
		const char* extension("VK_EXT_depth_clamp_zero_one");
		VkPhysicalDeviceDepthClampZeroOneFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_ZERO_ONE_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "depthClampZeroOne", extFeatures.depthClampZeroOne);
	}
	if (extensionSupported("VK_EXT_non_seamless_cube_map")) {
		const char* extension("VK_EXT_non_seamless_cube_map");
		VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NON_SEAMLESS_CUBE_MAP_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "nonSeamlessCubeMap", extFeatures.nonSeamlessCubeMap);
	}
	if (extensionSupported("VK_EXT_image_compression_control_swapchain")) {
		const char* extension("VK_EXT_image_compression_control_swapchain");
		VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "imageCompressionControlSwapchain", extFeatures.imageCompressionControlSwapchain);
	}
	if (extensionSupported("VK_EXT_extended_dynamic_state3")) {
		const char* extension("VK_EXT_extended_dynamic_state3");
		VkPhysicalDeviceExtendedDynamicState3FeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "extendedDynamicState3TessellationDomainOrigin", extFeatures.extendedDynamicState3TessellationDomainOrigin);
		pushFeature2(extension, "extendedDynamicState3DepthClampEnable", extFeatures.extendedDynamicState3DepthClampEnable);
		pushFeature2(extension, "extendedDynamicState3PolygonMode", extFeatures.extendedDynamicState3PolygonMode);
		pushFeature2(extension, "extendedDynamicState3RasterizationSamples", extFeatures.extendedDynamicState3RasterizationSamples);
		pushFeature2(extension, "extendedDynamicState3SampleMask", extFeatures.extendedDynamicState3SampleMask);
		pushFeature2(extension, "extendedDynamicState3AlphaToCoverageEnable", extFeatures.extendedDynamicState3AlphaToCoverageEnable);
		pushFeature2(extension, "extendedDynamicState3AlphaToOneEnable", extFeatures.extendedDynamicState3AlphaToOneEnable);
		pushFeature2(extension, "extendedDynamicState3LogicOpEnable", extFeatures.extendedDynamicState3LogicOpEnable);
		pushFeature2(extension, "extendedDynamicState3ColorBlendEnable", extFeatures.extendedDynamicState3ColorBlendEnable);
		pushFeature2(extension, "extendedDynamicState3ColorBlendEquation", extFeatures.extendedDynamicState3ColorBlendEquation);
		pushFeature2(extension, "extendedDynamicState3ColorWriteMask", extFeatures.extendedDynamicState3ColorWriteMask);
		pushFeature2(extension, "extendedDynamicState3RasterizationStream", extFeatures.extendedDynamicState3RasterizationStream);
		pushFeature2(extension, "extendedDynamicState3ConservativeRasterizationMode", extFeatures.extendedDynamicState3ConservativeRasterizationMode);
		pushFeature2(extension, "extendedDynamicState3ExtraPrimitiveOverestimationSize", extFeatures.extendedDynamicState3ExtraPrimitiveOverestimationSize);
		pushFeature2(extension, "extendedDynamicState3DepthClipEnable", extFeatures.extendedDynamicState3DepthClipEnable);
		pushFeature2(extension, "extendedDynamicState3SampleLocationsEnable", extFeatures.extendedDynamicState3SampleLocationsEnable);
		pushFeature2(extension, "extendedDynamicState3ColorBlendAdvanced", extFeatures.extendedDynamicState3ColorBlendAdvanced);
		pushFeature2(extension, "extendedDynamicState3ProvokingVertexMode", extFeatures.extendedDynamicState3ProvokingVertexMode);
		pushFeature2(extension, "extendedDynamicState3LineRasterizationMode", extFeatures.extendedDynamicState3LineRasterizationMode);
		pushFeature2(extension, "extendedDynamicState3LineStippleEnable", extFeatures.extendedDynamicState3LineStippleEnable);
		pushFeature2(extension, "extendedDynamicState3DepthClipNegativeOneToOne", extFeatures.extendedDynamicState3DepthClipNegativeOneToOne);
		pushFeature2(extension, "extendedDynamicState3ViewportWScalingEnable", extFeatures.extendedDynamicState3ViewportWScalingEnable);
		pushFeature2(extension, "extendedDynamicState3ViewportSwizzle", extFeatures.extendedDynamicState3ViewportSwizzle);
		pushFeature2(extension, "extendedDynamicState3CoverageToColorEnable", extFeatures.extendedDynamicState3CoverageToColorEnable);
		pushFeature2(extension, "extendedDynamicState3CoverageToColorLocation", extFeatures.extendedDynamicState3CoverageToColorLocation);
		pushFeature2(extension, "extendedDynamicState3CoverageModulationMode", extFeatures.extendedDynamicState3CoverageModulationMode);
		pushFeature2(extension, "extendedDynamicState3CoverageModulationTableEnable", extFeatures.extendedDynamicState3CoverageModulationTableEnable);
		pushFeature2(extension, "extendedDynamicState3CoverageModulationTable", extFeatures.extendedDynamicState3CoverageModulationTable);
		pushFeature2(extension, "extendedDynamicState3CoverageReductionMode", extFeatures.extendedDynamicState3CoverageReductionMode);
		pushFeature2(extension, "extendedDynamicState3RepresentativeFragmentTestEnable", extFeatures.extendedDynamicState3RepresentativeFragmentTestEnable);
		pushFeature2(extension, "extendedDynamicState3ShadingRateImageEnable", extFeatures.extendedDynamicState3ShadingRateImageEnable);
	}
	if (extensionSupported("VK_EXT_subpass_merge_feedback")) {
		const char* extension("VK_EXT_subpass_merge_feedback");
		VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_MERGE_FEEDBACK_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "subpassMergeFeedback", extFeatures.subpassMergeFeedback);
	}
	if (extensionSupported("VK_EXT_shader_module_identifier")) {
		const char* extension("VK_EXT_shader_module_identifier");
		VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "shaderModuleIdentifier", extFeatures.shaderModuleIdentifier);
	}
	if (extensionSupported("VK_EXT_rasterization_order_attachment_access")) {
		const char* extension("VK_EXT_rasterization_order_attachment_access");
		VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "rasterizationOrderColorAttachmentAccess", extFeatures.rasterizationOrderColorAttachmentAccess);
		pushFeature2(extension, "rasterizationOrderDepthAttachmentAccess", extFeatures.rasterizationOrderDepthAttachmentAccess);
		pushFeature2(extension, "rasterizationOrderStencilAttachmentAccess", extFeatures.rasterizationOrderStencilAttachmentAccess);
	}
	if (extensionSupported("VK_EXT_legacy_dithering")) {
		const char* extension("VK_EXT_legacy_dithering");
		VkPhysicalDeviceLegacyDitheringFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_DITHERING_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "legacyDithering", extFeatures.legacyDithering);
	}
	if (extensionSupported("VK_EXT_pipeline_protected_access")) {
		const char* extension("VK_EXT_pipeline_protected_access");
		VkPhysicalDevicePipelineProtectedAccessFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROTECTED_ACCESS_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "pipelineProtectedAccess", extFeatures.pipelineProtectedAccess);
	}
	if (extensionSupported("VK_EXT_mutable_descriptor_type")) {
		const char* extension("VK_EXT_mutable_descriptor_type");
		VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "mutableDescriptorType", extFeatures.mutableDescriptorType);
	}
}
void VulkanDeviceInfoExtensions::readPhysicalFeatures_HUAWEI() {
	if (extensionSupported("VK_HUAWEI_subpass_shading")) {
		const char* extension("VK_HUAWEI_subpass_shading");
		VkPhysicalDeviceSubpassShadingFeaturesHUAWEI extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_SHADING_FEATURES_HUAWEI };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "subpassShading", extFeatures.subpassShading);
	}
	if (extensionSupported("VK_HUAWEI_invocation_mask")) {
		const char* extension("VK_HUAWEI_invocation_mask");
		VkPhysicalDeviceInvocationMaskFeaturesHUAWEI extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INVOCATION_MASK_FEATURES_HUAWEI };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "invocationMask", extFeatures.invocationMask);
	}
}
void VulkanDeviceInfoExtensions::readPhysicalFeatures_INTEL() {
	if (extensionSupported("VK_INTEL_shader_integer_functions2")) {
		const char* extension("VK_INTEL_shader_integer_functions2");
		VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "shaderIntegerFunctions2", extFeatures.shaderIntegerFunctions2);
	}
}
void VulkanDeviceInfoExtensions::readPhysicalFeatures_KHR() {
	if (extensionSupported("VK_KHR_dynamic_rendering")) {
		const char* extension("VK_KHR_dynamic_rendering");
		VkPhysicalDeviceDynamicRenderingFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "dynamicRendering", extFeatures.dynamicRendering);
	}
	if (extensionSupported("VK_KHR_multiview")) {
		const char* extension("VK_KHR_multiview");
		VkPhysicalDeviceMultiviewFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "multiview", extFeatures.multiview);
		pushFeature2(extension, "multiviewGeometryShader", extFeatures.multiviewGeometryShader);
		pushFeature2(extension, "multiviewTessellationShader", extFeatures.multiviewTessellationShader);
	}
	if (extensionSupported("VK_KHR_shader_float16_int8")) {
		const char* extension("VK_KHR_shader_float16_int8");
		VkPhysicalDeviceShaderFloat16Int8Features extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "shaderFloat16", extFeatures.shaderFloat16);
		pushFeature2(extension, "shaderInt8", extFeatures.shaderInt8);
	}
	if (extensionSupported("VK_KHR_16bit_storage")) {
		const char* extension("VK_KHR_16bit_storage");
		VkPhysicalDevice16BitStorageFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "storageBuffer16BitAccess", extFeatures.storageBuffer16BitAccess);
		pushFeature2(extension, "uniformAndStorageBuffer16BitAccess", extFeatures.uniformAndStorageBuffer16BitAccess);
		pushFeature2(extension, "storagePushConstant16", extFeatures.storagePushConstant16);
		pushFeature2(extension, "storageInputOutput16", extFeatures.storageInputOutput16);
	}
	if (extensionSupported("VK_KHR_imageless_framebuffer")) {
		const char* extension("VK_KHR_imageless_framebuffer");
		VkPhysicalDeviceImagelessFramebufferFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "imagelessFramebuffer", extFeatures.imagelessFramebuffer);
	}
	if (extensionSupported("VK_KHR_performance_query")) {
		const char* extension("VK_KHR_performance_query");
		VkPhysicalDevicePerformanceQueryFeaturesKHR extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "performanceCounterQueryPools", extFeatures.performanceCounterQueryPools);
		pushFeature2(extension, "performanceCounterMultipleQueryPools", extFeatures.performanceCounterMultipleQueryPools);
	}
	if (extensionSupported("VK_KHR_variable_pointers")) {
		const char* extension("VK_KHR_variable_pointers");
		VkPhysicalDeviceVariablePointersFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "variablePointersStorageBuffer", extFeatures.variablePointersStorageBuffer);
		pushFeature2(extension, "variablePointers", extFeatures.variablePointers);
	}
	if (extensionSupported("VK_KHR_acceleration_structure")) {
		const char* extension("VK_KHR_acceleration_structure");
		VkPhysicalDeviceAccelerationStructureFeaturesKHR extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "accelerationStructure", extFeatures.accelerationStructure);
		pushFeature2(extension, "accelerationStructureCaptureReplay", extFeatures.accelerationStructureCaptureReplay);
		pushFeature2(extension, "accelerationStructureIndirectBuild", extFeatures.accelerationStructureIndirectBuild);
		pushFeature2(extension, "accelerationStructureHostCommands", extFeatures.accelerationStructureHostCommands);
		pushFeature2(extension, "descriptorBindingAccelerationStructureUpdateAfterBind", extFeatures.descriptorBindingAccelerationStructureUpdateAfterBind);
	}
	if (extensionSupported("VK_KHR_ray_tracing_pipeline")) {
		const char* extension("VK_KHR_ray_tracing_pipeline");
		VkPhysicalDeviceRayTracingPipelineFeaturesKHR extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "rayTracingPipeline", extFeatures.rayTracingPipeline);
		pushFeature2(extension, "rayTracingPipelineShaderGroupHandleCaptureReplay", extFeatures.rayTracingPipelineShaderGroupHandleCaptureReplay);
		pushFeature2(extension, "rayTracingPipelineShaderGroupHandleCaptureReplayMixed", extFeatures.rayTracingPipelineShaderGroupHandleCaptureReplayMixed);
		pushFeature2(extension, "rayTracingPipelineTraceRaysIndirect", extFeatures.rayTracingPipelineTraceRaysIndirect);
		pushFeature2(extension, "rayTraversalPrimitiveCulling", extFeatures.rayTraversalPrimitiveCulling);
	}
	if (extensionSupported("VK_KHR_ray_query")) {
		const char* extension("VK_KHR_ray_query");
		VkPhysicalDeviceRayQueryFeaturesKHR extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_QUERY_FEATURES_KHR };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "rayQuery", extFeatures.rayQuery);
	}
	if (extensionSupported("VK_KHR_sampler_ycbcr_conversion")) {
		const char* extension("VK_KHR_sampler_ycbcr_conversion");
		VkPhysicalDeviceSamplerYcbcrConversionFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "samplerYcbcrConversion", extFeatures.samplerYcbcrConversion);
	}
	if (extensionSupported("VK_KHR_portability_subset")) {
		const char* extension("VK_KHR_portability_subset");
		VkPhysicalDevicePortabilitySubsetFeaturesKHR extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_FEATURES_KHR };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "constantAlphaColorBlendFactors", extFeatures.constantAlphaColorBlendFactors);
		pushFeature2(extension, "events", extFeatures.events);
		pushFeature2(extension, "imageViewFormatReinterpretation", extFeatures.imageViewFormatReinterpretation);
		pushFeature2(extension, "imageViewFormatSwizzle", extFeatures.imageViewFormatSwizzle);
		pushFeature2(extension, "imageView2DOn3DImage", extFeatures.imageView2DOn3DImage);
		pushFeature2(extension, "multisampleArrayImage", extFeatures.multisampleArrayImage);
		pushFeature2(extension, "mutableComparisonSamplers", extFeatures.mutableComparisonSamplers);
		pushFeature2(extension, "pointPolygons", extFeatures.pointPolygons);
		pushFeature2(extension, "samplerMipLodBias", extFeatures.samplerMipLodBias);
		pushFeature2(extension, "separateStencilMaskRef", extFeatures.separateStencilMaskRef);
		pushFeature2(extension, "shaderSampleRateInterpolationFunctions", extFeatures.shaderSampleRateInterpolationFunctions);
		pushFeature2(extension, "tessellationIsolines", extFeatures.tessellationIsolines);
		pushFeature2(extension, "tessellationPointMode", extFeatures.tessellationPointMode);
		pushFeature2(extension, "triangleFans", extFeatures.triangleFans);
		pushFeature2(extension, "vertexAttributeAccessBeyondStride", extFeatures.vertexAttributeAccessBeyondStride);
	}
	if (extensionSupported("VK_KHR_shader_subgroup_extended_types")) {
		const char* extension("VK_KHR_shader_subgroup_extended_types");
		VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "shaderSubgroupExtendedTypes", extFeatures.shaderSubgroupExtendedTypes);
	}
	if (extensionSupported("VK_KHR_8bit_storage")) {
		const char* extension("VK_KHR_8bit_storage");
		VkPhysicalDevice8BitStorageFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "storageBuffer8BitAccess", extFeatures.storageBuffer8BitAccess);
		pushFeature2(extension, "uniformAndStorageBuffer8BitAccess", extFeatures.uniformAndStorageBuffer8BitAccess);
		pushFeature2(extension, "storagePushConstant8", extFeatures.storagePushConstant8);
	}
	if (extensionSupported("VK_KHR_shader_atomic_int64")) {
		const char* extension("VK_KHR_shader_atomic_int64");
		VkPhysicalDeviceShaderAtomicInt64Features extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "shaderBufferInt64Atomics", extFeatures.shaderBufferInt64Atomics);
		pushFeature2(extension, "shaderSharedInt64Atomics", extFeatures.shaderSharedInt64Atomics);
	}
	if (extensionSupported("VK_KHR_shader_clock")) {
		const char* extension("VK_KHR_shader_clock");
		VkPhysicalDeviceShaderClockFeaturesKHR extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "shaderSubgroupClock", extFeatures.shaderSubgroupClock);
		pushFeature2(extension, "shaderDeviceClock", extFeatures.shaderDeviceClock);
	}
	if (extensionSupported("VK_KHR_global_priority")) {
		const char* extension("VK_KHR_global_priority");
		VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES_KHR };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "globalPriorityQuery", extFeatures.globalPriorityQuery);
	}
	if (extensionSupported("VK_KHR_timeline_semaphore")) {
		const char* extension("VK_KHR_timeline_semaphore");
		VkPhysicalDeviceTimelineSemaphoreFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "timelineSemaphore", extFeatures.timelineSemaphore);
	}
	if (extensionSupported("VK_KHR_vulkan_memory_model")) {
		const char* extension("VK_KHR_vulkan_memory_model");
		VkPhysicalDeviceVulkanMemoryModelFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "vulkanMemoryModel", extFeatures.vulkanMemoryModel);
		pushFeature2(extension, "vulkanMemoryModelDeviceScope", extFeatures.vulkanMemoryModelDeviceScope);
		pushFeature2(extension, "vulkanMemoryModelAvailabilityVisibilityChains", extFeatures.vulkanMemoryModelAvailabilityVisibilityChains);
	}
	if (extensionSupported("VK_KHR_shader_terminate_invocation")) {
		const char* extension("VK_KHR_shader_terminate_invocation");
		VkPhysicalDeviceShaderTerminateInvocationFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "shaderTerminateInvocation", extFeatures.shaderTerminateInvocation);
	}
	if (extensionSupported("VK_KHR_fragment_shading_rate")) {
		const char* extension("VK_KHR_fragment_shading_rate");
		VkPhysicalDeviceFragmentShadingRateFeaturesKHR extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "pipelineFragmentShadingRate", extFeatures.pipelineFragmentShadingRate);
		pushFeature2(extension, "primitiveFragmentShadingRate", extFeatures.primitiveFragmentShadingRate);
		pushFeature2(extension, "attachmentFragmentShadingRate", extFeatures.attachmentFragmentShadingRate);
	}
	if (extensionSupported("VK_KHR_separate_depth_stencil_layouts")) {
		const char* extension("VK_KHR_separate_depth_stencil_layouts");
		VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "separateDepthStencilLayouts", extFeatures.separateDepthStencilLayouts);
	}
	if (extensionSupported("VK_KHR_present_wait")) {
		const char* extension("VK_KHR_present_wait");
		VkPhysicalDevicePresentWaitFeaturesKHR extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_FEATURES_KHR };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "presentWait", extFeatures.presentWait);
	}
	if (extensionSupported("VK_KHR_uniform_buffer_standard_layout")) {
		const char* extension("VK_KHR_uniform_buffer_standard_layout");
		VkPhysicalDeviceUniformBufferStandardLayoutFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "uniformBufferStandardLayout", extFeatures.uniformBufferStandardLayout);
	}
	if (extensionSupported("VK_KHR_buffer_device_address")) {
		const char* extension("VK_KHR_buffer_device_address");
		VkPhysicalDeviceBufferDeviceAddressFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "bufferDeviceAddress", extFeatures.bufferDeviceAddress);
		pushFeature2(extension, "bufferDeviceAddressCaptureReplay", extFeatures.bufferDeviceAddressCaptureReplay);
		pushFeature2(extension, "bufferDeviceAddressMultiDevice", extFeatures.bufferDeviceAddressMultiDevice);
	}
	if (extensionSupported("VK_KHR_pipeline_executable_properties")) {
		const char* extension("VK_KHR_pipeline_executable_properties");
		VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "pipelineExecutableInfo", extFeatures.pipelineExecutableInfo);
	}
	if (extensionSupported("VK_KHR_shader_integer_dot_product")) {
		const char* extension("VK_KHR_shader_integer_dot_product");
		VkPhysicalDeviceShaderIntegerDotProductFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "shaderIntegerDotProduct", extFeatures.shaderIntegerDotProduct);
	}
	if (extensionSupported("VK_KHR_present_id")) {
		const char* extension("VK_KHR_present_id");
		VkPhysicalDevicePresentIdFeaturesKHR extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_FEATURES_KHR };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "presentId", extFeatures.presentId);
	}
	if (extensionSupported("VK_KHR_synchronization2")) {
		const char* extension("VK_KHR_synchronization2");
		VkPhysicalDeviceSynchronization2Features extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "synchronization2", extFeatures.synchronization2);
	}
	if (extensionSupported("VK_KHR_fragment_shader_barycentric")) {
		const char* extension("VK_KHR_fragment_shader_barycentric");
		VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_KHR };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "fragmentShaderBarycentric", extFeatures.fragmentShaderBarycentric);
	}
	if (extensionSupported("VK_KHR_shader_subgroup_uniform_control_flow")) {
		const char* extension("VK_KHR_shader_subgroup_uniform_control_flow");
		VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "shaderSubgroupUniformControlFlow", extFeatures.shaderSubgroupUniformControlFlow);
	}
	if (extensionSupported("VK_KHR_zero_initialize_workgroup_memory")) {
		const char* extension("VK_KHR_zero_initialize_workgroup_memory");
		VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "shaderZeroInitializeWorkgroupMemory", extFeatures.shaderZeroInitializeWorkgroupMemory);
	}
	if (extensionSupported("VK_KHR_workgroup_memory_explicit_layout")) {
		const char* extension("VK_KHR_workgroup_memory_explicit_layout");
		VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "workgroupMemoryExplicitLayout", extFeatures.workgroupMemoryExplicitLayout);
		pushFeature2(extension, "workgroupMemoryExplicitLayoutScalarBlockLayout", extFeatures.workgroupMemoryExplicitLayoutScalarBlockLayout);
		pushFeature2(extension, "workgroupMemoryExplicitLayout8BitAccess", extFeatures.workgroupMemoryExplicitLayout8BitAccess);
		pushFeature2(extension, "workgroupMemoryExplicitLayout16BitAccess", extFeatures.workgroupMemoryExplicitLayout16BitAccess);
	}
	if (extensionSupported("VK_KHR_ray_tracing_maintenance1")) {
		const char* extension("VK_KHR_ray_tracing_maintenance1");
		VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MAINTENANCE_1_FEATURES_KHR };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "rayTracingMaintenance1", extFeatures.rayTracingMaintenance1);
		pushFeature2(extension, "rayTracingPipelineTraceRaysIndirect2", extFeatures.rayTracingPipelineTraceRaysIndirect2);
	}
	if (extensionSupported("VK_KHR_maintenance4")) {
		const char* extension("VK_KHR_maintenance4");
		VkPhysicalDeviceMaintenance4Features extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "maintenance4", extFeatures.maintenance4);
	}
}
void VulkanDeviceInfoExtensions::readPhysicalFeatures_NV() {
	if (extensionSupported("VK_NV_corner_sampled_image")) {
		const char* extension("VK_NV_corner_sampled_image");
		VkPhysicalDeviceCornerSampledImageFeaturesNV extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "cornerSampledImage", extFeatures.cornerSampledImage);
	}
	if (extensionSupported("VK_NV_shader_sm_builtins")) {
		const char* extension("VK_NV_shader_sm_builtins");
		VkPhysicalDeviceShaderSMBuiltinsFeaturesNV extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "shaderSMBuiltins", extFeatures.shaderSMBuiltins);
	}
	if (extensionSupported("VK_NV_shading_rate_image")) {
		const char* extension("VK_NV_shading_rate_image");
		VkPhysicalDeviceShadingRateImageFeaturesNV extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "shadingRateImage", extFeatures.shadingRateImage);
		pushFeature2(extension, "shadingRateCoarseSampleOrder", extFeatures.shadingRateCoarseSampleOrder);
	}
	if (extensionSupported("VK_NV_representative_fragment_test")) {
		const char* extension("VK_NV_representative_fragment_test");
		VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "representativeFragmentTest", extFeatures.representativeFragmentTest);
	}
	if (extensionSupported("VK_NV_compute_shader_derivatives")) {
		const char* extension("VK_NV_compute_shader_derivatives");
		VkPhysicalDeviceComputeShaderDerivativesFeaturesNV extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_NV };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "computeDerivativeGroupQuads", extFeatures.computeDerivativeGroupQuads);
		pushFeature2(extension, "computeDerivativeGroupLinear", extFeatures.computeDerivativeGroupLinear);
	}
	if (extensionSupported("VK_NV_mesh_shader")) {
		const char* extension("VK_NV_mesh_shader");
		VkPhysicalDeviceMeshShaderFeaturesNV extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "taskShader", extFeatures.taskShader);
		pushFeature2(extension, "meshShader", extFeatures.meshShader);
	}
	if (extensionSupported("VK_NV_fragment_shader_barycentric")) {
		const char* extension("VK_NV_fragment_shader_barycentric");
		VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_KHR };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "fragmentShaderBarycentric", extFeatures.fragmentShaderBarycentric);
	}
	if (extensionSupported("VK_NV_shader_image_footprint")) {
		const char* extension("VK_NV_shader_image_footprint");
		VkPhysicalDeviceShaderImageFootprintFeaturesNV extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "imageFootprint", extFeatures.imageFootprint);
	}
	if (extensionSupported("VK_NV_scissor_exclusive")) {
		const char* extension("VK_NV_scissor_exclusive");
		VkPhysicalDeviceExclusiveScissorFeaturesNV extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "exclusiveScissor", extFeatures.exclusiveScissor);
	}
	if (extensionSupported("VK_NV_dedicated_allocation_image_aliasing")) {
		const char* extension("VK_NV_dedicated_allocation_image_aliasing");
		VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "dedicatedAllocationImageAliasing", extFeatures.dedicatedAllocationImageAliasing);
	}
	if (extensionSupported("VK_NV_cooperative_matrix")) {
		const char* extension("VK_NV_cooperative_matrix");
		VkPhysicalDeviceCooperativeMatrixFeaturesNV extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "cooperativeMatrix", extFeatures.cooperativeMatrix);
		pushFeature2(extension, "cooperativeMatrixRobustBufferAccess", extFeatures.cooperativeMatrixRobustBufferAccess);
	}
	if (extensionSupported("VK_NV_coverage_reduction_mode")) {
		const char* extension("VK_NV_coverage_reduction_mode");
		VkPhysicalDeviceCoverageReductionModeFeaturesNV extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "coverageReductionMode", extFeatures.coverageReductionMode);
	}
	if (extensionSupported("VK_NV_device_generated_commands")) {
		const char* extension("VK_NV_device_generated_commands");
		VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "deviceGeneratedCommands", extFeatures.deviceGeneratedCommands);
	}
	if (extensionSupported("VK_NV_inherited_viewport_scissor")) {
		const char* extension("VK_NV_inherited_viewport_scissor");
		VkPhysicalDeviceInheritedViewportScissorFeaturesNV extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INHERITED_VIEWPORT_SCISSOR_FEATURES_NV };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "inheritedViewportScissor2D", extFeatures.inheritedViewportScissor2D);
	}
	if (extensionSupported("VK_NV_present_barrier")) {
		const char* extension("VK_NV_present_barrier");
		VkPhysicalDevicePresentBarrierFeaturesNV extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_BARRIER_FEATURES_NV };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "presentBarrier", extFeatures.presentBarrier);
	}
	if (extensionSupported("VK_NV_device_diagnostics_config")) {
		const char* extension("VK_NV_device_diagnostics_config");
		VkPhysicalDeviceDiagnosticsConfigFeaturesNV extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "diagnosticsConfig", extFeatures.diagnosticsConfig);
	}
	if (extensionSupported("VK_NV_fragment_shading_rate_enums")) {
		const char* extension("VK_NV_fragment_shading_rate_enums");
		VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_FEATURES_NV };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "fragmentShadingRateEnums", extFeatures.fragmentShadingRateEnums);
		pushFeature2(extension, "supersampleFragmentShadingRates", extFeatures.supersampleFragmentShadingRates);
		pushFeature2(extension, "noInvocationFragmentShadingRates", extFeatures.noInvocationFragmentShadingRates);
	}
	if (extensionSupported("VK_NV_ray_tracing_motion_blur")) {
		const char* extension("VK_NV_ray_tracing_motion_blur");
		VkPhysicalDeviceRayTracingMotionBlurFeaturesNV extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MOTION_BLUR_FEATURES_NV };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "rayTracingMotionBlur", extFeatures.rayTracingMotionBlur);
		pushFeature2(extension, "rayTracingMotionBlurPipelineTraceRaysIndirect", extFeatures.rayTracingMotionBlurPipelineTraceRaysIndirect);
	}
	if (extensionSupported("VK_NV_external_memory_rdma")) {
		const char* extension("VK_NV_external_memory_rdma");
		VkPhysicalDeviceExternalMemoryRDMAFeaturesNV extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_RDMA_FEATURES_NV };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "externalMemoryRDMA", extFeatures.externalMemoryRDMA);
	}
	if (extensionSupported("VK_NV_copy_memory_indirect")) {
		const char* extension("VK_NV_copy_memory_indirect");
		VkPhysicalDeviceCopyMemoryIndirectFeaturesNV extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_FEATURES_NV };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "indirectCopy", extFeatures.indirectCopy);
	}
	if (extensionSupported("VK_NV_memory_decompression")) {
		const char* extension("VK_NV_memory_decompression");
		VkPhysicalDeviceMemoryDecompressionFeaturesNV extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_FEATURES_NV };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "memoryDecompression", extFeatures.memoryDecompression);
	}
	if (extensionSupported("VK_NV_linear_color_attachment")) {
		const char* extension("VK_NV_linear_color_attachment");
		VkPhysicalDeviceLinearColorAttachmentFeaturesNV extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINEAR_COLOR_ATTACHMENT_FEATURES_NV };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "linearColorAttachment", extFeatures.linearColorAttachment);
	}
	if (extensionSupported("VK_NV_optical_flow")) {
		const char* extension("VK_NV_optical_flow");
		VkPhysicalDeviceOpticalFlowFeaturesNV extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_FEATURES_NV };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "opticalFlow", extFeatures.opticalFlow);
	}
	if (extensionSupported("VK_NV_ray_tracing_invocation_reorder")) {
		const char* extension("VK_NV_ray_tracing_invocation_reorder");
		VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_NV };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "rayTracingInvocationReorder", extFeatures.rayTracingInvocationReorder);
	}
}
void VulkanDeviceInfoExtensions::readPhysicalFeatures_QCOM() {
	if (extensionSupported("VK_QCOM_fragment_density_map_offset")) {
		const char* extension("VK_QCOM_fragment_density_map_offset");
		VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_FEATURES_QCOM };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "fragmentDensityMapOffset", extFeatures.fragmentDensityMapOffset);
	}
	if (extensionSupported("VK_QCOM_image_processing")) {
		const char* extension("VK_QCOM_image_processing");
		VkPhysicalDeviceImageProcessingFeaturesQCOM extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_FEATURES_QCOM };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "textureSampleWeighted", extFeatures.textureSampleWeighted);
		pushFeature2(extension, "textureBoxFilter", extFeatures.textureBoxFilter);
		pushFeature2(extension, "textureBlockMatch", extFeatures.textureBlockMatch);
	}
	if (extensionSupported("VK_QCOM_tile_properties")) {
		const char* extension("VK_QCOM_tile_properties");
		VkPhysicalDeviceTilePropertiesFeaturesQCOM extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_PROPERTIES_FEATURES_QCOM };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "tileProperties", extFeatures.tileProperties);
	}
	if (extensionSupported("VK_QCOM_multiview_per_view_viewports")) {
		const char* extension("VK_QCOM_multiview_per_view_viewports");
		VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_VIEWPORTS_FEATURES_QCOM };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "multiviewPerViewViewports", extFeatures.multiviewPerViewViewports);
	}
}
void VulkanDeviceInfoExtensions::readPhysicalFeatures_SEC() {
	if (extensionSupported("VK_SEC_amigo_profiling")) {
		const char* extension("VK_SEC_amigo_profiling");
		VkPhysicalDeviceAmigoProfilingFeaturesSEC extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_AMIGO_PROFILING_FEATURES_SEC };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "amigoProfiling", extFeatures.amigoProfiling);
	}
}
void VulkanDeviceInfoExtensions::readPhysicalFeatures_VALVE() {
	if (extensionSupported("VK_VALVE_mutable_descriptor_type")) {
		const char* extension("VK_VALVE_mutable_descriptor_type");
		VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_EXT };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "mutableDescriptorType", extFeatures.mutableDescriptorType);
	}
	if (extensionSupported("VK_VALVE_descriptor_set_host_mapping")) {
		const char* extension("VK_VALVE_descriptor_set_host_mapping");
		VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE extFeatures { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_SET_HOST_MAPPING_FEATURES_VALVE };
		VkPhysicalDeviceFeatures2 deviceFeatures2(initDeviceFeatures2(&extFeatures));
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "descriptorSetHostMapping", extFeatures.descriptorSetHostMapping);
	}
}


void VulkanDeviceInfoExtensions::readExtendedFeatures() {
    readPhysicalFeatures_AMD();
    readPhysicalFeatures_ARM();
    readPhysicalFeatures_EXT();
    readPhysicalFeatures_HUAWEI();
    readPhysicalFeatures_INTEL();
    readPhysicalFeatures_KHR();
    readPhysicalFeatures_NV();
    readPhysicalFeatures_QCOM();
    readPhysicalFeatures_SEC();
    readPhysicalFeatures_VALVE();
}
