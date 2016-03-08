#ifndef _SDL_vulkan_h
#define _SDL_vulkan_h

#include <SDL_video.h>
#include <vulkan/vulkan.h>

SDL_bool SDL_GetVulkanInstanceExtensions(unsigned* count, const char** names);
extern SDL_bool SDL_CreateVulkanSurface(SDL_Window* window, VkInstance instance, VkSurfaceKHR* surface);

#endif /* _SDL_vulkan_h */
