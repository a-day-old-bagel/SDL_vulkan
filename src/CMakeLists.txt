add_library(SDL_vulkan SHARED SDL_vulkan.c)
set_target_properties(SDL_vulkan PROPERTIES
  VERSION ${VERSION_MAJOR})
target_link_libraries(SDL_vulkan
  ${SDL2_LIBRARIES}
  ${Vulkan_LIBRARIES}
  ${X11_XCB_LIBRARIES})
install(TARGETS SDL_vulkan DESTINATION lib)
