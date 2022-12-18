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
	VkPhysicalDeviceProperties2 deviceProps2{};
	if (extensionSupported("VK_AMD_shader_core_properties")) {
		const char* extension("VK_AMD_shader_core_properties");
		VkPhysicalDeviceShaderCorePropertiesAMD* extProps = new VkPhysicalDeviceShaderCorePropertiesAMD{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_AMD_shader_core_properties" }, { "name", "shaderEngineCount" }, { "value", extProps->shaderEngineCount } });
		pushProperty2(extension, { { "extension", "VK_AMD_shader_core_properties" }, { "name", "shaderArraysPerEngineCount" }, { "value", extProps->shaderArraysPerEngineCount } });
		pushProperty2(extension, { { "extension", "VK_AMD_shader_core_properties" }, { "name", "computeUnitsPerShaderArray" }, { "value", extProps->computeUnitsPerShaderArray } });
		pushProperty2(extension, { { "extension", "VK_AMD_shader_core_properties" }, { "name", "simdPerComputeUnit" }, { "value", extProps->simdPerComputeUnit } });
		pushProperty2(extension, { { "extension", "VK_AMD_shader_core_properties" }, { "name", "wavefrontsPerSimd" }, { "value", extProps->wavefrontsPerSimd } });
		pushProperty2(extension, { { "extension", "VK_AMD_shader_core_properties" }, { "name", "wavefrontSize" }, { "value", extProps->wavefrontSize } });
		pushProperty2(extension, { { "extension", "VK_AMD_shader_core_properties" }, { "name", "sgprsPerSimd" }, { "value", extProps->sgprsPerSimd } });
		pushProperty2(extension, { { "extension", "VK_AMD_shader_core_properties" }, { "name", "minSgprAllocation" }, { "value", extProps->minSgprAllocation } });
		pushProperty2(extension, { { "extension", "VK_AMD_shader_core_properties" }, { "name", "maxSgprAllocation" }, { "value", extProps->maxSgprAllocation } });
		pushProperty2(extension, { { "extension", "VK_AMD_shader_core_properties" }, { "name", "sgprAllocationGranularity" }, { "value", extProps->sgprAllocationGranularity } });
		pushProperty2(extension, { { "extension", "VK_AMD_shader_core_properties" }, { "name", "vgprsPerSimd" }, { "value", extProps->vgprsPerSimd } });
		pushProperty2(extension, { { "extension", "VK_AMD_shader_core_properties" }, { "name", "minVgprAllocation" }, { "value", extProps->minVgprAllocation } });
		pushProperty2(extension, { { "extension", "VK_AMD_shader_core_properties" }, { "name", "maxVgprAllocation" }, { "value", extProps->maxVgprAllocation } });
		pushProperty2(extension, { { "extension", "VK_AMD_shader_core_properties" }, { "name", "vgprAllocationGranularity" }, { "value", extProps->vgprAllocationGranularity } });
		delete extProps;
	}
	if (extensionSupported("VK_AMD_shader_core_properties2")) {
		const char* extension("VK_AMD_shader_core_properties2");
		VkPhysicalDeviceShaderCoreProperties2AMD* extProps = new VkPhysicalDeviceShaderCoreProperties2AMD{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_AMD_shader_core_properties2" }, { "name", "shaderCoreFeatures" }, { "value", extProps->shaderCoreFeatures } });
		pushProperty2(extension, { { "extension", "VK_AMD_shader_core_properties2" }, { "name", "activeComputeUnitCount" }, { "value", extProps->activeComputeUnitCount } });
		delete extProps;
	}
}
void VulkanDeviceInfoExtensions::readPhysicalProperties_ARM() {
	VkPhysicalDeviceProperties2 deviceProps2{};
	if (extensionSupported("VK_ARM_shader_core_builtins")) {
		const char* extension("VK_ARM_shader_core_builtins");
		VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM* extProps = new VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_PROPERTIES_ARM;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_ARM_shader_core_builtins" }, { "name", "shaderCoreMask" }, { "value", extProps->shaderCoreMask } });
		pushProperty2(extension, { { "extension", "VK_ARM_shader_core_builtins" }, { "name", "shaderCoreCount" }, { "value", extProps->shaderCoreCount } });
		pushProperty2(extension, { { "extension", "VK_ARM_shader_core_builtins" }, { "name", "shaderWarpsPerCore" }, { "value", extProps->shaderWarpsPerCore } });
		delete extProps;
	}
}
void VulkanDeviceInfoExtensions::readPhysicalProperties_EXT() {
	VkPhysicalDeviceProperties2 deviceProps2{};
	if (extensionSupported("VK_EXT_transform_feedback")) {
		const char* extension("VK_EXT_transform_feedback");
		VkPhysicalDeviceTransformFeedbackPropertiesEXT* extProps = new VkPhysicalDeviceTransformFeedbackPropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_transform_feedback" }, { "name", "maxTransformFeedbackStreams" }, { "value", extProps->maxTransformFeedbackStreams } });
		pushProperty2(extension, { { "extension", "VK_EXT_transform_feedback" }, { "name", "maxTransformFeedbackBuffers" }, { "value", extProps->maxTransformFeedbackBuffers } });
		pushProperty2(extension, { { "extension", "VK_EXT_transform_feedback" }, { "name", "maxTransformFeedbackBufferSize" }, { "value", extProps->maxTransformFeedbackBufferSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_transform_feedback" }, { "name", "maxTransformFeedbackStreamDataSize" }, { "value", extProps->maxTransformFeedbackStreamDataSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_transform_feedback" }, { "name", "maxTransformFeedbackBufferDataSize" }, { "value", extProps->maxTransformFeedbackBufferDataSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_transform_feedback" }, { "name", "maxTransformFeedbackBufferDataStride" }, { "value", extProps->maxTransformFeedbackBufferDataStride } });
		pushProperty2(extension, { { "extension", "VK_EXT_transform_feedback" }, { "name", "transformFeedbackQueries" }, { "value", extProps->transformFeedbackQueries ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_EXT_transform_feedback" }, { "name", "transformFeedbackStreamsLinesTriangles" }, { "value", extProps->transformFeedbackStreamsLinesTriangles ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_EXT_transform_feedback" }, { "name", "transformFeedbackRasterizationStreamSelect" }, { "value", extProps->transformFeedbackRasterizationStreamSelect ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_EXT_transform_feedback" }, { "name", "transformFeedbackDraw" }, { "value", extProps->transformFeedbackDraw ? "true" : "false" } });
		delete extProps;
	}
	if (extensionSupported("VK_EXT_pipeline_robustness")) {
		const char* extension("VK_EXT_pipeline_robustness");
		VkPhysicalDevicePipelineRobustnessPropertiesEXT* extProps = new VkPhysicalDevicePipelineRobustnessPropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_pipeline_robustness" }, { "name", "defaultRobustnessStorageBuffers" }, { "value", extProps->defaultRobustnessStorageBuffers } });
		pushProperty2(extension, { { "extension", "VK_EXT_pipeline_robustness" }, { "name", "defaultRobustnessUniformBuffers" }, { "value", extProps->defaultRobustnessUniformBuffers } });
		pushProperty2(extension, { { "extension", "VK_EXT_pipeline_robustness" }, { "name", "defaultRobustnessVertexInputs" }, { "value", extProps->defaultRobustnessVertexInputs } });
		pushProperty2(extension, { { "extension", "VK_EXT_pipeline_robustness" }, { "name", "defaultRobustnessImages" }, { "value", extProps->defaultRobustnessImages } });
		delete extProps;
	}
	if (extensionSupported("VK_EXT_discard_rectangles")) {
		const char* extension("VK_EXT_discard_rectangles");
		VkPhysicalDeviceDiscardRectanglePropertiesEXT* extProps = new VkPhysicalDeviceDiscardRectanglePropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_discard_rectangles" }, { "name", "maxDiscardRectangles" }, { "value", extProps->maxDiscardRectangles } });
		delete extProps;
	}
	if (extensionSupported("VK_EXT_conservative_rasterization")) {
		const char* extension("VK_EXT_conservative_rasterization");
		VkPhysicalDeviceConservativeRasterizationPropertiesEXT* extProps = new VkPhysicalDeviceConservativeRasterizationPropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_conservative_rasterization" }, { "name", "primitiveOverestimationSize" }, { "value", extProps->primitiveOverestimationSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_conservative_rasterization" }, { "name", "maxExtraPrimitiveOverestimationSize" }, { "value", extProps->maxExtraPrimitiveOverestimationSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_conservative_rasterization" }, { "name", "extraPrimitiveOverestimationSizeGranularity" }, { "value", extProps->extraPrimitiveOverestimationSizeGranularity } });
		pushProperty2(extension, { { "extension", "VK_EXT_conservative_rasterization" }, { "name", "primitiveUnderestimation" }, { "value", extProps->primitiveUnderestimation ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_EXT_conservative_rasterization" }, { "name", "conservativePointAndLineRasterization" }, { "value", extProps->conservativePointAndLineRasterization ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_EXT_conservative_rasterization" }, { "name", "degenerateTrianglesRasterized" }, { "value", extProps->degenerateTrianglesRasterized ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_EXT_conservative_rasterization" }, { "name", "degenerateLinesRasterized" }, { "value", extProps->degenerateLinesRasterized ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_EXT_conservative_rasterization" }, { "name", "fullyCoveredFragmentShaderInputVariable" }, { "value", extProps->fullyCoveredFragmentShaderInputVariable ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_EXT_conservative_rasterization" }, { "name", "conservativeRasterizationPostDepthCoverage" }, { "value", extProps->conservativeRasterizationPostDepthCoverage ? "true" : "false" } });
		delete extProps;
	}
	if (extensionSupported("VK_EXT_sampler_filter_minmax")) {
		const char* extension("VK_EXT_sampler_filter_minmax");
		VkPhysicalDeviceSamplerFilterMinmaxProperties* extProps = new VkPhysicalDeviceSamplerFilterMinmaxProperties{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_sampler_filter_minmax" }, { "name", "filterMinmaxSingleComponentFormats" }, { "value", extProps->filterMinmaxSingleComponentFormats ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_EXT_sampler_filter_minmax" }, { "name", "filterMinmaxImageComponentMapping" }, { "value", extProps->filterMinmaxImageComponentMapping ? "true" : "false" } });
		delete extProps;
	}
	if (extensionSupported("VK_EXT_inline_uniform_block")) {
		const char* extension("VK_EXT_inline_uniform_block");
		VkPhysicalDeviceInlineUniformBlockProperties* extProps = new VkPhysicalDeviceInlineUniformBlockProperties{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_inline_uniform_block" }, { "name", "maxInlineUniformBlockSize" }, { "value", extProps->maxInlineUniformBlockSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_inline_uniform_block" }, { "name", "maxPerStageDescriptorInlineUniformBlocks" }, { "value", extProps->maxPerStageDescriptorInlineUniformBlocks } });
		pushProperty2(extension, { { "extension", "VK_EXT_inline_uniform_block" }, { "name", "maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks" }, { "value", extProps->maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks } });
		pushProperty2(extension, { { "extension", "VK_EXT_inline_uniform_block" }, { "name", "maxDescriptorSetInlineUniformBlocks" }, { "value", extProps->maxDescriptorSetInlineUniformBlocks } });
		pushProperty2(extension, { { "extension", "VK_EXT_inline_uniform_block" }, { "name", "maxDescriptorSetUpdateAfterBindInlineUniformBlocks" }, { "value", extProps->maxDescriptorSetUpdateAfterBindInlineUniformBlocks } });
		delete extProps;
	}
	if (extensionSupported("VK_EXT_sample_locations")) {
		const char* extension("VK_EXT_sample_locations");
		VkPhysicalDeviceSampleLocationsPropertiesEXT* extProps = new VkPhysicalDeviceSampleLocationsPropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_sample_locations" }, { "name", "sampleLocationSampleCounts" }, { "value", extProps->sampleLocationSampleCounts } });
		pushProperty2(extension, { { "extension", "VK_EXT_sample_locations" }, { "name", "maxSampleLocationGridSize" }, { "value", { extProps->maxSampleLocationGridSize.width, extProps->maxSampleLocationGridSize.height } } });
		pushProperty2(extension, { { "extension", "VK_EXT_sample_locations" }, { "name", "sampleLocationCoordinateRange" }, { "value", extProps->sampleLocationCoordinateRange } });
		pushProperty2(extension, { { "extension", "VK_EXT_sample_locations" }, { "name", "sampleLocationSubPixelBits" }, { "value", extProps->sampleLocationSubPixelBits } });
		pushProperty2(extension, { { "extension", "VK_EXT_sample_locations" }, { "name", "variableSampleLocations" }, { "value", extProps->variableSampleLocations ? "true" : "false" } });
		delete extProps;
	}
	if (extensionSupported("VK_EXT_blend_operation_advanced")) {
		const char* extension("VK_EXT_blend_operation_advanced");
		VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT* extProps = new VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_blend_operation_advanced" }, { "name", "advancedBlendMaxColorAttachments" }, { "value", extProps->advancedBlendMaxColorAttachments } });
		pushProperty2(extension, { { "extension", "VK_EXT_blend_operation_advanced" }, { "name", "advancedBlendIndependentBlend" }, { "value", extProps->advancedBlendIndependentBlend ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_EXT_blend_operation_advanced" }, { "name", "advancedBlendNonPremultipliedSrcColor" }, { "value", extProps->advancedBlendNonPremultipliedSrcColor ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_EXT_blend_operation_advanced" }, { "name", "advancedBlendNonPremultipliedDstColor" }, { "value", extProps->advancedBlendNonPremultipliedDstColor ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_EXT_blend_operation_advanced" }, { "name", "advancedBlendCorrelatedOverlap" }, { "value", extProps->advancedBlendCorrelatedOverlap ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_EXT_blend_operation_advanced" }, { "name", "advancedBlendAllOperations" }, { "value", extProps->advancedBlendAllOperations ? "true" : "false" } });
		delete extProps;
	}
	if (extensionSupported("VK_EXT_descriptor_indexing")) {
		const char* extension("VK_EXT_descriptor_indexing");
		VkPhysicalDeviceDescriptorIndexingProperties* extProps = new VkPhysicalDeviceDescriptorIndexingProperties{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_indexing" }, { "name", "maxUpdateAfterBindDescriptorsInAllPools" }, { "value", extProps->maxUpdateAfterBindDescriptorsInAllPools } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_indexing" }, { "name", "shaderUniformBufferArrayNonUniformIndexingNative" }, { "value", extProps->shaderUniformBufferArrayNonUniformIndexingNative ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_indexing" }, { "name", "shaderSampledImageArrayNonUniformIndexingNative" }, { "value", extProps->shaderSampledImageArrayNonUniformIndexingNative ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_indexing" }, { "name", "shaderStorageBufferArrayNonUniformIndexingNative" }, { "value", extProps->shaderStorageBufferArrayNonUniformIndexingNative ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_indexing" }, { "name", "shaderStorageImageArrayNonUniformIndexingNative" }, { "value", extProps->shaderStorageImageArrayNonUniformIndexingNative ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_indexing" }, { "name", "shaderInputAttachmentArrayNonUniformIndexingNative" }, { "value", extProps->shaderInputAttachmentArrayNonUniformIndexingNative ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_indexing" }, { "name", "robustBufferAccessUpdateAfterBind" }, { "value", extProps->robustBufferAccessUpdateAfterBind ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_indexing" }, { "name", "quadDivergentImplicitLod" }, { "value", extProps->quadDivergentImplicitLod ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_indexing" }, { "name", "maxPerStageDescriptorUpdateAfterBindSamplers" }, { "value", extProps->maxPerStageDescriptorUpdateAfterBindSamplers } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_indexing" }, { "name", "maxPerStageDescriptorUpdateAfterBindUniformBuffers" }, { "value", extProps->maxPerStageDescriptorUpdateAfterBindUniformBuffers } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_indexing" }, { "name", "maxPerStageDescriptorUpdateAfterBindStorageBuffers" }, { "value", extProps->maxPerStageDescriptorUpdateAfterBindStorageBuffers } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_indexing" }, { "name", "maxPerStageDescriptorUpdateAfterBindSampledImages" }, { "value", extProps->maxPerStageDescriptorUpdateAfterBindSampledImages } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_indexing" }, { "name", "maxPerStageDescriptorUpdateAfterBindStorageImages" }, { "value", extProps->maxPerStageDescriptorUpdateAfterBindStorageImages } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_indexing" }, { "name", "maxPerStageDescriptorUpdateAfterBindInputAttachments" }, { "value", extProps->maxPerStageDescriptorUpdateAfterBindInputAttachments } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_indexing" }, { "name", "maxPerStageUpdateAfterBindResources" }, { "value", extProps->maxPerStageUpdateAfterBindResources } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_indexing" }, { "name", "maxDescriptorSetUpdateAfterBindSamplers" }, { "value", extProps->maxDescriptorSetUpdateAfterBindSamplers } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_indexing" }, { "name", "maxDescriptorSetUpdateAfterBindUniformBuffers" }, { "value", extProps->maxDescriptorSetUpdateAfterBindUniformBuffers } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_indexing" }, { "name", "maxDescriptorSetUpdateAfterBindUniformBuffersDynamic" }, { "value", extProps->maxDescriptorSetUpdateAfterBindUniformBuffersDynamic } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_indexing" }, { "name", "maxDescriptorSetUpdateAfterBindStorageBuffers" }, { "value", extProps->maxDescriptorSetUpdateAfterBindStorageBuffers } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_indexing" }, { "name", "maxDescriptorSetUpdateAfterBindStorageBuffersDynamic" }, { "value", extProps->maxDescriptorSetUpdateAfterBindStorageBuffersDynamic } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_indexing" }, { "name", "maxDescriptorSetUpdateAfterBindSampledImages" }, { "value", extProps->maxDescriptorSetUpdateAfterBindSampledImages } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_indexing" }, { "name", "maxDescriptorSetUpdateAfterBindStorageImages" }, { "value", extProps->maxDescriptorSetUpdateAfterBindStorageImages } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_indexing" }, { "name", "maxDescriptorSetUpdateAfterBindInputAttachments" }, { "value", extProps->maxDescriptorSetUpdateAfterBindInputAttachments } });
		delete extProps;
	}
	if (extensionSupported("VK_EXT_external_memory_host")) {
		const char* extension("VK_EXT_external_memory_host");
		VkPhysicalDeviceExternalMemoryHostPropertiesEXT* extProps = new VkPhysicalDeviceExternalMemoryHostPropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_external_memory_host" }, { "name", "minImportedHostPointerAlignment" }, { "value", extProps->minImportedHostPointerAlignment } });
		delete extProps;
	}
	if (extensionSupported("VK_EXT_vertex_attribute_divisor")) {
		const char* extension("VK_EXT_vertex_attribute_divisor");
		VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT* extProps = new VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_vertex_attribute_divisor" }, { "name", "maxVertexAttribDivisor" }, { "value", extProps->maxVertexAttribDivisor } });
		delete extProps;
	}
	if (extensionSupported("VK_EXT_pci_bus_info")) {
		const char* extension("VK_EXT_pci_bus_info");
		VkPhysicalDevicePCIBusInfoPropertiesEXT* extProps = new VkPhysicalDevicePCIBusInfoPropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_pci_bus_info" }, { "name", "pciDomain" }, { "value", extProps->pciDomain } });
		pushProperty2(extension, { { "extension", "VK_EXT_pci_bus_info" }, { "name", "pciBus" }, { "value", extProps->pciBus } });
		pushProperty2(extension, { { "extension", "VK_EXT_pci_bus_info" }, { "name", "pciDevice" }, { "value", extProps->pciDevice } });
		pushProperty2(extension, { { "extension", "VK_EXT_pci_bus_info" }, { "name", "pciFunction" }, { "value", extProps->pciFunction } });
		delete extProps;
	}
	if (extensionSupported("VK_EXT_fragment_density_map")) {
		const char* extension("VK_EXT_fragment_density_map");
		VkPhysicalDeviceFragmentDensityMapPropertiesEXT* extProps = new VkPhysicalDeviceFragmentDensityMapPropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_fragment_density_map" }, { "name", "minFragmentDensityTexelSize" }, { "value", { extProps->minFragmentDensityTexelSize.width, extProps->minFragmentDensityTexelSize.height } } });
		pushProperty2(extension, { { "extension", "VK_EXT_fragment_density_map" }, { "name", "maxFragmentDensityTexelSize" }, { "value", { extProps->maxFragmentDensityTexelSize.width, extProps->maxFragmentDensityTexelSize.height } } });
		pushProperty2(extension, { { "extension", "VK_EXT_fragment_density_map" }, { "name", "fragmentDensityInvocations" }, { "value", extProps->fragmentDensityInvocations ? "true" : "false" } });
		delete extProps;
	}
	if (extensionSupported("VK_EXT_subgroup_size_control")) {
		const char* extension("VK_EXT_subgroup_size_control");
		VkPhysicalDeviceSubgroupSizeControlProperties* extProps = new VkPhysicalDeviceSubgroupSizeControlProperties{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_subgroup_size_control" }, { "name", "minSubgroupSize" }, { "value", extProps->minSubgroupSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_subgroup_size_control" }, { "name", "maxSubgroupSize" }, { "value", extProps->maxSubgroupSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_subgroup_size_control" }, { "name", "maxComputeWorkgroupSubgroups" }, { "value", extProps->maxComputeWorkgroupSubgroups } });
		pushProperty2(extension, { { "extension", "VK_EXT_subgroup_size_control" }, { "name", "requiredSubgroupSizeStages" }, { "value", extProps->requiredSubgroupSizeStages } });
		delete extProps;
	}
	if (extensionSupported("VK_EXT_provoking_vertex")) {
		const char* extension("VK_EXT_provoking_vertex");
		VkPhysicalDeviceProvokingVertexPropertiesEXT* extProps = new VkPhysicalDeviceProvokingVertexPropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_provoking_vertex" }, { "name", "provokingVertexModePerPipeline" }, { "value", extProps->provokingVertexModePerPipeline ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_EXT_provoking_vertex" }, { "name", "transformFeedbackPreservesTriangleFanProvokingVertex" }, { "value", extProps->transformFeedbackPreservesTriangleFanProvokingVertex ? "true" : "false" } });
		delete extProps;
	}
	if (extensionSupported("VK_EXT_line_rasterization")) {
		const char* extension("VK_EXT_line_rasterization");
		VkPhysicalDeviceLineRasterizationPropertiesEXT* extProps = new VkPhysicalDeviceLineRasterizationPropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_line_rasterization" }, { "name", "lineSubPixelPrecisionBits" }, { "value", extProps->lineSubPixelPrecisionBits } });
		delete extProps;
	}
	if (extensionSupported("VK_EXT_texel_buffer_alignment")) {
		const char* extension("VK_EXT_texel_buffer_alignment");
		VkPhysicalDeviceTexelBufferAlignmentProperties* extProps = new VkPhysicalDeviceTexelBufferAlignmentProperties{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_texel_buffer_alignment" }, { "name", "storageTexelBufferOffsetAlignmentBytes" }, { "value", extProps->storageTexelBufferOffsetAlignmentBytes } });
		pushProperty2(extension, { { "extension", "VK_EXT_texel_buffer_alignment" }, { "name", "storageTexelBufferOffsetSingleTexelAlignment" }, { "value", extProps->storageTexelBufferOffsetSingleTexelAlignment ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_EXT_texel_buffer_alignment" }, { "name", "uniformTexelBufferOffsetAlignmentBytes" }, { "value", extProps->uniformTexelBufferOffsetAlignmentBytes } });
		pushProperty2(extension, { { "extension", "VK_EXT_texel_buffer_alignment" }, { "name", "uniformTexelBufferOffsetSingleTexelAlignment" }, { "value", extProps->uniformTexelBufferOffsetSingleTexelAlignment ? "true" : "false" } });
		delete extProps;
	}
	if (extensionSupported("VK_EXT_robustness2")) {
		const char* extension("VK_EXT_robustness2");
		VkPhysicalDeviceRobustness2PropertiesEXT* extProps = new VkPhysicalDeviceRobustness2PropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_robustness2" }, { "name", "robustStorageBufferAccessSizeAlignment" }, { "value", extProps->robustStorageBufferAccessSizeAlignment } });
		pushProperty2(extension, { { "extension", "VK_EXT_robustness2" }, { "name", "robustUniformBufferAccessSizeAlignment" }, { "value", extProps->robustUniformBufferAccessSizeAlignment } });
		delete extProps;
	}
	if (extensionSupported("VK_EXT_custom_border_color")) {
		const char* extension("VK_EXT_custom_border_color");
		VkPhysicalDeviceCustomBorderColorPropertiesEXT* extProps = new VkPhysicalDeviceCustomBorderColorPropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_custom_border_color" }, { "name", "maxCustomBorderColorSamplers" }, { "value", extProps->maxCustomBorderColorSamplers } });
		delete extProps;
	}
	if (extensionSupported("VK_EXT_descriptor_buffer")) {
		const char* extension("VK_EXT_descriptor_buffer");
		VkPhysicalDeviceDescriptorBufferPropertiesEXT* extProps = new VkPhysicalDeviceDescriptorBufferPropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "combinedImageSamplerDescriptorSingleArray" }, { "value", extProps->combinedImageSamplerDescriptorSingleArray ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "bufferlessPushDescriptors" }, { "value", extProps->bufferlessPushDescriptors ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "allowSamplerImageViewPostSubmitCreation" }, { "value", extProps->allowSamplerImageViewPostSubmitCreation ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "descriptorBufferOffsetAlignment" }, { "value", extProps->descriptorBufferOffsetAlignment } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "maxDescriptorBufferBindings" }, { "value", extProps->maxDescriptorBufferBindings } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "maxResourceDescriptorBufferBindings" }, { "value", extProps->maxResourceDescriptorBufferBindings } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "maxSamplerDescriptorBufferBindings" }, { "value", extProps->maxSamplerDescriptorBufferBindings } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "maxEmbeddedImmutableSamplerBindings" }, { "value", extProps->maxEmbeddedImmutableSamplerBindings } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "maxEmbeddedImmutableSamplers" }, { "value", extProps->maxEmbeddedImmutableSamplers } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "bufferCaptureReplayDescriptorDataSize" }, { "value", extProps->bufferCaptureReplayDescriptorDataSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "imageCaptureReplayDescriptorDataSize" }, { "value", extProps->imageCaptureReplayDescriptorDataSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "imageViewCaptureReplayDescriptorDataSize" }, { "value", extProps->imageViewCaptureReplayDescriptorDataSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "samplerCaptureReplayDescriptorDataSize" }, { "value", extProps->samplerCaptureReplayDescriptorDataSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "accelerationStructureCaptureReplayDescriptorDataSize" }, { "value", extProps->accelerationStructureCaptureReplayDescriptorDataSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "samplerDescriptorSize" }, { "value", extProps->samplerDescriptorSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "combinedImageSamplerDescriptorSize" }, { "value", extProps->combinedImageSamplerDescriptorSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "sampledImageDescriptorSize" }, { "value", extProps->sampledImageDescriptorSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "storageImageDescriptorSize" }, { "value", extProps->storageImageDescriptorSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "uniformTexelBufferDescriptorSize" }, { "value", extProps->uniformTexelBufferDescriptorSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "robustUniformTexelBufferDescriptorSize" }, { "value", extProps->robustUniformTexelBufferDescriptorSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "storageTexelBufferDescriptorSize" }, { "value", extProps->storageTexelBufferDescriptorSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "robustStorageTexelBufferDescriptorSize" }, { "value", extProps->robustStorageTexelBufferDescriptorSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "uniformBufferDescriptorSize" }, { "value", extProps->uniformBufferDescriptorSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "robustUniformBufferDescriptorSize" }, { "value", extProps->robustUniformBufferDescriptorSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "storageBufferDescriptorSize" }, { "value", extProps->storageBufferDescriptorSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "robustStorageBufferDescriptorSize" }, { "value", extProps->robustStorageBufferDescriptorSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "inputAttachmentDescriptorSize" }, { "value", extProps->inputAttachmentDescriptorSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "accelerationStructureDescriptorSize" }, { "value", extProps->accelerationStructureDescriptorSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "maxSamplerDescriptorBufferRange" }, { "value", extProps->maxSamplerDescriptorBufferRange } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "maxResourceDescriptorBufferRange" }, { "value", extProps->maxResourceDescriptorBufferRange } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "samplerDescriptorBufferAddressSpaceSize" }, { "value", extProps->samplerDescriptorBufferAddressSpaceSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "resourceDescriptorBufferAddressSpaceSize" }, { "value", extProps->resourceDescriptorBufferAddressSpaceSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_descriptor_buffer" }, { "name", "descriptorBufferAddressSpaceSize" }, { "value", extProps->descriptorBufferAddressSpaceSize } });
		delete extProps;
	}
	if (extensionSupported("VK_EXT_graphics_pipeline_library")) {
		const char* extension("VK_EXT_graphics_pipeline_library");
		VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT* extProps = new VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_graphics_pipeline_library" }, { "name", "graphicsPipelineLibraryFastLinking" }, { "value", extProps->graphicsPipelineLibraryFastLinking ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_EXT_graphics_pipeline_library" }, { "name", "graphicsPipelineLibraryIndependentInterpolationDecoration" }, { "value", extProps->graphicsPipelineLibraryIndependentInterpolationDecoration ? "true" : "false" } });
		delete extProps;
	}
	if (extensionSupported("VK_EXT_mesh_shader")) {
		const char* extension("VK_EXT_mesh_shader");
		VkPhysicalDeviceMeshShaderPropertiesEXT* extProps = new VkPhysicalDeviceMeshShaderPropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "maxTaskWorkGroupTotalCount" }, { "value", extProps->maxTaskWorkGroupTotalCount } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "maxTaskWorkGroupCount" }, { "value", extProps->maxTaskWorkGroupCount } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "maxTaskWorkGroupInvocations" }, { "value", extProps->maxTaskWorkGroupInvocations } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "maxTaskWorkGroupSize" }, { "value", extProps->maxTaskWorkGroupSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "maxTaskPayloadSize" }, { "value", extProps->maxTaskPayloadSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "maxTaskSharedMemorySize" }, { "value", extProps->maxTaskSharedMemorySize } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "maxTaskPayloadAndSharedMemorySize" }, { "value", extProps->maxTaskPayloadAndSharedMemorySize } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "maxMeshWorkGroupTotalCount" }, { "value", extProps->maxMeshWorkGroupTotalCount } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "maxMeshWorkGroupCount" }, { "value", extProps->maxMeshWorkGroupCount } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "maxMeshWorkGroupInvocations" }, { "value", extProps->maxMeshWorkGroupInvocations } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "maxMeshWorkGroupSize" }, { "value", extProps->maxMeshWorkGroupSize } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "maxMeshSharedMemorySize" }, { "value", extProps->maxMeshSharedMemorySize } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "maxMeshPayloadAndSharedMemorySize" }, { "value", extProps->maxMeshPayloadAndSharedMemorySize } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "maxMeshOutputMemorySize" }, { "value", extProps->maxMeshOutputMemorySize } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "maxMeshPayloadAndOutputMemorySize" }, { "value", extProps->maxMeshPayloadAndOutputMemorySize } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "maxMeshOutputComponents" }, { "value", extProps->maxMeshOutputComponents } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "maxMeshOutputVertices" }, { "value", extProps->maxMeshOutputVertices } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "maxMeshOutputPrimitives" }, { "value", extProps->maxMeshOutputPrimitives } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "maxMeshOutputLayers" }, { "value", extProps->maxMeshOutputLayers } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "maxMeshMultiviewViewCount" }, { "value", extProps->maxMeshMultiviewViewCount } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "meshOutputPerVertexGranularity" }, { "value", extProps->meshOutputPerVertexGranularity } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "meshOutputPerPrimitiveGranularity" }, { "value", extProps->meshOutputPerPrimitiveGranularity } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "maxPreferredTaskWorkGroupInvocations" }, { "value", extProps->maxPreferredTaskWorkGroupInvocations } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "maxPreferredMeshWorkGroupInvocations" }, { "value", extProps->maxPreferredMeshWorkGroupInvocations } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "prefersLocalInvocationVertexOutput" }, { "value", extProps->prefersLocalInvocationVertexOutput ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "prefersLocalInvocationPrimitiveOutput" }, { "value", extProps->prefersLocalInvocationPrimitiveOutput ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "prefersCompactVertexOutput" }, { "value", extProps->prefersCompactVertexOutput ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_EXT_mesh_shader" }, { "name", "prefersCompactPrimitiveOutput" }, { "value", extProps->prefersCompactPrimitiveOutput ? "true" : "false" } });
		delete extProps;
	}
	if (extensionSupported("VK_EXT_fragment_density_map2")) {
		const char* extension("VK_EXT_fragment_density_map2");
		VkPhysicalDeviceFragmentDensityMap2PropertiesEXT* extProps = new VkPhysicalDeviceFragmentDensityMap2PropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_fragment_density_map2" }, { "name", "subsampledLoads" }, { "value", extProps->subsampledLoads ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_EXT_fragment_density_map2" }, { "name", "subsampledCoarseReconstructionEarlyAccess" }, { "value", extProps->subsampledCoarseReconstructionEarlyAccess ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_EXT_fragment_density_map2" }, { "name", "maxSubsampledArrayLayers" }, { "value", extProps->maxSubsampledArrayLayers } });
		pushProperty2(extension, { { "extension", "VK_EXT_fragment_density_map2" }, { "name", "maxDescriptorSetSubsampledSamplers" }, { "value", extProps->maxDescriptorSetSubsampledSamplers } });
		delete extProps;
	}
	if (extensionSupported("VK_EXT_physical_device_drm")) {
		const char* extension("VK_EXT_physical_device_drm");
		VkPhysicalDeviceDrmPropertiesEXT* extProps = new VkPhysicalDeviceDrmPropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRM_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_physical_device_drm" }, { "name", "hasPrimary" }, { "value", extProps->hasPrimary ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_EXT_physical_device_drm" }, { "name", "hasRender" }, { "value", extProps->hasRender ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_EXT_physical_device_drm" }, { "name", "primaryMajor" }, { "value", extProps->primaryMajor } });
		pushProperty2(extension, { { "extension", "VK_EXT_physical_device_drm" }, { "name", "primaryMinor" }, { "value", extProps->primaryMinor } });
		pushProperty2(extension, { { "extension", "VK_EXT_physical_device_drm" }, { "name", "renderMajor" }, { "value", extProps->renderMajor } });
		pushProperty2(extension, { { "extension", "VK_EXT_physical_device_drm" }, { "name", "renderMinor" }, { "value", extProps->renderMinor } });
		delete extProps;
	}
	if (extensionSupported("VK_EXT_multi_draw")) {
		const char* extension("VK_EXT_multi_draw");
		VkPhysicalDeviceMultiDrawPropertiesEXT* extProps = new VkPhysicalDeviceMultiDrawPropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_multi_draw" }, { "name", "maxMultiDrawCount" }, { "value", extProps->maxMultiDrawCount } });
		delete extProps;
	}
	if (extensionSupported("VK_EXT_opacity_micromap")) {
		const char* extension("VK_EXT_opacity_micromap");
		VkPhysicalDeviceOpacityMicromapPropertiesEXT* extProps = new VkPhysicalDeviceOpacityMicromapPropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_opacity_micromap" }, { "name", "maxOpacity2StateSubdivisionLevel" }, { "value", extProps->maxOpacity2StateSubdivisionLevel } });
		pushProperty2(extension, { { "extension", "VK_EXT_opacity_micromap" }, { "name", "maxOpacity4StateSubdivisionLevel" }, { "value", extProps->maxOpacity4StateSubdivisionLevel } });
		delete extProps;
	}
	if (extensionSupported("VK_EXT_extended_dynamic_state3")) {
		const char* extension("VK_EXT_extended_dynamic_state3");
		VkPhysicalDeviceExtendedDynamicState3PropertiesEXT* extProps = new VkPhysicalDeviceExtendedDynamicState3PropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_extended_dynamic_state3" }, { "name", "dynamicPrimitiveTopologyUnrestricted" }, { "value", extProps->dynamicPrimitiveTopologyUnrestricted ? "true" : "false" } });
		delete extProps;
	}
	if (extensionSupported("VK_EXT_shader_module_identifier")) {
		const char* extension("VK_EXT_shader_module_identifier");
		VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT* extProps = new VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_PROPERTIES_EXT;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_EXT_shader_module_identifier" }, { "name", "shaderModuleIdentifierAlgorithmUUID" }, { "value", extProps->shaderModuleIdentifierAlgorithmUUID } });
		delete extProps;
	}
}
void VulkanDeviceInfoExtensions::readPhysicalProperties_HUAWEI() {
	VkPhysicalDeviceProperties2 deviceProps2{};
	if (extensionSupported("VK_HUAWEI_subpass_shading")) {
		const char* extension("VK_HUAWEI_subpass_shading");
		VkPhysicalDeviceSubpassShadingPropertiesHUAWEI* extProps = new VkPhysicalDeviceSubpassShadingPropertiesHUAWEI{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_SHADING_PROPERTIES_HUAWEI;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_HUAWEI_subpass_shading" }, { "name", "maxSubpassShadingWorkgroupSizeAspectRatio" }, { "value", extProps->maxSubpassShadingWorkgroupSizeAspectRatio } });
		delete extProps;
	}
}
void VulkanDeviceInfoExtensions::readPhysicalProperties_KHR() {
	VkPhysicalDeviceProperties2 deviceProps2{};
	if (extensionSupported("VK_KHR_multiview")) {
		const char* extension("VK_KHR_multiview");
		VkPhysicalDeviceMultiviewProperties* extProps = new VkPhysicalDeviceMultiviewProperties{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_KHR_multiview" }, { "name", "maxMultiviewViewCount" }, { "value", extProps->maxMultiviewViewCount } });
		pushProperty2(extension, { { "extension", "VK_KHR_multiview" }, { "name", "maxMultiviewInstanceIndex" }, { "value", extProps->maxMultiviewInstanceIndex } });
		delete extProps;
	}
	if (extensionSupported("VK_KHR_external_memory_capabilities")) {
		const char* extension("VK_KHR_external_memory_capabilities");
		VkPhysicalDeviceIDProperties* extProps = new VkPhysicalDeviceIDProperties{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_KHR_external_memory_capabilities" }, { "name", "deviceUUID" }, { "value", extProps->deviceUUID } });
		pushProperty2(extension, { { "extension", "VK_KHR_external_memory_capabilities" }, { "name", "driverUUID" }, { "value", extProps->driverUUID } });
		pushProperty2(extension, { { "extension", "VK_KHR_external_memory_capabilities" }, { "name", "deviceLUID" }, { "value", extProps->deviceLUID } });
		pushProperty2(extension, { { "extension", "VK_KHR_external_memory_capabilities" }, { "name", "deviceNodeMask" }, { "value", extProps->deviceNodeMask } });
		pushProperty2(extension, { { "extension", "VK_KHR_external_memory_capabilities" }, { "name", "deviceLUIDValid" }, { "value", extProps->deviceLUIDValid ? "true" : "false" } });
		delete extProps;
	}
	if (extensionSupported("VK_KHR_external_semaphore_capabilities")) {
		const char* extension("VK_KHR_external_semaphore_capabilities");
		VkPhysicalDeviceIDProperties* extProps = new VkPhysicalDeviceIDProperties{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_KHR_external_semaphore_capabilities" }, { "name", "deviceUUID" }, { "value", extProps->deviceUUID } });
		pushProperty2(extension, { { "extension", "VK_KHR_external_semaphore_capabilities" }, { "name", "driverUUID" }, { "value", extProps->driverUUID } });
		pushProperty2(extension, { { "extension", "VK_KHR_external_semaphore_capabilities" }, { "name", "deviceLUID" }, { "value", extProps->deviceLUID } });
		pushProperty2(extension, { { "extension", "VK_KHR_external_semaphore_capabilities" }, { "name", "deviceNodeMask" }, { "value", extProps->deviceNodeMask } });
		pushProperty2(extension, { { "extension", "VK_KHR_external_semaphore_capabilities" }, { "name", "deviceLUIDValid" }, { "value", extProps->deviceLUIDValid ? "true" : "false" } });
		delete extProps;
	}
	if (extensionSupported("VK_KHR_push_descriptor")) {
		const char* extension("VK_KHR_push_descriptor");
		VkPhysicalDevicePushDescriptorPropertiesKHR* extProps = new VkPhysicalDevicePushDescriptorPropertiesKHR{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_KHR_push_descriptor" }, { "name", "maxPushDescriptors" }, { "value", extProps->maxPushDescriptors } });
		delete extProps;
	}
	if (extensionSupported("VK_KHR_external_fence_capabilities")) {
		const char* extension("VK_KHR_external_fence_capabilities");
		VkPhysicalDeviceIDProperties* extProps = new VkPhysicalDeviceIDProperties{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_KHR_external_fence_capabilities" }, { "name", "deviceUUID" }, { "value", extProps->deviceUUID } });
		pushProperty2(extension, { { "extension", "VK_KHR_external_fence_capabilities" }, { "name", "driverUUID" }, { "value", extProps->driverUUID } });
		pushProperty2(extension, { { "extension", "VK_KHR_external_fence_capabilities" }, { "name", "deviceLUID" }, { "value", extProps->deviceLUID } });
		pushProperty2(extension, { { "extension", "VK_KHR_external_fence_capabilities" }, { "name", "deviceNodeMask" }, { "value", extProps->deviceNodeMask } });
		pushProperty2(extension, { { "extension", "VK_KHR_external_fence_capabilities" }, { "name", "deviceLUIDValid" }, { "value", extProps->deviceLUIDValid ? "true" : "false" } });
		delete extProps;
	}
	if (extensionSupported("VK_KHR_performance_query")) {
		const char* extension("VK_KHR_performance_query");
		VkPhysicalDevicePerformanceQueryPropertiesKHR* extProps = new VkPhysicalDevicePerformanceQueryPropertiesKHR{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_KHR_performance_query" }, { "name", "allowCommandBufferQueryCopies" }, { "value", extProps->allowCommandBufferQueryCopies ? "true" : "false" } });
		delete extProps;
	}
	if (extensionSupported("VK_KHR_maintenance2")) {
		const char* extension("VK_KHR_maintenance2");
		VkPhysicalDevicePointClippingProperties* extProps = new VkPhysicalDevicePointClippingProperties{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_KHR_maintenance2" }, { "name", "pointClippingBehavior" }, { "value", extProps->pointClippingBehavior } });
		delete extProps;
	}
	if (extensionSupported("VK_KHR_acceleration_structure")) {
		const char* extension("VK_KHR_acceleration_structure");
		VkPhysicalDeviceAccelerationStructurePropertiesKHR* extProps = new VkPhysicalDeviceAccelerationStructurePropertiesKHR{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_PROPERTIES_KHR;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_KHR_acceleration_structure" }, { "name", "maxGeometryCount" }, { "value", extProps->maxGeometryCount } });
		pushProperty2(extension, { { "extension", "VK_KHR_acceleration_structure" }, { "name", "maxInstanceCount" }, { "value", extProps->maxInstanceCount } });
		pushProperty2(extension, { { "extension", "VK_KHR_acceleration_structure" }, { "name", "maxPrimitiveCount" }, { "value", extProps->maxPrimitiveCount } });
		pushProperty2(extension, { { "extension", "VK_KHR_acceleration_structure" }, { "name", "maxPerStageDescriptorAccelerationStructures" }, { "value", extProps->maxPerStageDescriptorAccelerationStructures } });
		pushProperty2(extension, { { "extension", "VK_KHR_acceleration_structure" }, { "name", "maxPerStageDescriptorUpdateAfterBindAccelerationStructures" }, { "value", extProps->maxPerStageDescriptorUpdateAfterBindAccelerationStructures } });
		pushProperty2(extension, { { "extension", "VK_KHR_acceleration_structure" }, { "name", "maxDescriptorSetAccelerationStructures" }, { "value", extProps->maxDescriptorSetAccelerationStructures } });
		pushProperty2(extension, { { "extension", "VK_KHR_acceleration_structure" }, { "name", "maxDescriptorSetUpdateAfterBindAccelerationStructures" }, { "value", extProps->maxDescriptorSetUpdateAfterBindAccelerationStructures } });
		pushProperty2(extension, { { "extension", "VK_KHR_acceleration_structure" }, { "name", "minAccelerationStructureScratchOffsetAlignment" }, { "value", extProps->minAccelerationStructureScratchOffsetAlignment } });
		delete extProps;
	}
	if (extensionSupported("VK_KHR_ray_tracing_pipeline")) {
		const char* extension("VK_KHR_ray_tracing_pipeline");
		VkPhysicalDeviceRayTracingPipelinePropertiesKHR* extProps = new VkPhysicalDeviceRayTracingPipelinePropertiesKHR{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_PROPERTIES_KHR;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_KHR_ray_tracing_pipeline" }, { "name", "shaderGroupHandleSize" }, { "value", extProps->shaderGroupHandleSize } });
		pushProperty2(extension, { { "extension", "VK_KHR_ray_tracing_pipeline" }, { "name", "maxRayRecursionDepth" }, { "value", extProps->maxRayRecursionDepth } });
		pushProperty2(extension, { { "extension", "VK_KHR_ray_tracing_pipeline" }, { "name", "maxShaderGroupStride" }, { "value", extProps->maxShaderGroupStride } });
		pushProperty2(extension, { { "extension", "VK_KHR_ray_tracing_pipeline" }, { "name", "shaderGroupBaseAlignment" }, { "value", extProps->shaderGroupBaseAlignment } });
		pushProperty2(extension, { { "extension", "VK_KHR_ray_tracing_pipeline" }, { "name", "shaderGroupHandleCaptureReplaySize" }, { "value", extProps->shaderGroupHandleCaptureReplaySize } });
		pushProperty2(extension, { { "extension", "VK_KHR_ray_tracing_pipeline" }, { "name", "maxRayDispatchInvocationCount" }, { "value", extProps->maxRayDispatchInvocationCount } });
		pushProperty2(extension, { { "extension", "VK_KHR_ray_tracing_pipeline" }, { "name", "shaderGroupHandleAlignment" }, { "value", extProps->shaderGroupHandleAlignment } });
		pushProperty2(extension, { { "extension", "VK_KHR_ray_tracing_pipeline" }, { "name", "maxRayHitAttributeSize" }, { "value", extProps->maxRayHitAttributeSize } });
		delete extProps;
	}
	if (extensionSupported("VK_KHR_portability_subset")) {
		const char* extension("VK_KHR_portability_subset");
		VkPhysicalDevicePortabilitySubsetPropertiesKHR* extProps = new VkPhysicalDevicePortabilitySubsetPropertiesKHR{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_PROPERTIES_KHR;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_KHR_portability_subset" }, { "name", "minVertexInputBindingStrideAlignment" }, { "value", extProps->minVertexInputBindingStrideAlignment } });
		delete extProps;
	}
	if (extensionSupported("VK_KHR_maintenance3")) {
		const char* extension("VK_KHR_maintenance3");
		VkPhysicalDeviceMaintenance3Properties* extProps = new VkPhysicalDeviceMaintenance3Properties{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_KHR_maintenance3" }, { "name", "maxPerSetDescriptors" }, { "value", extProps->maxPerSetDescriptors } });
		pushProperty2(extension, { { "extension", "VK_KHR_maintenance3" }, { "name", "maxMemoryAllocationSize" }, { "value", extProps->maxMemoryAllocationSize } });
		delete extProps;
	}
	if (extensionSupported("VK_KHR_driver_properties")) {
		const char* extension("VK_KHR_driver_properties");
		VkPhysicalDeviceDriverProperties* extProps = new VkPhysicalDeviceDriverProperties{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_KHR_driver_properties" }, { "name", "driverID" }, { "value", extProps->driverID } });
		pushProperty2(extension, { { "extension", "VK_KHR_driver_properties" }, { "name", "driverName" }, { "value", extProps->driverName } });
		pushProperty2(extension, { { "extension", "VK_KHR_driver_properties" }, { "name", "driverInfo" }, { "value", extProps->driverInfo } });
		pushProperty2(extension, { { "extension", "VK_KHR_driver_properties" }, { "name", "conformanceVersion" }, { "value", Utils::conformanceVersionKHRString(extProps->conformanceVersion) } });
		delete extProps;
	}
	if (extensionSupported("VK_KHR_shader_float_controls")) {
		const char* extension("VK_KHR_shader_float_controls");
		VkPhysicalDeviceFloatControlsProperties* extProps = new VkPhysicalDeviceFloatControlsProperties{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_KHR_shader_float_controls" }, { "name", "denormBehaviorIndependence" }, { "value", extProps->denormBehaviorIndependence } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_float_controls" }, { "name", "roundingModeIndependence" }, { "value", extProps->roundingModeIndependence } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_float_controls" }, { "name", "shaderSignedZeroInfNanPreserveFloat16" }, { "value", extProps->shaderSignedZeroInfNanPreserveFloat16 ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_float_controls" }, { "name", "shaderSignedZeroInfNanPreserveFloat32" }, { "value", extProps->shaderSignedZeroInfNanPreserveFloat32 ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_float_controls" }, { "name", "shaderSignedZeroInfNanPreserveFloat64" }, { "value", extProps->shaderSignedZeroInfNanPreserveFloat64 ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_float_controls" }, { "name", "shaderDenormPreserveFloat16" }, { "value", extProps->shaderDenormPreserveFloat16 ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_float_controls" }, { "name", "shaderDenormPreserveFloat32" }, { "value", extProps->shaderDenormPreserveFloat32 ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_float_controls" }, { "name", "shaderDenormPreserveFloat64" }, { "value", extProps->shaderDenormPreserveFloat64 ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_float_controls" }, { "name", "shaderDenormFlushToZeroFloat16" }, { "value", extProps->shaderDenormFlushToZeroFloat16 ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_float_controls" }, { "name", "shaderDenormFlushToZeroFloat32" }, { "value", extProps->shaderDenormFlushToZeroFloat32 ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_float_controls" }, { "name", "shaderDenormFlushToZeroFloat64" }, { "value", extProps->shaderDenormFlushToZeroFloat64 ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_float_controls" }, { "name", "shaderRoundingModeRTEFloat16" }, { "value", extProps->shaderRoundingModeRTEFloat16 ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_float_controls" }, { "name", "shaderRoundingModeRTEFloat32" }, { "value", extProps->shaderRoundingModeRTEFloat32 ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_float_controls" }, { "name", "shaderRoundingModeRTEFloat64" }, { "value", extProps->shaderRoundingModeRTEFloat64 ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_float_controls" }, { "name", "shaderRoundingModeRTZFloat16" }, { "value", extProps->shaderRoundingModeRTZFloat16 ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_float_controls" }, { "name", "shaderRoundingModeRTZFloat32" }, { "value", extProps->shaderRoundingModeRTZFloat32 ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_float_controls" }, { "name", "shaderRoundingModeRTZFloat64" }, { "value", extProps->shaderRoundingModeRTZFloat64 ? "true" : "false" } });
		delete extProps;
	}
	if (extensionSupported("VK_KHR_depth_stencil_resolve")) {
		const char* extension("VK_KHR_depth_stencil_resolve");
		VkPhysicalDeviceDepthStencilResolveProperties* extProps = new VkPhysicalDeviceDepthStencilResolveProperties{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_KHR_depth_stencil_resolve" }, { "name", "supportedDepthResolveModes" }, { "value", extProps->supportedDepthResolveModes } });
		pushProperty2(extension, { { "extension", "VK_KHR_depth_stencil_resolve" }, { "name", "supportedStencilResolveModes" }, { "value", extProps->supportedStencilResolveModes } });
		pushProperty2(extension, { { "extension", "VK_KHR_depth_stencil_resolve" }, { "name", "independentResolveNone" }, { "value", extProps->independentResolveNone ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_depth_stencil_resolve" }, { "name", "independentResolve" }, { "value", extProps->independentResolve ? "true" : "false" } });
		delete extProps;
	}
	if (extensionSupported("VK_KHR_timeline_semaphore")) {
		const char* extension("VK_KHR_timeline_semaphore");
		VkPhysicalDeviceTimelineSemaphoreProperties* extProps = new VkPhysicalDeviceTimelineSemaphoreProperties{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_KHR_timeline_semaphore" }, { "name", "maxTimelineSemaphoreValueDifference" }, { "value", extProps->maxTimelineSemaphoreValueDifference } });
		delete extProps;
	}
	if (extensionSupported("VK_KHR_fragment_shading_rate")) {
		const char* extension("VK_KHR_fragment_shading_rate");
		VkPhysicalDeviceFragmentShadingRatePropertiesKHR* extProps = new VkPhysicalDeviceFragmentShadingRatePropertiesKHR{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_KHR_fragment_shading_rate" }, { "name", "minFragmentShadingRateAttachmentTexelSize" }, { "value", { extProps->minFragmentShadingRateAttachmentTexelSize.width, extProps->minFragmentShadingRateAttachmentTexelSize.height } } });
		pushProperty2(extension, { { "extension", "VK_KHR_fragment_shading_rate" }, { "name", "maxFragmentShadingRateAttachmentTexelSize" }, { "value", { extProps->maxFragmentShadingRateAttachmentTexelSize.width, extProps->maxFragmentShadingRateAttachmentTexelSize.height } } });
		pushProperty2(extension, { { "extension", "VK_KHR_fragment_shading_rate" }, { "name", "maxFragmentShadingRateAttachmentTexelSizeAspectRatio" }, { "value", extProps->maxFragmentShadingRateAttachmentTexelSizeAspectRatio } });
		pushProperty2(extension, { { "extension", "VK_KHR_fragment_shading_rate" }, { "name", "primitiveFragmentShadingRateWithMultipleViewports" }, { "value", extProps->primitiveFragmentShadingRateWithMultipleViewports ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_fragment_shading_rate" }, { "name", "layeredShadingRateAttachments" }, { "value", extProps->layeredShadingRateAttachments ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_fragment_shading_rate" }, { "name", "fragmentShadingRateNonTrivialCombinerOps" }, { "value", extProps->fragmentShadingRateNonTrivialCombinerOps ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_fragment_shading_rate" }, { "name", "maxFragmentSize" }, { "value", { extProps->maxFragmentSize.width, extProps->maxFragmentSize.height } } });
		pushProperty2(extension, { { "extension", "VK_KHR_fragment_shading_rate" }, { "name", "maxFragmentSizeAspectRatio" }, { "value", extProps->maxFragmentSizeAspectRatio } });
		pushProperty2(extension, { { "extension", "VK_KHR_fragment_shading_rate" }, { "name", "maxFragmentShadingRateCoverageSamples" }, { "value", extProps->maxFragmentShadingRateCoverageSamples } });
		pushProperty2(extension, { { "extension", "VK_KHR_fragment_shading_rate" }, { "name", "maxFragmentShadingRateRasterizationSamples" }, { "value", extProps->maxFragmentShadingRateRasterizationSamples } });
		pushProperty2(extension, { { "extension", "VK_KHR_fragment_shading_rate" }, { "name", "fragmentShadingRateWithShaderDepthStencilWrites" }, { "value", extProps->fragmentShadingRateWithShaderDepthStencilWrites ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_fragment_shading_rate" }, { "name", "fragmentShadingRateWithSampleMask" }, { "value", extProps->fragmentShadingRateWithSampleMask ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_fragment_shading_rate" }, { "name", "fragmentShadingRateWithShaderSampleMask" }, { "value", extProps->fragmentShadingRateWithShaderSampleMask ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_fragment_shading_rate" }, { "name", "fragmentShadingRateWithConservativeRasterization" }, { "value", extProps->fragmentShadingRateWithConservativeRasterization ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_fragment_shading_rate" }, { "name", "fragmentShadingRateWithFragmentShaderInterlock" }, { "value", extProps->fragmentShadingRateWithFragmentShaderInterlock ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_fragment_shading_rate" }, { "name", "fragmentShadingRateWithCustomSampleLocations" }, { "value", extProps->fragmentShadingRateWithCustomSampleLocations ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_fragment_shading_rate" }, { "name", "fragmentShadingRateStrictMultiplyCombiner" }, { "value", extProps->fragmentShadingRateStrictMultiplyCombiner ? "true" : "false" } });
		delete extProps;
	}
	if (extensionSupported("VK_KHR_shader_integer_dot_product")) {
		const char* extension("VK_KHR_shader_integer_dot_product");
		VkPhysicalDeviceShaderIntegerDotProductProperties* extProps = new VkPhysicalDeviceShaderIntegerDotProductProperties{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProduct8BitUnsignedAccelerated" }, { "value", extProps->integerDotProduct8BitUnsignedAccelerated ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProduct8BitSignedAccelerated" }, { "value", extProps->integerDotProduct8BitSignedAccelerated ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProduct8BitMixedSignednessAccelerated" }, { "value", extProps->integerDotProduct8BitMixedSignednessAccelerated ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProduct4x8BitPackedUnsignedAccelerated" }, { "value", extProps->integerDotProduct4x8BitPackedUnsignedAccelerated ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProduct4x8BitPackedSignedAccelerated" }, { "value", extProps->integerDotProduct4x8BitPackedSignedAccelerated ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProduct4x8BitPackedMixedSignednessAccelerated" }, { "value", extProps->integerDotProduct4x8BitPackedMixedSignednessAccelerated ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProduct16BitUnsignedAccelerated" }, { "value", extProps->integerDotProduct16BitUnsignedAccelerated ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProduct16BitSignedAccelerated" }, { "value", extProps->integerDotProduct16BitSignedAccelerated ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProduct16BitMixedSignednessAccelerated" }, { "value", extProps->integerDotProduct16BitMixedSignednessAccelerated ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProduct32BitUnsignedAccelerated" }, { "value", extProps->integerDotProduct32BitUnsignedAccelerated ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProduct32BitSignedAccelerated" }, { "value", extProps->integerDotProduct32BitSignedAccelerated ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProduct32BitMixedSignednessAccelerated" }, { "value", extProps->integerDotProduct32BitMixedSignednessAccelerated ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProduct64BitUnsignedAccelerated" }, { "value", extProps->integerDotProduct64BitUnsignedAccelerated ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProduct64BitSignedAccelerated" }, { "value", extProps->integerDotProduct64BitSignedAccelerated ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProduct64BitMixedSignednessAccelerated" }, { "value", extProps->integerDotProduct64BitMixedSignednessAccelerated ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProductAccumulatingSaturating8BitUnsignedAccelerated" }, { "value", extProps->integerDotProductAccumulatingSaturating8BitUnsignedAccelerated ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProductAccumulatingSaturating8BitSignedAccelerated" }, { "value", extProps->integerDotProductAccumulatingSaturating8BitSignedAccelerated ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated" }, { "value", extProps->integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated" }, { "value", extProps->integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated" }, { "value", extProps->integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated" }, { "value", extProps->integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProductAccumulatingSaturating16BitUnsignedAccelerated" }, { "value", extProps->integerDotProductAccumulatingSaturating16BitUnsignedAccelerated ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProductAccumulatingSaturating16BitSignedAccelerated" }, { "value", extProps->integerDotProductAccumulatingSaturating16BitSignedAccelerated ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated" }, { "value", extProps->integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProductAccumulatingSaturating32BitUnsignedAccelerated" }, { "value", extProps->integerDotProductAccumulatingSaturating32BitUnsignedAccelerated ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProductAccumulatingSaturating32BitSignedAccelerated" }, { "value", extProps->integerDotProductAccumulatingSaturating32BitSignedAccelerated ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated" }, { "value", extProps->integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProductAccumulatingSaturating64BitUnsignedAccelerated" }, { "value", extProps->integerDotProductAccumulatingSaturating64BitUnsignedAccelerated ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProductAccumulatingSaturating64BitSignedAccelerated" }, { "value", extProps->integerDotProductAccumulatingSaturating64BitSignedAccelerated ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_KHR_shader_integer_dot_product" }, { "name", "integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated" }, { "value", extProps->integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated ? "true" : "false" } });
		delete extProps;
	}
	if (extensionSupported("VK_KHR_fragment_shader_barycentric")) {
		const char* extension("VK_KHR_fragment_shader_barycentric");
		VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR* extProps = new VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_PROPERTIES_KHR;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_KHR_fragment_shader_barycentric" }, { "name", "triStripVertexOrderIndependentOfProvokingVertex" }, { "value", extProps->triStripVertexOrderIndependentOfProvokingVertex ? "true" : "false" } });
		delete extProps;
	}
	if (extensionSupported("VK_KHR_maintenance4")) {
		const char* extension("VK_KHR_maintenance4");
		VkPhysicalDeviceMaintenance4Properties* extProps = new VkPhysicalDeviceMaintenance4Properties{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_KHR_maintenance4" }, { "name", "maxBufferSize" }, { "value", extProps->maxBufferSize } });
		delete extProps;
	}
}
void VulkanDeviceInfoExtensions::readPhysicalProperties_NV() {
	VkPhysicalDeviceProperties2 deviceProps2{};
	if (extensionSupported("VK_NV_shader_sm_builtins")) {
		const char* extension("VK_NV_shader_sm_builtins");
		VkPhysicalDeviceShaderSMBuiltinsPropertiesNV* extProps = new VkPhysicalDeviceShaderSMBuiltinsPropertiesNV{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_NV_shader_sm_builtins" }, { "name", "shaderSMCount" }, { "value", extProps->shaderSMCount } });
		pushProperty2(extension, { { "extension", "VK_NV_shader_sm_builtins" }, { "name", "shaderWarpsPerSM" }, { "value", extProps->shaderWarpsPerSM } });
		delete extProps;
	}
	if (extensionSupported("VK_NV_shading_rate_image")) {
		const char* extension("VK_NV_shading_rate_image");
		VkPhysicalDeviceShadingRateImagePropertiesNV* extProps = new VkPhysicalDeviceShadingRateImagePropertiesNV{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_NV_shading_rate_image" }, { "name", "shadingRateTexelSize" }, { "value", { extProps->shadingRateTexelSize.width, extProps->shadingRateTexelSize.height } } });
		pushProperty2(extension, { { "extension", "VK_NV_shading_rate_image" }, { "name", "shadingRatePaletteSize" }, { "value", extProps->shadingRatePaletteSize } });
		pushProperty2(extension, { { "extension", "VK_NV_shading_rate_image" }, { "name", "shadingRateMaxCoarseSamples" }, { "value", extProps->shadingRateMaxCoarseSamples } });
		delete extProps;
	}
	if (extensionSupported("VK_NV_ray_tracing")) {
		const char* extension("VK_NV_ray_tracing");
		VkPhysicalDeviceRayTracingPropertiesNV* extProps = new VkPhysicalDeviceRayTracingPropertiesNV{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_NV_ray_tracing" }, { "name", "shaderGroupHandleSize" }, { "value", extProps->shaderGroupHandleSize } });
		pushProperty2(extension, { { "extension", "VK_NV_ray_tracing" }, { "name", "maxRecursionDepth" }, { "value", extProps->maxRecursionDepth } });
		pushProperty2(extension, { { "extension", "VK_NV_ray_tracing" }, { "name", "maxShaderGroupStride" }, { "value", extProps->maxShaderGroupStride } });
		pushProperty2(extension, { { "extension", "VK_NV_ray_tracing" }, { "name", "shaderGroupBaseAlignment" }, { "value", extProps->shaderGroupBaseAlignment } });
		pushProperty2(extension, { { "extension", "VK_NV_ray_tracing" }, { "name", "maxGeometryCount" }, { "value", extProps->maxGeometryCount } });
		pushProperty2(extension, { { "extension", "VK_NV_ray_tracing" }, { "name", "maxInstanceCount" }, { "value", extProps->maxInstanceCount } });
		pushProperty2(extension, { { "extension", "VK_NV_ray_tracing" }, { "name", "maxTriangleCount" }, { "value", extProps->maxTriangleCount } });
		pushProperty2(extension, { { "extension", "VK_NV_ray_tracing" }, { "name", "maxDescriptorSetAccelerationStructures" }, { "value", extProps->maxDescriptorSetAccelerationStructures } });
		delete extProps;
	}
	if (extensionSupported("VK_NV_mesh_shader")) {
		const char* extension("VK_NV_mesh_shader");
		VkPhysicalDeviceMeshShaderPropertiesNV* extProps = new VkPhysicalDeviceMeshShaderPropertiesNV{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_NV_mesh_shader" }, { "name", "maxDrawMeshTasksCount" }, { "value", extProps->maxDrawMeshTasksCount } });
		pushProperty2(extension, { { "extension", "VK_NV_mesh_shader" }, { "name", "maxTaskWorkGroupInvocations" }, { "value", extProps->maxTaskWorkGroupInvocations } });
		pushProperty2(extension, { { "extension", "VK_NV_mesh_shader" }, { "name", "maxTaskWorkGroupSize" }, { "value", extProps->maxTaskWorkGroupSize } });
		pushProperty2(extension, { { "extension", "VK_NV_mesh_shader" }, { "name", "maxTaskTotalMemorySize" }, { "value", extProps->maxTaskTotalMemorySize } });
		pushProperty2(extension, { { "extension", "VK_NV_mesh_shader" }, { "name", "maxTaskOutputCount" }, { "value", extProps->maxTaskOutputCount } });
		pushProperty2(extension, { { "extension", "VK_NV_mesh_shader" }, { "name", "maxMeshWorkGroupInvocations" }, { "value", extProps->maxMeshWorkGroupInvocations } });
		pushProperty2(extension, { { "extension", "VK_NV_mesh_shader" }, { "name", "maxMeshWorkGroupSize" }, { "value", extProps->maxMeshWorkGroupSize } });
		pushProperty2(extension, { { "extension", "VK_NV_mesh_shader" }, { "name", "maxMeshTotalMemorySize" }, { "value", extProps->maxMeshTotalMemorySize } });
		pushProperty2(extension, { { "extension", "VK_NV_mesh_shader" }, { "name", "maxMeshOutputVertices" }, { "value", extProps->maxMeshOutputVertices } });
		pushProperty2(extension, { { "extension", "VK_NV_mesh_shader" }, { "name", "maxMeshOutputPrimitives" }, { "value", extProps->maxMeshOutputPrimitives } });
		pushProperty2(extension, { { "extension", "VK_NV_mesh_shader" }, { "name", "maxMeshMultiviewViewCount" }, { "value", extProps->maxMeshMultiviewViewCount } });
		pushProperty2(extension, { { "extension", "VK_NV_mesh_shader" }, { "name", "meshOutputPerVertexGranularity" }, { "value", extProps->meshOutputPerVertexGranularity } });
		pushProperty2(extension, { { "extension", "VK_NV_mesh_shader" }, { "name", "meshOutputPerPrimitiveGranularity" }, { "value", extProps->meshOutputPerPrimitiveGranularity } });
		delete extProps;
	}
	if (extensionSupported("VK_NV_cooperative_matrix")) {
		const char* extension("VK_NV_cooperative_matrix");
		VkPhysicalDeviceCooperativeMatrixPropertiesNV* extProps = new VkPhysicalDeviceCooperativeMatrixPropertiesNV{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_NV_cooperative_matrix" }, { "name", "cooperativeMatrixSupportedStages" }, { "value", extProps->cooperativeMatrixSupportedStages } });
		delete extProps;
	}
	if (extensionSupported("VK_NV_device_generated_commands")) {
		const char* extension("VK_NV_device_generated_commands");
		VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV* extProps = new VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_NV;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_NV_device_generated_commands" }, { "name", "maxGraphicsShaderGroupCount" }, { "value", extProps->maxGraphicsShaderGroupCount } });
		pushProperty2(extension, { { "extension", "VK_NV_device_generated_commands" }, { "name", "maxIndirectSequenceCount" }, { "value", extProps->maxIndirectSequenceCount } });
		pushProperty2(extension, { { "extension", "VK_NV_device_generated_commands" }, { "name", "maxIndirectCommandsTokenCount" }, { "value", extProps->maxIndirectCommandsTokenCount } });
		pushProperty2(extension, { { "extension", "VK_NV_device_generated_commands" }, { "name", "maxIndirectCommandsStreamCount" }, { "value", extProps->maxIndirectCommandsStreamCount } });
		pushProperty2(extension, { { "extension", "VK_NV_device_generated_commands" }, { "name", "maxIndirectCommandsTokenOffset" }, { "value", extProps->maxIndirectCommandsTokenOffset } });
		pushProperty2(extension, { { "extension", "VK_NV_device_generated_commands" }, { "name", "maxIndirectCommandsStreamStride" }, { "value", extProps->maxIndirectCommandsStreamStride } });
		pushProperty2(extension, { { "extension", "VK_NV_device_generated_commands" }, { "name", "minSequencesCountBufferOffsetAlignment" }, { "value", extProps->minSequencesCountBufferOffsetAlignment } });
		pushProperty2(extension, { { "extension", "VK_NV_device_generated_commands" }, { "name", "minSequencesIndexBufferOffsetAlignment" }, { "value", extProps->minSequencesIndexBufferOffsetAlignment } });
		pushProperty2(extension, { { "extension", "VK_NV_device_generated_commands" }, { "name", "minIndirectCommandsBufferOffsetAlignment" }, { "value", extProps->minIndirectCommandsBufferOffsetAlignment } });
		delete extProps;
	}
	if (extensionSupported("VK_NV_fragment_shading_rate_enums")) {
		const char* extension("VK_NV_fragment_shading_rate_enums");
		VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV* extProps = new VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_PROPERTIES_NV;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_NV_fragment_shading_rate_enums" }, { "name", "maxFragmentShadingRateInvocationCount" }, { "value", extProps->maxFragmentShadingRateInvocationCount } });
		delete extProps;
	}
	if (extensionSupported("VK_NV_copy_memory_indirect")) {
		const char* extension("VK_NV_copy_memory_indirect");
		VkPhysicalDeviceCopyMemoryIndirectPropertiesNV* extProps = new VkPhysicalDeviceCopyMemoryIndirectPropertiesNV{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_PROPERTIES_NV;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_NV_copy_memory_indirect" }, { "name", "supportedQueues" }, { "value", extProps->supportedQueues } });
		delete extProps;
	}
	if (extensionSupported("VK_NV_memory_decompression")) {
		const char* extension("VK_NV_memory_decompression");
		VkPhysicalDeviceMemoryDecompressionPropertiesNV* extProps = new VkPhysicalDeviceMemoryDecompressionPropertiesNV{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_PROPERTIES_NV;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_NV_memory_decompression" }, { "name", "decompressionMethods" }, { "value", extProps->decompressionMethods } });
		pushProperty2(extension, { { "extension", "VK_NV_memory_decompression" }, { "name", "maxDecompressionIndirectCount" }, { "value", extProps->maxDecompressionIndirectCount } });
		delete extProps;
	}
	if (extensionSupported("VK_NV_optical_flow")) {
		const char* extension("VK_NV_optical_flow");
		VkPhysicalDeviceOpticalFlowPropertiesNV* extProps = new VkPhysicalDeviceOpticalFlowPropertiesNV{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_PROPERTIES_NV;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_NV_optical_flow" }, { "name", "supportedOutputGridSizes" }, { "value", extProps->supportedOutputGridSizes } });
		pushProperty2(extension, { { "extension", "VK_NV_optical_flow" }, { "name", "supportedHintGridSizes" }, { "value", extProps->supportedHintGridSizes } });
		pushProperty2(extension, { { "extension", "VK_NV_optical_flow" }, { "name", "hintSupported" }, { "value", extProps->hintSupported ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_NV_optical_flow" }, { "name", "costSupported" }, { "value", extProps->costSupported ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_NV_optical_flow" }, { "name", "bidirectionalFlowSupported" }, { "value", extProps->bidirectionalFlowSupported ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_NV_optical_flow" }, { "name", "globalFlowSupported" }, { "value", extProps->globalFlowSupported ? "true" : "false" } });
		pushProperty2(extension, { { "extension", "VK_NV_optical_flow" }, { "name", "minWidth" }, { "value", extProps->minWidth } });
		pushProperty2(extension, { { "extension", "VK_NV_optical_flow" }, { "name", "minHeight" }, { "value", extProps->minHeight } });
		pushProperty2(extension, { { "extension", "VK_NV_optical_flow" }, { "name", "maxWidth" }, { "value", extProps->maxWidth } });
		pushProperty2(extension, { { "extension", "VK_NV_optical_flow" }, { "name", "maxHeight" }, { "value", extProps->maxHeight } });
		pushProperty2(extension, { { "extension", "VK_NV_optical_flow" }, { "name", "maxNumRegionsOfInterest" }, { "value", extProps->maxNumRegionsOfInterest } });
		delete extProps;
	}
	if (extensionSupported("VK_NV_ray_tracing_invocation_reorder")) {
		const char* extension("VK_NV_ray_tracing_invocation_reorder");
		VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV* extProps = new VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_PROPERTIES_NV;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_NV_ray_tracing_invocation_reorder" }, { "name", "rayTracingInvocationReorderReorderingHint" }, { "value", extProps->rayTracingInvocationReorderReorderingHint } });
		delete extProps;
	}
}
void VulkanDeviceInfoExtensions::readPhysicalProperties_NVX() {
	VkPhysicalDeviceProperties2 deviceProps2{};
	if (extensionSupported("VK_NVX_multiview_per_view_attributes")) {
		const char* extension("VK_NVX_multiview_per_view_attributes");
		VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX* extProps = new VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_NVX_multiview_per_view_attributes" }, { "name", "perViewPositionAllComponents" }, { "value", extProps->perViewPositionAllComponents ? "true" : "false" } });
		delete extProps;
	}
}
void VulkanDeviceInfoExtensions::readPhysicalProperties_QCOM() {
	VkPhysicalDeviceProperties2 deviceProps2{};
	if (extensionSupported("VK_QCOM_fragment_density_map_offset")) {
		const char* extension("VK_QCOM_fragment_density_map_offset");
		VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM* extProps = new VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_PROPERTIES_QCOM;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_QCOM_fragment_density_map_offset" }, { "name", "fragmentDensityOffsetGranularity" }, { "value", { extProps->fragmentDensityOffsetGranularity.width, extProps->fragmentDensityOffsetGranularity.height } } });
		delete extProps;
	}
	if (extensionSupported("VK_QCOM_image_processing")) {
		const char* extension("VK_QCOM_image_processing");
		VkPhysicalDeviceImageProcessingPropertiesQCOM* extProps = new VkPhysicalDeviceImageProcessingPropertiesQCOM{};
		extProps->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_PROPERTIES_QCOM;
		deviceProps2 = initDeviceProperties2(extProps);
		vulkanContext.vkGetPhysicalDeviceProperties2KHR(handle, &deviceProps2);
		pushProperty2(extension, { { "extension", "VK_QCOM_image_processing" }, { "name", "maxWeightFilterPhases" }, { "value", extProps->maxWeightFilterPhases } });
		pushProperty2(extension, { { "extension", "VK_QCOM_image_processing" }, { "name", "maxWeightFilterDimension" }, { "value", { extProps->maxWeightFilterDimension.width, extProps->maxWeightFilterDimension.height } } });
		pushProperty2(extension, { { "extension", "VK_QCOM_image_processing" }, { "name", "maxBlockMatchRegion" }, { "value", { extProps->maxBlockMatchRegion.width, extProps->maxBlockMatchRegion.height } } });
		pushProperty2(extension, { { "extension", "VK_QCOM_image_processing" }, { "name", "maxBoxFilterBlockSize" }, { "value", { extProps->maxBoxFilterBlockSize.width, extProps->maxBoxFilterBlockSize.height } } });
		delete extProps;
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
	VkPhysicalDeviceFeatures2 deviceFeatures2{};
	if (extensionSupported("VK_AMD_device_coherent_memory")) {
		const char* extension("VK_AMD_device_coherent_memory");
		VkPhysicalDeviceCoherentMemoryFeaturesAMD* extFeatures = new VkPhysicalDeviceCoherentMemoryFeaturesAMD{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "deviceCoherentMemory", extFeatures->deviceCoherentMemory);
		delete extFeatures;
	}
	if (extensionSupported("VK_AMD_shader_early_and_late_fragment_tests")) {
		const char* extension("VK_AMD_shader_early_and_late_fragment_tests");
		VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD* extFeatures = new VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_FEATURES_AMD;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "shaderEarlyAndLateFragmentTests", extFeatures->shaderEarlyAndLateFragmentTests);
		delete extFeatures;
	}
}
void VulkanDeviceInfoExtensions::readPhysicalFeatures_ARM() {
	VkPhysicalDeviceFeatures2 deviceFeatures2{};
	if (extensionSupported("VK_ARM_rasterization_order_attachment_access")) {
		const char* extension("VK_ARM_rasterization_order_attachment_access");
		VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT* extFeatures = new VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "rasterizationOrderColorAttachmentAccess", extFeatures->rasterizationOrderColorAttachmentAccess);
		pushFeature2(extension, "rasterizationOrderDepthAttachmentAccess", extFeatures->rasterizationOrderDepthAttachmentAccess);
		pushFeature2(extension, "rasterizationOrderStencilAttachmentAccess", extFeatures->rasterizationOrderStencilAttachmentAccess);
		delete extFeatures;
	}
	if (extensionSupported("VK_ARM_shader_core_builtins")) {
		const char* extension("VK_ARM_shader_core_builtins");
		VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM* extFeatures = new VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_FEATURES_ARM;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "shaderCoreBuiltins", extFeatures->shaderCoreBuiltins);
		delete extFeatures;
	}
}
void VulkanDeviceInfoExtensions::readPhysicalFeatures_EXT() {
	VkPhysicalDeviceFeatures2 deviceFeatures2{};
	if (extensionSupported("VK_EXT_transform_feedback")) {
		const char* extension("VK_EXT_transform_feedback");
		VkPhysicalDeviceTransformFeedbackFeaturesEXT* extFeatures = new VkPhysicalDeviceTransformFeedbackFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "transformFeedback", extFeatures->transformFeedback);
		pushFeature2(extension, "geometryStreams", extFeatures->geometryStreams);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_texture_compression_astc_hdr")) {
		const char* extension("VK_EXT_texture_compression_astc_hdr");
		VkPhysicalDeviceTextureCompressionASTCHDRFeatures* extFeatures = new VkPhysicalDeviceTextureCompressionASTCHDRFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "textureCompressionASTC_HDR", extFeatures->textureCompressionASTC_HDR);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_astc_decode_mode")) {
		const char* extension("VK_EXT_astc_decode_mode");
		VkPhysicalDeviceASTCDecodeFeaturesEXT* extFeatures = new VkPhysicalDeviceASTCDecodeFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "decodeModeSharedExponent", extFeatures->decodeModeSharedExponent);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_pipeline_robustness")) {
		const char* extension("VK_EXT_pipeline_robustness");
		VkPhysicalDevicePipelineRobustnessFeaturesEXT* extFeatures = new VkPhysicalDevicePipelineRobustnessFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "pipelineRobustness", extFeatures->pipelineRobustness);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_conditional_rendering")) {
		const char* extension("VK_EXT_conditional_rendering");
		VkPhysicalDeviceConditionalRenderingFeaturesEXT* extFeatures = new VkPhysicalDeviceConditionalRenderingFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "conditionalRendering", extFeatures->conditionalRendering);
		pushFeature2(extension, "inheritedConditionalRendering", extFeatures->inheritedConditionalRendering);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_depth_clip_enable")) {
		const char* extension("VK_EXT_depth_clip_enable");
		VkPhysicalDeviceDepthClipEnableFeaturesEXT* extFeatures = new VkPhysicalDeviceDepthClipEnableFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "depthClipEnable", extFeatures->depthClipEnable);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_inline_uniform_block")) {
		const char* extension("VK_EXT_inline_uniform_block");
		VkPhysicalDeviceInlineUniformBlockFeatures* extFeatures = new VkPhysicalDeviceInlineUniformBlockFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "inlineUniformBlock", extFeatures->inlineUniformBlock);
		pushFeature2(extension, "descriptorBindingInlineUniformBlockUpdateAfterBind", extFeatures->descriptorBindingInlineUniformBlockUpdateAfterBind);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_blend_operation_advanced")) {
		const char* extension("VK_EXT_blend_operation_advanced");
		VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT* extFeatures = new VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "advancedBlendCoherentOperations", extFeatures->advancedBlendCoherentOperations);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_descriptor_indexing")) {
		const char* extension("VK_EXT_descriptor_indexing");
		VkPhysicalDeviceDescriptorIndexingFeatures* extFeatures = new VkPhysicalDeviceDescriptorIndexingFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "shaderInputAttachmentArrayDynamicIndexing", extFeatures->shaderInputAttachmentArrayDynamicIndexing);
		pushFeature2(extension, "shaderUniformTexelBufferArrayDynamicIndexing", extFeatures->shaderUniformTexelBufferArrayDynamicIndexing);
		pushFeature2(extension, "shaderStorageTexelBufferArrayDynamicIndexing", extFeatures->shaderStorageTexelBufferArrayDynamicIndexing);
		pushFeature2(extension, "shaderUniformBufferArrayNonUniformIndexing", extFeatures->shaderUniformBufferArrayNonUniformIndexing);
		pushFeature2(extension, "shaderSampledImageArrayNonUniformIndexing", extFeatures->shaderSampledImageArrayNonUniformIndexing);
		pushFeature2(extension, "shaderStorageBufferArrayNonUniformIndexing", extFeatures->shaderStorageBufferArrayNonUniformIndexing);
		pushFeature2(extension, "shaderStorageImageArrayNonUniformIndexing", extFeatures->shaderStorageImageArrayNonUniformIndexing);
		pushFeature2(extension, "shaderInputAttachmentArrayNonUniformIndexing", extFeatures->shaderInputAttachmentArrayNonUniformIndexing);
		pushFeature2(extension, "shaderUniformTexelBufferArrayNonUniformIndexing", extFeatures->shaderUniformTexelBufferArrayNonUniformIndexing);
		pushFeature2(extension, "shaderStorageTexelBufferArrayNonUniformIndexing", extFeatures->shaderStorageTexelBufferArrayNonUniformIndexing);
		pushFeature2(extension, "descriptorBindingUniformBufferUpdateAfterBind", extFeatures->descriptorBindingUniformBufferUpdateAfterBind);
		pushFeature2(extension, "descriptorBindingSampledImageUpdateAfterBind", extFeatures->descriptorBindingSampledImageUpdateAfterBind);
		pushFeature2(extension, "descriptorBindingStorageImageUpdateAfterBind", extFeatures->descriptorBindingStorageImageUpdateAfterBind);
		pushFeature2(extension, "descriptorBindingStorageBufferUpdateAfterBind", extFeatures->descriptorBindingStorageBufferUpdateAfterBind);
		pushFeature2(extension, "descriptorBindingUniformTexelBufferUpdateAfterBind", extFeatures->descriptorBindingUniformTexelBufferUpdateAfterBind);
		pushFeature2(extension, "descriptorBindingStorageTexelBufferUpdateAfterBind", extFeatures->descriptorBindingStorageTexelBufferUpdateAfterBind);
		pushFeature2(extension, "descriptorBindingUpdateUnusedWhilePending", extFeatures->descriptorBindingUpdateUnusedWhilePending);
		pushFeature2(extension, "descriptorBindingPartiallyBound", extFeatures->descriptorBindingPartiallyBound);
		pushFeature2(extension, "descriptorBindingVariableDescriptorCount", extFeatures->descriptorBindingVariableDescriptorCount);
		pushFeature2(extension, "runtimeDescriptorArray", extFeatures->runtimeDescriptorArray);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_vertex_attribute_divisor")) {
		const char* extension("VK_EXT_vertex_attribute_divisor");
		VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT* extFeatures = new VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "vertexAttributeInstanceRateDivisor", extFeatures->vertexAttributeInstanceRateDivisor);
		pushFeature2(extension, "vertexAttributeInstanceRateZeroDivisor", extFeatures->vertexAttributeInstanceRateZeroDivisor);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_fragment_density_map")) {
		const char* extension("VK_EXT_fragment_density_map");
		VkPhysicalDeviceFragmentDensityMapFeaturesEXT* extFeatures = new VkPhysicalDeviceFragmentDensityMapFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "fragmentDensityMap", extFeatures->fragmentDensityMap);
		pushFeature2(extension, "fragmentDensityMapDynamic", extFeatures->fragmentDensityMapDynamic);
		pushFeature2(extension, "fragmentDensityMapNonSubsampledImages", extFeatures->fragmentDensityMapNonSubsampledImages);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_scalar_block_layout")) {
		const char* extension("VK_EXT_scalar_block_layout");
		VkPhysicalDeviceScalarBlockLayoutFeatures* extFeatures = new VkPhysicalDeviceScalarBlockLayoutFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "scalarBlockLayout", extFeatures->scalarBlockLayout);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_subgroup_size_control")) {
		const char* extension("VK_EXT_subgroup_size_control");
		VkPhysicalDeviceSubgroupSizeControlFeatures* extFeatures = new VkPhysicalDeviceSubgroupSizeControlFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "subgroupSizeControl", extFeatures->subgroupSizeControl);
		pushFeature2(extension, "computeFullSubgroups", extFeatures->computeFullSubgroups);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_shader_image_atomic_int64")) {
		const char* extension("VK_EXT_shader_image_atomic_int64");
		VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT* extFeatures = new VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "shaderImageInt64Atomics", extFeatures->shaderImageInt64Atomics);
		pushFeature2(extension, "sparseImageInt64Atomics", extFeatures->sparseImageInt64Atomics);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_memory_priority")) {
		const char* extension("VK_EXT_memory_priority");
		VkPhysicalDeviceMemoryPriorityFeaturesEXT* extFeatures = new VkPhysicalDeviceMemoryPriorityFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "memoryPriority", extFeatures->memoryPriority);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_buffer_device_address")) {
		const char* extension("VK_EXT_buffer_device_address");
		VkPhysicalDeviceBufferDeviceAddressFeaturesEXT* extFeatures = new VkPhysicalDeviceBufferDeviceAddressFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "bufferDeviceAddress", extFeatures->bufferDeviceAddress);
		pushFeature2(extension, "bufferDeviceAddressCaptureReplay", extFeatures->bufferDeviceAddressCaptureReplay);
		pushFeature2(extension, "bufferDeviceAddressMultiDevice", extFeatures->bufferDeviceAddressMultiDevice);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_fragment_shader_interlock")) {
		const char* extension("VK_EXT_fragment_shader_interlock");
		VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT* extFeatures = new VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "fragmentShaderSampleInterlock", extFeatures->fragmentShaderSampleInterlock);
		pushFeature2(extension, "fragmentShaderPixelInterlock", extFeatures->fragmentShaderPixelInterlock);
		pushFeature2(extension, "fragmentShaderShadingRateInterlock", extFeatures->fragmentShaderShadingRateInterlock);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_ycbcr_image_arrays")) {
		const char* extension("VK_EXT_ycbcr_image_arrays");
		VkPhysicalDeviceYcbcrImageArraysFeaturesEXT* extFeatures = new VkPhysicalDeviceYcbcrImageArraysFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "ycbcrImageArrays", extFeatures->ycbcrImageArrays);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_provoking_vertex")) {
		const char* extension("VK_EXT_provoking_vertex");
		VkPhysicalDeviceProvokingVertexFeaturesEXT* extFeatures = new VkPhysicalDeviceProvokingVertexFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "provokingVertexLast", extFeatures->provokingVertexLast);
		pushFeature2(extension, "transformFeedbackPreservesProvokingVertex", extFeatures->transformFeedbackPreservesProvokingVertex);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_line_rasterization")) {
		const char* extension("VK_EXT_line_rasterization");
		VkPhysicalDeviceLineRasterizationFeaturesEXT* extFeatures = new VkPhysicalDeviceLineRasterizationFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "rectangularLines", extFeatures->rectangularLines);
		pushFeature2(extension, "bresenhamLines", extFeatures->bresenhamLines);
		pushFeature2(extension, "smoothLines", extFeatures->smoothLines);
		pushFeature2(extension, "stippledRectangularLines", extFeatures->stippledRectangularLines);
		pushFeature2(extension, "stippledBresenhamLines", extFeatures->stippledBresenhamLines);
		pushFeature2(extension, "stippledSmoothLines", extFeatures->stippledSmoothLines);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_shader_atomic_float")) {
		const char* extension("VK_EXT_shader_atomic_float");
		VkPhysicalDeviceShaderAtomicFloatFeaturesEXT* extFeatures = new VkPhysicalDeviceShaderAtomicFloatFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "shaderBufferFloat32Atomics", extFeatures->shaderBufferFloat32Atomics);
		pushFeature2(extension, "shaderBufferFloat32AtomicAdd", extFeatures->shaderBufferFloat32AtomicAdd);
		pushFeature2(extension, "shaderBufferFloat64Atomics", extFeatures->shaderBufferFloat64Atomics);
		pushFeature2(extension, "shaderBufferFloat64AtomicAdd", extFeatures->shaderBufferFloat64AtomicAdd);
		pushFeature2(extension, "shaderSharedFloat32Atomics", extFeatures->shaderSharedFloat32Atomics);
		pushFeature2(extension, "shaderSharedFloat32AtomicAdd", extFeatures->shaderSharedFloat32AtomicAdd);
		pushFeature2(extension, "shaderSharedFloat64Atomics", extFeatures->shaderSharedFloat64Atomics);
		pushFeature2(extension, "shaderSharedFloat64AtomicAdd", extFeatures->shaderSharedFloat64AtomicAdd);
		pushFeature2(extension, "shaderImageFloat32Atomics", extFeatures->shaderImageFloat32Atomics);
		pushFeature2(extension, "shaderImageFloat32AtomicAdd", extFeatures->shaderImageFloat32AtomicAdd);
		pushFeature2(extension, "sparseImageFloat32Atomics", extFeatures->sparseImageFloat32Atomics);
		pushFeature2(extension, "sparseImageFloat32AtomicAdd", extFeatures->sparseImageFloat32AtomicAdd);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_host_query_reset")) {
		const char* extension("VK_EXT_host_query_reset");
		VkPhysicalDeviceHostQueryResetFeatures* extFeatures = new VkPhysicalDeviceHostQueryResetFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "hostQueryReset", extFeatures->hostQueryReset);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_index_type_uint8")) {
		const char* extension("VK_EXT_index_type_uint8");
		VkPhysicalDeviceIndexTypeUint8FeaturesEXT* extFeatures = new VkPhysicalDeviceIndexTypeUint8FeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "indexTypeUint8", extFeatures->indexTypeUint8);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_extended_dynamic_state")) {
		const char* extension("VK_EXT_extended_dynamic_state");
		VkPhysicalDeviceExtendedDynamicStateFeaturesEXT* extFeatures = new VkPhysicalDeviceExtendedDynamicStateFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "extendedDynamicState", extFeatures->extendedDynamicState);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_shader_atomic_float2")) {
		const char* extension("VK_EXT_shader_atomic_float2");
		VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT* extFeatures = new VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_2_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "shaderBufferFloat16Atomics", extFeatures->shaderBufferFloat16Atomics);
		pushFeature2(extension, "shaderBufferFloat16AtomicAdd", extFeatures->shaderBufferFloat16AtomicAdd);
		pushFeature2(extension, "shaderBufferFloat16AtomicMinMax", extFeatures->shaderBufferFloat16AtomicMinMax);
		pushFeature2(extension, "shaderBufferFloat32AtomicMinMax", extFeatures->shaderBufferFloat32AtomicMinMax);
		pushFeature2(extension, "shaderBufferFloat64AtomicMinMax", extFeatures->shaderBufferFloat64AtomicMinMax);
		pushFeature2(extension, "shaderSharedFloat16Atomics", extFeatures->shaderSharedFloat16Atomics);
		pushFeature2(extension, "shaderSharedFloat16AtomicAdd", extFeatures->shaderSharedFloat16AtomicAdd);
		pushFeature2(extension, "shaderSharedFloat16AtomicMinMax", extFeatures->shaderSharedFloat16AtomicMinMax);
		pushFeature2(extension, "shaderSharedFloat32AtomicMinMax", extFeatures->shaderSharedFloat32AtomicMinMax);
		pushFeature2(extension, "shaderSharedFloat64AtomicMinMax", extFeatures->shaderSharedFloat64AtomicMinMax);
		pushFeature2(extension, "shaderImageFloat32AtomicMinMax", extFeatures->shaderImageFloat32AtomicMinMax);
		pushFeature2(extension, "sparseImageFloat32AtomicMinMax", extFeatures->sparseImageFloat32AtomicMinMax);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_swapchain_maintenance1")) {
		const char* extension("VK_EXT_swapchain_maintenance1");
		VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT* extFeatures = new VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SWAPCHAIN_MAINTENANCE_1_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "swapchainMaintenance1", extFeatures->swapchainMaintenance1);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_shader_demote_to_helper_invocation")) {
		const char* extension("VK_EXT_shader_demote_to_helper_invocation");
		VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures* extFeatures = new VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "shaderDemoteToHelperInvocation", extFeatures->shaderDemoteToHelperInvocation);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_texel_buffer_alignment")) {
		const char* extension("VK_EXT_texel_buffer_alignment");
		VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT* extFeatures = new VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "texelBufferAlignment", extFeatures->texelBufferAlignment);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_device_memory_report")) {
		const char* extension("VK_EXT_device_memory_report");
		VkPhysicalDeviceDeviceMemoryReportFeaturesEXT* extFeatures = new VkPhysicalDeviceDeviceMemoryReportFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_MEMORY_REPORT_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "deviceMemoryReport", extFeatures->deviceMemoryReport);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_robustness2")) {
		const char* extension("VK_EXT_robustness2");
		VkPhysicalDeviceRobustness2FeaturesEXT* extFeatures = new VkPhysicalDeviceRobustness2FeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "robustBufferAccess2", extFeatures->robustBufferAccess2);
		pushFeature2(extension, "robustImageAccess2", extFeatures->robustImageAccess2);
		pushFeature2(extension, "nullDescriptor", extFeatures->nullDescriptor);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_custom_border_color")) {
		const char* extension("VK_EXT_custom_border_color");
		VkPhysicalDeviceCustomBorderColorFeaturesEXT* extFeatures = new VkPhysicalDeviceCustomBorderColorFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "customBorderColors", extFeatures->customBorderColors);
		pushFeature2(extension, "customBorderColorWithoutFormat", extFeatures->customBorderColorWithoutFormat);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_private_data")) {
		const char* extension("VK_EXT_private_data");
		VkPhysicalDevicePrivateDataFeatures* extFeatures = new VkPhysicalDevicePrivateDataFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "privateData", extFeatures->privateData);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_pipeline_creation_cache_control")) {
		const char* extension("VK_EXT_pipeline_creation_cache_control");
		VkPhysicalDevicePipelineCreationCacheControlFeatures* extFeatures = new VkPhysicalDevicePipelineCreationCacheControlFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "pipelineCreationCacheControl", extFeatures->pipelineCreationCacheControl);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_descriptor_buffer")) {
		const char* extension("VK_EXT_descriptor_buffer");
		VkPhysicalDeviceDescriptorBufferFeaturesEXT* extFeatures = new VkPhysicalDeviceDescriptorBufferFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "descriptorBuffer", extFeatures->descriptorBuffer);
		pushFeature2(extension, "descriptorBufferCaptureReplay", extFeatures->descriptorBufferCaptureReplay);
		pushFeature2(extension, "descriptorBufferImageLayoutIgnored", extFeatures->descriptorBufferImageLayoutIgnored);
		pushFeature2(extension, "descriptorBufferPushDescriptors", extFeatures->descriptorBufferPushDescriptors);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_graphics_pipeline_library")) {
		const char* extension("VK_EXT_graphics_pipeline_library");
		VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT* extFeatures = new VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "graphicsPipelineLibrary", extFeatures->graphicsPipelineLibrary);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_mesh_shader")) {
		const char* extension("VK_EXT_mesh_shader");
		VkPhysicalDeviceMeshShaderFeaturesEXT* extFeatures = new VkPhysicalDeviceMeshShaderFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "taskShader", extFeatures->taskShader);
		pushFeature2(extension, "meshShader", extFeatures->meshShader);
		pushFeature2(extension, "multiviewMeshShader", extFeatures->multiviewMeshShader);
		pushFeature2(extension, "primitiveFragmentShadingRateMeshShader", extFeatures->primitiveFragmentShadingRateMeshShader);
		pushFeature2(extension, "meshShaderQueries", extFeatures->meshShaderQueries);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_ycbcr_2plane_444_formats")) {
		const char* extension("VK_EXT_ycbcr_2plane_444_formats");
		VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT* extFeatures = new VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "ycbcr2plane444Formats", extFeatures->ycbcr2plane444Formats);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_fragment_density_map2")) {
		const char* extension("VK_EXT_fragment_density_map2");
		VkPhysicalDeviceFragmentDensityMap2FeaturesEXT* extFeatures = new VkPhysicalDeviceFragmentDensityMap2FeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "fragmentDensityMapDeferred", extFeatures->fragmentDensityMapDeferred);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_image_robustness")) {
		const char* extension("VK_EXT_image_robustness");
		VkPhysicalDeviceImageRobustnessFeatures* extFeatures = new VkPhysicalDeviceImageRobustnessFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "robustImageAccess", extFeatures->robustImageAccess);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_image_compression_control")) {
		const char* extension("VK_EXT_image_compression_control");
		VkPhysicalDeviceImageCompressionControlFeaturesEXT* extFeatures = new VkPhysicalDeviceImageCompressionControlFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "imageCompressionControl", extFeatures->imageCompressionControl);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_attachment_feedback_loop_layout")) {
		const char* extension("VK_EXT_attachment_feedback_loop_layout");
		VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT* extFeatures = new VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_LAYOUT_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "attachmentFeedbackLoopLayout", extFeatures->attachmentFeedbackLoopLayout);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_4444_formats")) {
		const char* extension("VK_EXT_4444_formats");
		VkPhysicalDevice4444FormatsFeaturesEXT* extFeatures = new VkPhysicalDevice4444FormatsFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "formatA4R4G4B4", extFeatures->formatA4R4G4B4);
		pushFeature2(extension, "formatA4B4G4R4", extFeatures->formatA4B4G4R4);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_device_fault")) {
		const char* extension("VK_EXT_device_fault");
		VkPhysicalDeviceFaultFeaturesEXT* extFeatures = new VkPhysicalDeviceFaultFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "deviceFault", extFeatures->deviceFault);
		pushFeature2(extension, "deviceFaultVendorBinary", extFeatures->deviceFaultVendorBinary);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_rgba10x6_formats")) {
		const char* extension("VK_EXT_rgba10x6_formats");
		VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT* extFeatures = new VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RGBA10X6_FORMATS_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "formatRgba10x6WithoutYCbCrSampler", extFeatures->formatRgba10x6WithoutYCbCrSampler);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_vertex_input_dynamic_state")) {
		const char* extension("VK_EXT_vertex_input_dynamic_state");
		VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT* extFeatures = new VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "vertexInputDynamicState", extFeatures->vertexInputDynamicState);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_device_address_binding_report")) {
		const char* extension("VK_EXT_device_address_binding_report");
		VkPhysicalDeviceAddressBindingReportFeaturesEXT* extFeatures = new VkPhysicalDeviceAddressBindingReportFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ADDRESS_BINDING_REPORT_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "reportAddressBinding", extFeatures->reportAddressBinding);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_depth_clip_control")) {
		const char* extension("VK_EXT_depth_clip_control");
		VkPhysicalDeviceDepthClipControlFeaturesEXT* extFeatures = new VkPhysicalDeviceDepthClipControlFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_CONTROL_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "depthClipControl", extFeatures->depthClipControl);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_primitive_topology_list_restart")) {
		const char* extension("VK_EXT_primitive_topology_list_restart");
		VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT* extFeatures = new VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_TOPOLOGY_LIST_RESTART_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "primitiveTopologyListRestart", extFeatures->primitiveTopologyListRestart);
		pushFeature2(extension, "primitiveTopologyPatchListRestart", extFeatures->primitiveTopologyPatchListRestart);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_pipeline_properties")) {
		const char* extension("VK_EXT_pipeline_properties");
		VkPhysicalDevicePipelinePropertiesFeaturesEXT* extFeatures = new VkPhysicalDevicePipelinePropertiesFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROPERTIES_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "pipelinePropertiesIdentifier", extFeatures->pipelinePropertiesIdentifier);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_multisampled_render_to_single_sampled")) {
		const char* extension("VK_EXT_multisampled_render_to_single_sampled");
		VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT* extFeatures = new VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "multisampledRenderToSingleSampled", extFeatures->multisampledRenderToSingleSampled);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_extended_dynamic_state2")) {
		const char* extension("VK_EXT_extended_dynamic_state2");
		VkPhysicalDeviceExtendedDynamicState2FeaturesEXT* extFeatures = new VkPhysicalDeviceExtendedDynamicState2FeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "extendedDynamicState2", extFeatures->extendedDynamicState2);
		pushFeature2(extension, "extendedDynamicState2LogicOp", extFeatures->extendedDynamicState2LogicOp);
		pushFeature2(extension, "extendedDynamicState2PatchControlPoints", extFeatures->extendedDynamicState2PatchControlPoints);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_color_write_enable")) {
		const char* extension("VK_EXT_color_write_enable");
		VkPhysicalDeviceColorWriteEnableFeaturesEXT* extFeatures = new VkPhysicalDeviceColorWriteEnableFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "colorWriteEnable", extFeatures->colorWriteEnable);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_primitives_generated_query")) {
		const char* extension("VK_EXT_primitives_generated_query");
		VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT* extFeatures = new VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVES_GENERATED_QUERY_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "primitivesGeneratedQuery", extFeatures->primitivesGeneratedQuery);
		pushFeature2(extension, "primitivesGeneratedQueryWithRasterizerDiscard", extFeatures->primitivesGeneratedQueryWithRasterizerDiscard);
		pushFeature2(extension, "primitivesGeneratedQueryWithNonZeroStreams", extFeatures->primitivesGeneratedQueryWithNonZeroStreams);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_global_priority_query")) {
		const char* extension("VK_EXT_global_priority_query");
		VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR* extFeatures = new VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "globalPriorityQuery", extFeatures->globalPriorityQuery);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_image_view_min_lod")) {
		const char* extension("VK_EXT_image_view_min_lod");
		VkPhysicalDeviceImageViewMinLodFeaturesEXT* extFeatures = new VkPhysicalDeviceImageViewMinLodFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_MIN_LOD_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "minLod", extFeatures->minLod);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_multi_draw")) {
		const char* extension("VK_EXT_multi_draw");
		VkPhysicalDeviceMultiDrawFeaturesEXT* extFeatures = new VkPhysicalDeviceMultiDrawFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "multiDraw", extFeatures->multiDraw);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_image_2d_view_of_3d")) {
		const char* extension("VK_EXT_image_2d_view_of_3d");
		VkPhysicalDeviceImage2DViewOf3DFeaturesEXT* extFeatures = new VkPhysicalDeviceImage2DViewOf3DFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_2D_VIEW_OF_3D_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "image2DViewOf3D", extFeatures->image2DViewOf3D);
		pushFeature2(extension, "sampler2DViewOf3D", extFeatures->sampler2DViewOf3D);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_opacity_micromap")) {
		const char* extension("VK_EXT_opacity_micromap");
		VkPhysicalDeviceOpacityMicromapFeaturesEXT* extFeatures = new VkPhysicalDeviceOpacityMicromapFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "micromap", extFeatures->micromap);
		pushFeature2(extension, "micromapCaptureReplay", extFeatures->micromapCaptureReplay);
		pushFeature2(extension, "micromapHostCommands", extFeatures->micromapHostCommands);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_border_color_swizzle")) {
		const char* extension("VK_EXT_border_color_swizzle");
		VkPhysicalDeviceBorderColorSwizzleFeaturesEXT* extFeatures = new VkPhysicalDeviceBorderColorSwizzleFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BORDER_COLOR_SWIZZLE_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "borderColorSwizzle", extFeatures->borderColorSwizzle);
		pushFeature2(extension, "borderColorSwizzleFromImage", extFeatures->borderColorSwizzleFromImage);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_pageable_device_local_memory")) {
		const char* extension("VK_EXT_pageable_device_local_memory");
		VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT* extFeatures = new VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PAGEABLE_DEVICE_LOCAL_MEMORY_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "pageableDeviceLocalMemory", extFeatures->pageableDeviceLocalMemory);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_depth_clamp_zero_one")) {
		const char* extension("VK_EXT_depth_clamp_zero_one");
		VkPhysicalDeviceDepthClampZeroOneFeaturesEXT* extFeatures = new VkPhysicalDeviceDepthClampZeroOneFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_ZERO_ONE_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "depthClampZeroOne", extFeatures->depthClampZeroOne);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_non_seamless_cube_map")) {
		const char* extension("VK_EXT_non_seamless_cube_map");
		VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT* extFeatures = new VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NON_SEAMLESS_CUBE_MAP_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "nonSeamlessCubeMap", extFeatures->nonSeamlessCubeMap);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_image_compression_control_swapchain")) {
		const char* extension("VK_EXT_image_compression_control_swapchain");
		VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT* extFeatures = new VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "imageCompressionControlSwapchain", extFeatures->imageCompressionControlSwapchain);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_extended_dynamic_state3")) {
		const char* extension("VK_EXT_extended_dynamic_state3");
		VkPhysicalDeviceExtendedDynamicState3FeaturesEXT* extFeatures = new VkPhysicalDeviceExtendedDynamicState3FeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "extendedDynamicState3TessellationDomainOrigin", extFeatures->extendedDynamicState3TessellationDomainOrigin);
		pushFeature2(extension, "extendedDynamicState3DepthClampEnable", extFeatures->extendedDynamicState3DepthClampEnable);
		pushFeature2(extension, "extendedDynamicState3PolygonMode", extFeatures->extendedDynamicState3PolygonMode);
		pushFeature2(extension, "extendedDynamicState3RasterizationSamples", extFeatures->extendedDynamicState3RasterizationSamples);
		pushFeature2(extension, "extendedDynamicState3SampleMask", extFeatures->extendedDynamicState3SampleMask);
		pushFeature2(extension, "extendedDynamicState3AlphaToCoverageEnable", extFeatures->extendedDynamicState3AlphaToCoverageEnable);
		pushFeature2(extension, "extendedDynamicState3AlphaToOneEnable", extFeatures->extendedDynamicState3AlphaToOneEnable);
		pushFeature2(extension, "extendedDynamicState3LogicOpEnable", extFeatures->extendedDynamicState3LogicOpEnable);
		pushFeature2(extension, "extendedDynamicState3ColorBlendEnable", extFeatures->extendedDynamicState3ColorBlendEnable);
		pushFeature2(extension, "extendedDynamicState3ColorBlendEquation", extFeatures->extendedDynamicState3ColorBlendEquation);
		pushFeature2(extension, "extendedDynamicState3ColorWriteMask", extFeatures->extendedDynamicState3ColorWriteMask);
		pushFeature2(extension, "extendedDynamicState3RasterizationStream", extFeatures->extendedDynamicState3RasterizationStream);
		pushFeature2(extension, "extendedDynamicState3ConservativeRasterizationMode", extFeatures->extendedDynamicState3ConservativeRasterizationMode);
		pushFeature2(extension, "extendedDynamicState3ExtraPrimitiveOverestimationSize", extFeatures->extendedDynamicState3ExtraPrimitiveOverestimationSize);
		pushFeature2(extension, "extendedDynamicState3DepthClipEnable", extFeatures->extendedDynamicState3DepthClipEnable);
		pushFeature2(extension, "extendedDynamicState3SampleLocationsEnable", extFeatures->extendedDynamicState3SampleLocationsEnable);
		pushFeature2(extension, "extendedDynamicState3ColorBlendAdvanced", extFeatures->extendedDynamicState3ColorBlendAdvanced);
		pushFeature2(extension, "extendedDynamicState3ProvokingVertexMode", extFeatures->extendedDynamicState3ProvokingVertexMode);
		pushFeature2(extension, "extendedDynamicState3LineRasterizationMode", extFeatures->extendedDynamicState3LineRasterizationMode);
		pushFeature2(extension, "extendedDynamicState3LineStippleEnable", extFeatures->extendedDynamicState3LineStippleEnable);
		pushFeature2(extension, "extendedDynamicState3DepthClipNegativeOneToOne", extFeatures->extendedDynamicState3DepthClipNegativeOneToOne);
		pushFeature2(extension, "extendedDynamicState3ViewportWScalingEnable", extFeatures->extendedDynamicState3ViewportWScalingEnable);
		pushFeature2(extension, "extendedDynamicState3ViewportSwizzle", extFeatures->extendedDynamicState3ViewportSwizzle);
		pushFeature2(extension, "extendedDynamicState3CoverageToColorEnable", extFeatures->extendedDynamicState3CoverageToColorEnable);
		pushFeature2(extension, "extendedDynamicState3CoverageToColorLocation", extFeatures->extendedDynamicState3CoverageToColorLocation);
		pushFeature2(extension, "extendedDynamicState3CoverageModulationMode", extFeatures->extendedDynamicState3CoverageModulationMode);
		pushFeature2(extension, "extendedDynamicState3CoverageModulationTableEnable", extFeatures->extendedDynamicState3CoverageModulationTableEnable);
		pushFeature2(extension, "extendedDynamicState3CoverageModulationTable", extFeatures->extendedDynamicState3CoverageModulationTable);
		pushFeature2(extension, "extendedDynamicState3CoverageReductionMode", extFeatures->extendedDynamicState3CoverageReductionMode);
		pushFeature2(extension, "extendedDynamicState3RepresentativeFragmentTestEnable", extFeatures->extendedDynamicState3RepresentativeFragmentTestEnable);
		pushFeature2(extension, "extendedDynamicState3ShadingRateImageEnable", extFeatures->extendedDynamicState3ShadingRateImageEnable);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_subpass_merge_feedback")) {
		const char* extension("VK_EXT_subpass_merge_feedback");
		VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT* extFeatures = new VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_MERGE_FEEDBACK_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "subpassMergeFeedback", extFeatures->subpassMergeFeedback);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_shader_module_identifier")) {
		const char* extension("VK_EXT_shader_module_identifier");
		VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT* extFeatures = new VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "shaderModuleIdentifier", extFeatures->shaderModuleIdentifier);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_rasterization_order_attachment_access")) {
		const char* extension("VK_EXT_rasterization_order_attachment_access");
		VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT* extFeatures = new VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "rasterizationOrderColorAttachmentAccess", extFeatures->rasterizationOrderColorAttachmentAccess);
		pushFeature2(extension, "rasterizationOrderDepthAttachmentAccess", extFeatures->rasterizationOrderDepthAttachmentAccess);
		pushFeature2(extension, "rasterizationOrderStencilAttachmentAccess", extFeatures->rasterizationOrderStencilAttachmentAccess);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_legacy_dithering")) {
		const char* extension("VK_EXT_legacy_dithering");
		VkPhysicalDeviceLegacyDitheringFeaturesEXT* extFeatures = new VkPhysicalDeviceLegacyDitheringFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_DITHERING_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "legacyDithering", extFeatures->legacyDithering);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_pipeline_protected_access")) {
		const char* extension("VK_EXT_pipeline_protected_access");
		VkPhysicalDevicePipelineProtectedAccessFeaturesEXT* extFeatures = new VkPhysicalDevicePipelineProtectedAccessFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROTECTED_ACCESS_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "pipelineProtectedAccess", extFeatures->pipelineProtectedAccess);
		delete extFeatures;
	}
	if (extensionSupported("VK_EXT_mutable_descriptor_type")) {
		const char* extension("VK_EXT_mutable_descriptor_type");
		VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT* extFeatures = new VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "mutableDescriptorType", extFeatures->mutableDescriptorType);
		delete extFeatures;
	}
}
void VulkanDeviceInfoExtensions::readPhysicalFeatures_HUAWEI() {
	VkPhysicalDeviceFeatures2 deviceFeatures2{};
	if (extensionSupported("VK_HUAWEI_subpass_shading")) {
		const char* extension("VK_HUAWEI_subpass_shading");
		VkPhysicalDeviceSubpassShadingFeaturesHUAWEI* extFeatures = new VkPhysicalDeviceSubpassShadingFeaturesHUAWEI{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_SHADING_FEATURES_HUAWEI;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "subpassShading", extFeatures->subpassShading);
		delete extFeatures;
	}
	if (extensionSupported("VK_HUAWEI_invocation_mask")) {
		const char* extension("VK_HUAWEI_invocation_mask");
		VkPhysicalDeviceInvocationMaskFeaturesHUAWEI* extFeatures = new VkPhysicalDeviceInvocationMaskFeaturesHUAWEI{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INVOCATION_MASK_FEATURES_HUAWEI;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "invocationMask", extFeatures->invocationMask);
		delete extFeatures;
	}
}
void VulkanDeviceInfoExtensions::readPhysicalFeatures_INTEL() {
	VkPhysicalDeviceFeatures2 deviceFeatures2{};
	if (extensionSupported("VK_INTEL_shader_integer_functions2")) {
		const char* extension("VK_INTEL_shader_integer_functions2");
		VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL* extFeatures = new VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "shaderIntegerFunctions2", extFeatures->shaderIntegerFunctions2);
		delete extFeatures;
	}
}
void VulkanDeviceInfoExtensions::readPhysicalFeatures_KHR() {
	VkPhysicalDeviceFeatures2 deviceFeatures2{};
	if (extensionSupported("VK_KHR_dynamic_rendering")) {
		const char* extension("VK_KHR_dynamic_rendering");
		VkPhysicalDeviceDynamicRenderingFeatures* extFeatures = new VkPhysicalDeviceDynamicRenderingFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "dynamicRendering", extFeatures->dynamicRendering);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_multiview")) {
		const char* extension("VK_KHR_multiview");
		VkPhysicalDeviceMultiviewFeatures* extFeatures = new VkPhysicalDeviceMultiviewFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "multiview", extFeatures->multiview);
		pushFeature2(extension, "multiviewGeometryShader", extFeatures->multiviewGeometryShader);
		pushFeature2(extension, "multiviewTessellationShader", extFeatures->multiviewTessellationShader);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_shader_float16_int8")) {
		const char* extension("VK_KHR_shader_float16_int8");
		VkPhysicalDeviceShaderFloat16Int8Features* extFeatures = new VkPhysicalDeviceShaderFloat16Int8Features{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "shaderFloat16", extFeatures->shaderFloat16);
		pushFeature2(extension, "shaderInt8", extFeatures->shaderInt8);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_16bit_storage")) {
		const char* extension("VK_KHR_16bit_storage");
		VkPhysicalDevice16BitStorageFeatures* extFeatures = new VkPhysicalDevice16BitStorageFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "storageBuffer16BitAccess", extFeatures->storageBuffer16BitAccess);
		pushFeature2(extension, "uniformAndStorageBuffer16BitAccess", extFeatures->uniformAndStorageBuffer16BitAccess);
		pushFeature2(extension, "storagePushConstant16", extFeatures->storagePushConstant16);
		pushFeature2(extension, "storageInputOutput16", extFeatures->storageInputOutput16);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_imageless_framebuffer")) {
		const char* extension("VK_KHR_imageless_framebuffer");
		VkPhysicalDeviceImagelessFramebufferFeatures* extFeatures = new VkPhysicalDeviceImagelessFramebufferFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "imagelessFramebuffer", extFeatures->imagelessFramebuffer);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_performance_query")) {
		const char* extension("VK_KHR_performance_query");
		VkPhysicalDevicePerformanceQueryFeaturesKHR* extFeatures = new VkPhysicalDevicePerformanceQueryFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "performanceCounterQueryPools", extFeatures->performanceCounterQueryPools);
		pushFeature2(extension, "performanceCounterMultipleQueryPools", extFeatures->performanceCounterMultipleQueryPools);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_variable_pointers")) {
		const char* extension("VK_KHR_variable_pointers");
		VkPhysicalDeviceVariablePointersFeatures* extFeatures = new VkPhysicalDeviceVariablePointersFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "variablePointersStorageBuffer", extFeatures->variablePointersStorageBuffer);
		pushFeature2(extension, "variablePointers", extFeatures->variablePointers);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_acceleration_structure")) {
		const char* extension("VK_KHR_acceleration_structure");
		VkPhysicalDeviceAccelerationStructureFeaturesKHR* extFeatures = new VkPhysicalDeviceAccelerationStructureFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "accelerationStructure", extFeatures->accelerationStructure);
		pushFeature2(extension, "accelerationStructureCaptureReplay", extFeatures->accelerationStructureCaptureReplay);
		pushFeature2(extension, "accelerationStructureIndirectBuild", extFeatures->accelerationStructureIndirectBuild);
		pushFeature2(extension, "accelerationStructureHostCommands", extFeatures->accelerationStructureHostCommands);
		pushFeature2(extension, "descriptorBindingAccelerationStructureUpdateAfterBind", extFeatures->descriptorBindingAccelerationStructureUpdateAfterBind);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_ray_tracing_pipeline")) {
		const char* extension("VK_KHR_ray_tracing_pipeline");
		VkPhysicalDeviceRayTracingPipelineFeaturesKHR* extFeatures = new VkPhysicalDeviceRayTracingPipelineFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "rayTracingPipeline", extFeatures->rayTracingPipeline);
		pushFeature2(extension, "rayTracingPipelineShaderGroupHandleCaptureReplay", extFeatures->rayTracingPipelineShaderGroupHandleCaptureReplay);
		pushFeature2(extension, "rayTracingPipelineShaderGroupHandleCaptureReplayMixed", extFeatures->rayTracingPipelineShaderGroupHandleCaptureReplayMixed);
		pushFeature2(extension, "rayTracingPipelineTraceRaysIndirect", extFeatures->rayTracingPipelineTraceRaysIndirect);
		pushFeature2(extension, "rayTraversalPrimitiveCulling", extFeatures->rayTraversalPrimitiveCulling);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_ray_query")) {
		const char* extension("VK_KHR_ray_query");
		VkPhysicalDeviceRayQueryFeaturesKHR* extFeatures = new VkPhysicalDeviceRayQueryFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_QUERY_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "rayQuery", extFeatures->rayQuery);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_sampler_ycbcr_conversion")) {
		const char* extension("VK_KHR_sampler_ycbcr_conversion");
		VkPhysicalDeviceSamplerYcbcrConversionFeatures* extFeatures = new VkPhysicalDeviceSamplerYcbcrConversionFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "samplerYcbcrConversion", extFeatures->samplerYcbcrConversion);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_portability_subset")) {
		const char* extension("VK_KHR_portability_subset");
		VkPhysicalDevicePortabilitySubsetFeaturesKHR* extFeatures = new VkPhysicalDevicePortabilitySubsetFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "constantAlphaColorBlendFactors", extFeatures->constantAlphaColorBlendFactors);
		pushFeature2(extension, "events", extFeatures->events);
		pushFeature2(extension, "imageViewFormatReinterpretation", extFeatures->imageViewFormatReinterpretation);
		pushFeature2(extension, "imageViewFormatSwizzle", extFeatures->imageViewFormatSwizzle);
		pushFeature2(extension, "imageView2DOn3DImage", extFeatures->imageView2DOn3DImage);
		pushFeature2(extension, "multisampleArrayImage", extFeatures->multisampleArrayImage);
		pushFeature2(extension, "mutableComparisonSamplers", extFeatures->mutableComparisonSamplers);
		pushFeature2(extension, "pointPolygons", extFeatures->pointPolygons);
		pushFeature2(extension, "samplerMipLodBias", extFeatures->samplerMipLodBias);
		pushFeature2(extension, "separateStencilMaskRef", extFeatures->separateStencilMaskRef);
		pushFeature2(extension, "shaderSampleRateInterpolationFunctions", extFeatures->shaderSampleRateInterpolationFunctions);
		pushFeature2(extension, "tessellationIsolines", extFeatures->tessellationIsolines);
		pushFeature2(extension, "tessellationPointMode", extFeatures->tessellationPointMode);
		pushFeature2(extension, "triangleFans", extFeatures->triangleFans);
		pushFeature2(extension, "vertexAttributeAccessBeyondStride", extFeatures->vertexAttributeAccessBeyondStride);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_shader_subgroup_extended_types")) {
		const char* extension("VK_KHR_shader_subgroup_extended_types");
		VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures* extFeatures = new VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "shaderSubgroupExtendedTypes", extFeatures->shaderSubgroupExtendedTypes);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_8bit_storage")) {
		const char* extension("VK_KHR_8bit_storage");
		VkPhysicalDevice8BitStorageFeatures* extFeatures = new VkPhysicalDevice8BitStorageFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "storageBuffer8BitAccess", extFeatures->storageBuffer8BitAccess);
		pushFeature2(extension, "uniformAndStorageBuffer8BitAccess", extFeatures->uniformAndStorageBuffer8BitAccess);
		pushFeature2(extension, "storagePushConstant8", extFeatures->storagePushConstant8);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_shader_atomic_int64")) {
		const char* extension("VK_KHR_shader_atomic_int64");
		VkPhysicalDeviceShaderAtomicInt64Features* extFeatures = new VkPhysicalDeviceShaderAtomicInt64Features{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "shaderBufferInt64Atomics", extFeatures->shaderBufferInt64Atomics);
		pushFeature2(extension, "shaderSharedInt64Atomics", extFeatures->shaderSharedInt64Atomics);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_shader_clock")) {
		const char* extension("VK_KHR_shader_clock");
		VkPhysicalDeviceShaderClockFeaturesKHR* extFeatures = new VkPhysicalDeviceShaderClockFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "shaderSubgroupClock", extFeatures->shaderSubgroupClock);
		pushFeature2(extension, "shaderDeviceClock", extFeatures->shaderDeviceClock);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_global_priority")) {
		const char* extension("VK_KHR_global_priority");
		VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR* extFeatures = new VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "globalPriorityQuery", extFeatures->globalPriorityQuery);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_timeline_semaphore")) {
		const char* extension("VK_KHR_timeline_semaphore");
		VkPhysicalDeviceTimelineSemaphoreFeatures* extFeatures = new VkPhysicalDeviceTimelineSemaphoreFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "timelineSemaphore", extFeatures->timelineSemaphore);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_vulkan_memory_model")) {
		const char* extension("VK_KHR_vulkan_memory_model");
		VkPhysicalDeviceVulkanMemoryModelFeatures* extFeatures = new VkPhysicalDeviceVulkanMemoryModelFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "vulkanMemoryModel", extFeatures->vulkanMemoryModel);
		pushFeature2(extension, "vulkanMemoryModelDeviceScope", extFeatures->vulkanMemoryModelDeviceScope);
		pushFeature2(extension, "vulkanMemoryModelAvailabilityVisibilityChains", extFeatures->vulkanMemoryModelAvailabilityVisibilityChains);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_shader_terminate_invocation")) {
		const char* extension("VK_KHR_shader_terminate_invocation");
		VkPhysicalDeviceShaderTerminateInvocationFeatures* extFeatures = new VkPhysicalDeviceShaderTerminateInvocationFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "shaderTerminateInvocation", extFeatures->shaderTerminateInvocation);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_fragment_shading_rate")) {
		const char* extension("VK_KHR_fragment_shading_rate");
		VkPhysicalDeviceFragmentShadingRateFeaturesKHR* extFeatures = new VkPhysicalDeviceFragmentShadingRateFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "pipelineFragmentShadingRate", extFeatures->pipelineFragmentShadingRate);
		pushFeature2(extension, "primitiveFragmentShadingRate", extFeatures->primitiveFragmentShadingRate);
		pushFeature2(extension, "attachmentFragmentShadingRate", extFeatures->attachmentFragmentShadingRate);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_separate_depth_stencil_layouts")) {
		const char* extension("VK_KHR_separate_depth_stencil_layouts");
		VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures* extFeatures = new VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "separateDepthStencilLayouts", extFeatures->separateDepthStencilLayouts);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_present_wait")) {
		const char* extension("VK_KHR_present_wait");
		VkPhysicalDevicePresentWaitFeaturesKHR* extFeatures = new VkPhysicalDevicePresentWaitFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "presentWait", extFeatures->presentWait);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_uniform_buffer_standard_layout")) {
		const char* extension("VK_KHR_uniform_buffer_standard_layout");
		VkPhysicalDeviceUniformBufferStandardLayoutFeatures* extFeatures = new VkPhysicalDeviceUniformBufferStandardLayoutFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "uniformBufferStandardLayout", extFeatures->uniformBufferStandardLayout);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_buffer_device_address")) {
		const char* extension("VK_KHR_buffer_device_address");
		VkPhysicalDeviceBufferDeviceAddressFeatures* extFeatures = new VkPhysicalDeviceBufferDeviceAddressFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "bufferDeviceAddress", extFeatures->bufferDeviceAddress);
		pushFeature2(extension, "bufferDeviceAddressCaptureReplay", extFeatures->bufferDeviceAddressCaptureReplay);
		pushFeature2(extension, "bufferDeviceAddressMultiDevice", extFeatures->bufferDeviceAddressMultiDevice);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_pipeline_executable_properties")) {
		const char* extension("VK_KHR_pipeline_executable_properties");
		VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR* extFeatures = new VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "pipelineExecutableInfo", extFeatures->pipelineExecutableInfo);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_shader_integer_dot_product")) {
		const char* extension("VK_KHR_shader_integer_dot_product");
		VkPhysicalDeviceShaderIntegerDotProductFeatures* extFeatures = new VkPhysicalDeviceShaderIntegerDotProductFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "shaderIntegerDotProduct", extFeatures->shaderIntegerDotProduct);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_present_id")) {
		const char* extension("VK_KHR_present_id");
		VkPhysicalDevicePresentIdFeaturesKHR* extFeatures = new VkPhysicalDevicePresentIdFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "presentId", extFeatures->presentId);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_synchronization2")) {
		const char* extension("VK_KHR_synchronization2");
		VkPhysicalDeviceSynchronization2Features* extFeatures = new VkPhysicalDeviceSynchronization2Features{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "synchronization2", extFeatures->synchronization2);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_fragment_shader_barycentric")) {
		const char* extension("VK_KHR_fragment_shader_barycentric");
		VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR* extFeatures = new VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "fragmentShaderBarycentric", extFeatures->fragmentShaderBarycentric);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_shader_subgroup_uniform_control_flow")) {
		const char* extension("VK_KHR_shader_subgroup_uniform_control_flow");
		VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR* extFeatures = new VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "shaderSubgroupUniformControlFlow", extFeatures->shaderSubgroupUniformControlFlow);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_zero_initialize_workgroup_memory")) {
		const char* extension("VK_KHR_zero_initialize_workgroup_memory");
		VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures* extFeatures = new VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "shaderZeroInitializeWorkgroupMemory", extFeatures->shaderZeroInitializeWorkgroupMemory);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_workgroup_memory_explicit_layout")) {
		const char* extension("VK_KHR_workgroup_memory_explicit_layout");
		VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR* extFeatures = new VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "workgroupMemoryExplicitLayout", extFeatures->workgroupMemoryExplicitLayout);
		pushFeature2(extension, "workgroupMemoryExplicitLayoutScalarBlockLayout", extFeatures->workgroupMemoryExplicitLayoutScalarBlockLayout);
		pushFeature2(extension, "workgroupMemoryExplicitLayout8BitAccess", extFeatures->workgroupMemoryExplicitLayout8BitAccess);
		pushFeature2(extension, "workgroupMemoryExplicitLayout16BitAccess", extFeatures->workgroupMemoryExplicitLayout16BitAccess);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_ray_tracing_maintenance1")) {
		const char* extension("VK_KHR_ray_tracing_maintenance1");
		VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR* extFeatures = new VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MAINTENANCE_1_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "rayTracingMaintenance1", extFeatures->rayTracingMaintenance1);
		pushFeature2(extension, "rayTracingPipelineTraceRaysIndirect2", extFeatures->rayTracingPipelineTraceRaysIndirect2);
		delete extFeatures;
	}
	if (extensionSupported("VK_KHR_maintenance4")) {
		const char* extension("VK_KHR_maintenance4");
		VkPhysicalDeviceMaintenance4Features* extFeatures = new VkPhysicalDeviceMaintenance4Features{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "maintenance4", extFeatures->maintenance4);
		delete extFeatures;
	}
}
void VulkanDeviceInfoExtensions::readPhysicalFeatures_NV() {
	VkPhysicalDeviceFeatures2 deviceFeatures2{};
	if (extensionSupported("VK_NV_corner_sampled_image")) {
		const char* extension("VK_NV_corner_sampled_image");
		VkPhysicalDeviceCornerSampledImageFeaturesNV* extFeatures = new VkPhysicalDeviceCornerSampledImageFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "cornerSampledImage", extFeatures->cornerSampledImage);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_shader_sm_builtins")) {
		const char* extension("VK_NV_shader_sm_builtins");
		VkPhysicalDeviceShaderSMBuiltinsFeaturesNV* extFeatures = new VkPhysicalDeviceShaderSMBuiltinsFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "shaderSMBuiltins", extFeatures->shaderSMBuiltins);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_shading_rate_image")) {
		const char* extension("VK_NV_shading_rate_image");
		VkPhysicalDeviceShadingRateImageFeaturesNV* extFeatures = new VkPhysicalDeviceShadingRateImageFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "shadingRateImage", extFeatures->shadingRateImage);
		pushFeature2(extension, "shadingRateCoarseSampleOrder", extFeatures->shadingRateCoarseSampleOrder);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_representative_fragment_test")) {
		const char* extension("VK_NV_representative_fragment_test");
		VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV* extFeatures = new VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "representativeFragmentTest", extFeatures->representativeFragmentTest);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_compute_shader_derivatives")) {
		const char* extension("VK_NV_compute_shader_derivatives");
		VkPhysicalDeviceComputeShaderDerivativesFeaturesNV* extFeatures = new VkPhysicalDeviceComputeShaderDerivativesFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "computeDerivativeGroupQuads", extFeatures->computeDerivativeGroupQuads);
		pushFeature2(extension, "computeDerivativeGroupLinear", extFeatures->computeDerivativeGroupLinear);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_mesh_shader")) {
		const char* extension("VK_NV_mesh_shader");
		VkPhysicalDeviceMeshShaderFeaturesNV* extFeatures = new VkPhysicalDeviceMeshShaderFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "taskShader", extFeatures->taskShader);
		pushFeature2(extension, "meshShader", extFeatures->meshShader);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_fragment_shader_barycentric")) {
		const char* extension("VK_NV_fragment_shader_barycentric");
		VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR* extFeatures = new VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_KHR;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "fragmentShaderBarycentric", extFeatures->fragmentShaderBarycentric);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_shader_image_footprint")) {
		const char* extension("VK_NV_shader_image_footprint");
		VkPhysicalDeviceShaderImageFootprintFeaturesNV* extFeatures = new VkPhysicalDeviceShaderImageFootprintFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "imageFootprint", extFeatures->imageFootprint);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_scissor_exclusive")) {
		const char* extension("VK_NV_scissor_exclusive");
		VkPhysicalDeviceExclusiveScissorFeaturesNV* extFeatures = new VkPhysicalDeviceExclusiveScissorFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "exclusiveScissor", extFeatures->exclusiveScissor);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_dedicated_allocation_image_aliasing")) {
		const char* extension("VK_NV_dedicated_allocation_image_aliasing");
		VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV* extFeatures = new VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "dedicatedAllocationImageAliasing", extFeatures->dedicatedAllocationImageAliasing);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_cooperative_matrix")) {
		const char* extension("VK_NV_cooperative_matrix");
		VkPhysicalDeviceCooperativeMatrixFeaturesNV* extFeatures = new VkPhysicalDeviceCooperativeMatrixFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "cooperativeMatrix", extFeatures->cooperativeMatrix);
		pushFeature2(extension, "cooperativeMatrixRobustBufferAccess", extFeatures->cooperativeMatrixRobustBufferAccess);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_coverage_reduction_mode")) {
		const char* extension("VK_NV_coverage_reduction_mode");
		VkPhysicalDeviceCoverageReductionModeFeaturesNV* extFeatures = new VkPhysicalDeviceCoverageReductionModeFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "coverageReductionMode", extFeatures->coverageReductionMode);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_device_generated_commands")) {
		const char* extension("VK_NV_device_generated_commands");
		VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV* extFeatures = new VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "deviceGeneratedCommands", extFeatures->deviceGeneratedCommands);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_inherited_viewport_scissor")) {
		const char* extension("VK_NV_inherited_viewport_scissor");
		VkPhysicalDeviceInheritedViewportScissorFeaturesNV* extFeatures = new VkPhysicalDeviceInheritedViewportScissorFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INHERITED_VIEWPORT_SCISSOR_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "inheritedViewportScissor2D", extFeatures->inheritedViewportScissor2D);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_present_barrier")) {
		const char* extension("VK_NV_present_barrier");
		VkPhysicalDevicePresentBarrierFeaturesNV* extFeatures = new VkPhysicalDevicePresentBarrierFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_BARRIER_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "presentBarrier", extFeatures->presentBarrier);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_device_diagnostics_config")) {
		const char* extension("VK_NV_device_diagnostics_config");
		VkPhysicalDeviceDiagnosticsConfigFeaturesNV* extFeatures = new VkPhysicalDeviceDiagnosticsConfigFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "diagnosticsConfig", extFeatures->diagnosticsConfig);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_fragment_shading_rate_enums")) {
		const char* extension("VK_NV_fragment_shading_rate_enums");
		VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV* extFeatures = new VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "fragmentShadingRateEnums", extFeatures->fragmentShadingRateEnums);
		pushFeature2(extension, "supersampleFragmentShadingRates", extFeatures->supersampleFragmentShadingRates);
		pushFeature2(extension, "noInvocationFragmentShadingRates", extFeatures->noInvocationFragmentShadingRates);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_ray_tracing_motion_blur")) {
		const char* extension("VK_NV_ray_tracing_motion_blur");
		VkPhysicalDeviceRayTracingMotionBlurFeaturesNV* extFeatures = new VkPhysicalDeviceRayTracingMotionBlurFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MOTION_BLUR_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "rayTracingMotionBlur", extFeatures->rayTracingMotionBlur);
		pushFeature2(extension, "rayTracingMotionBlurPipelineTraceRaysIndirect", extFeatures->rayTracingMotionBlurPipelineTraceRaysIndirect);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_external_memory_rdma")) {
		const char* extension("VK_NV_external_memory_rdma");
		VkPhysicalDeviceExternalMemoryRDMAFeaturesNV* extFeatures = new VkPhysicalDeviceExternalMemoryRDMAFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_RDMA_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "externalMemoryRDMA", extFeatures->externalMemoryRDMA);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_copy_memory_indirect")) {
		const char* extension("VK_NV_copy_memory_indirect");
		VkPhysicalDeviceCopyMemoryIndirectFeaturesNV* extFeatures = new VkPhysicalDeviceCopyMemoryIndirectFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "indirectCopy", extFeatures->indirectCopy);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_memory_decompression")) {
		const char* extension("VK_NV_memory_decompression");
		VkPhysicalDeviceMemoryDecompressionFeaturesNV* extFeatures = new VkPhysicalDeviceMemoryDecompressionFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "memoryDecompression", extFeatures->memoryDecompression);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_linear_color_attachment")) {
		const char* extension("VK_NV_linear_color_attachment");
		VkPhysicalDeviceLinearColorAttachmentFeaturesNV* extFeatures = new VkPhysicalDeviceLinearColorAttachmentFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINEAR_COLOR_ATTACHMENT_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "linearColorAttachment", extFeatures->linearColorAttachment);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_optical_flow")) {
		const char* extension("VK_NV_optical_flow");
		VkPhysicalDeviceOpticalFlowFeaturesNV* extFeatures = new VkPhysicalDeviceOpticalFlowFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "opticalFlow", extFeatures->opticalFlow);
		delete extFeatures;
	}
	if (extensionSupported("VK_NV_ray_tracing_invocation_reorder")) {
		const char* extension("VK_NV_ray_tracing_invocation_reorder");
		VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV* extFeatures = new VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_NV;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "rayTracingInvocationReorder", extFeatures->rayTracingInvocationReorder);
		delete extFeatures;
	}
}
void VulkanDeviceInfoExtensions::readPhysicalFeatures_QCOM() {
	VkPhysicalDeviceFeatures2 deviceFeatures2{};
	if (extensionSupported("VK_QCOM_fragment_density_map_offset")) {
		const char* extension("VK_QCOM_fragment_density_map_offset");
		VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM* extFeatures = new VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_FEATURES_QCOM;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "fragmentDensityMapOffset", extFeatures->fragmentDensityMapOffset);
		delete extFeatures;
	}
	if (extensionSupported("VK_QCOM_image_processing")) {
		const char* extension("VK_QCOM_image_processing");
		VkPhysicalDeviceImageProcessingFeaturesQCOM* extFeatures = new VkPhysicalDeviceImageProcessingFeaturesQCOM{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_FEATURES_QCOM;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "textureSampleWeighted", extFeatures->textureSampleWeighted);
		pushFeature2(extension, "textureBoxFilter", extFeatures->textureBoxFilter);
		pushFeature2(extension, "textureBlockMatch", extFeatures->textureBlockMatch);
		delete extFeatures;
	}
	if (extensionSupported("VK_QCOM_tile_properties")) {
		const char* extension("VK_QCOM_tile_properties");
		VkPhysicalDeviceTilePropertiesFeaturesQCOM* extFeatures = new VkPhysicalDeviceTilePropertiesFeaturesQCOM{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_PROPERTIES_FEATURES_QCOM;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "tileProperties", extFeatures->tileProperties);
		delete extFeatures;
	}
	if (extensionSupported("VK_QCOM_multiview_per_view_viewports")) {
		const char* extension("VK_QCOM_multiview_per_view_viewports");
		VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM* extFeatures = new VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_VIEWPORTS_FEATURES_QCOM;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "multiviewPerViewViewports", extFeatures->multiviewPerViewViewports);
		delete extFeatures;
	}
}
void VulkanDeviceInfoExtensions::readPhysicalFeatures_SEC() {
	VkPhysicalDeviceFeatures2 deviceFeatures2{};
	if (extensionSupported("VK_SEC_amigo_profiling")) {
		const char* extension("VK_SEC_amigo_profiling");
		VkPhysicalDeviceAmigoProfilingFeaturesSEC* extFeatures = new VkPhysicalDeviceAmigoProfilingFeaturesSEC{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_AMIGO_PROFILING_FEATURES_SEC;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "amigoProfiling", extFeatures->amigoProfiling);
		delete extFeatures;
	}
}
void VulkanDeviceInfoExtensions::readPhysicalFeatures_VALVE() {
	VkPhysicalDeviceFeatures2 deviceFeatures2{};
	if (extensionSupported("VK_VALVE_mutable_descriptor_type")) {
		const char* extension("VK_VALVE_mutable_descriptor_type");
		VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT* extFeatures = new VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_EXT;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "mutableDescriptorType", extFeatures->mutableDescriptorType);
		delete extFeatures;
	}
	if (extensionSupported("VK_VALVE_descriptor_set_host_mapping")) {
		const char* extension("VK_VALVE_descriptor_set_host_mapping");
		VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE* extFeatures = new VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE{};
		extFeatures->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_SET_HOST_MAPPING_FEATURES_VALVE;
		deviceFeatures2 = initDeviceFeatures2(extFeatures);
		vulkanContext.vkGetPhysicalDeviceFeatures2KHR(handle, &deviceFeatures2);
		pushFeature2(extension, "descriptorSetHostMapping", extFeatures->descriptorSetHostMapping);
		delete extFeatures;
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
