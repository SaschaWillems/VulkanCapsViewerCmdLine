cmake_minimum_required (VERSION 3.8)

project ("VulkanCapsViewerCmdLine")

file(GLOB SOURCE ./*.cpp)
file(GLOB HEADERS ./*.h)

include_directories("external")
include_directories("Vulkan-Headers/include")

if(WIN32)
    find_library(Vulkan_LIBRARY NAMES vulkan-1 HINTS "$ENV{VULKAN_SDK}/lib" "${CMAKE_SOURCE_DIR}/libs/vulkan" REQUIRED)
else()
find_library(Vulkan_LIBRARY NAMES vulkan HINTS "$ENV{VULKAN_SDK}/lib" "${CMAKE_SOURCE_DIR}/libs/vulkan" REQUIRED)
endif()

# Add source to this project's executable.
add_executable (VulkanCapsViewerCmdLine ${SOURCE} ${HEADERS})

target_link_libraries(VulkanCapsViewerCmdLine ${Vulkan_LIBRARY})

target_compile_definitions(VulkanCapsViewerCmdLine PRIVATE VK_ENABLE_BETA_EXTENSIONS)