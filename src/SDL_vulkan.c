#define VK_USE_PLATFORM_XCB_KHR
#include <X11/Xlib-xcb.h>

#include <SDL_vulkan.h>
#include <SDL_syswm.h>

SDL_bool SetNames(unsigned* count, const char** names, unsigned inCount, const char* const* inNames) {
    unsigned capacity = *count;
    *count = inCount;
    if (names) {
        if (capacity < inCount)
            return SDL_FALSE;
        for (unsigned i = 0; i < inCount; ++i)
            names[i] = inNames[i];
    }
    return SDL_TRUE;
}

SDL_bool SDL_GetVulkanInstanceExtensions(unsigned* count, const char** names) {
    const char *driver = SDL_GetCurrentVideoDriver();
    if (!driver) return SDL_FALSE;
    if (!count) return SDL_FALSE;

    if (!strcmp(driver, "x11")) {
        const char* ext[] = { VK_KHR_XCB_SURFACE_EXTENSION_NAME };
        return SetNames(count, names, 1, ext);
    }
    return SDL_FALSE;
}

SDL_bool SDL_CreateVulkanSurface(SDL_Window* window, VkInstance instance, VkSurfaceKHR* surface) {
    SDL_SysWMinfo wminfo;
    SDL_VERSION(&wminfo.version);
    SDL_GetWindowWMInfo(window, &wminfo);

    switch (wminfo.subsystem) {
    case SDL_SYSWM_X11:
        {
            VkXcbSurfaceCreateInfoKHR createInfo;
            createInfo.sType = VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR;
            createInfo.pNext = NULL;
            createInfo.flags = 0;
            createInfo.connection = XGetXCBConnection(wminfo.info.x11.display);
            createInfo.window = wminfo.info.x11.window;

            vkCreateXcbSurfaceKHR(instance, &createInfo, NULL, surface);
            return SDL_TRUE;
        }
    default:
        return SDL_FALSE;
    }
}
