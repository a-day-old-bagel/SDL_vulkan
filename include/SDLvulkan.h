#ifndef _SDL_vulkan_h
#define _SDL_vulkan_h

#include <SDL_video.h>
#include <vulkan/vulkan.h>

#ifdef _WIN32
  #ifdef sldvk_EXPORT_MODE
    #define SDLVK_SHARED_EXPORT __declspec(dllexport)
  #else
    #define SDLVK_SHARED_EXPORT __declspec(dllimport)
  #endif
#else
  #define SDLVK_SHARED_EXPORT
#endif

#ifdef __cplusplus
extern "C" {
#endif

SDL_bool SDLVK_SHARED_EXPORT SDL_GetVulkanInstanceExtensions(unsigned* count, const char** names);
SDL_bool SDLVK_SHARED_EXPORT SDL_CreateVulkanSurface(SDL_Window* window, VkInstance instance, VkSurfaceKHR* surface);

#ifdef __cplusplus
}
#endif

#endif /* _SDL_vulkan_h */