# Vulkan Hardware Capability (Viewer) Command Line Utility

This is a headless (command line) application to generate Vulkan implementation reports compatible with https://vulkan.gpuinfo.org.

Unlike the [GUI hardware capability viewer](https://github.com/SaschaWillems/VulkanCapsViewer) this has as little external dependencies (e.g. no Qt) so it can be built and run on a wide variety of platforms.

This tool is mostly aimed at IHVs that run on platforms without a visual UI and with no direct internet access. As such, it doesn't have functionality to directly upload reports. Reports instead need to be uploaded via a web page.

**Note**: If you want to use this tool to upload the reports please contact me.
