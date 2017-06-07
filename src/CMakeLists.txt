
if(NOT WIN32)
  add_checked_flag(-fPIC fPIC)
endif()

add_library(SDL_vulkan SHARED SDL_vulkan.c)
set_target_properties(SDL_vulkan PROPERTIES
  VERSION ${VERSION_MAJOR})
target_link_libraries(SDL_vulkan
  ${SDL2_LIBRARY}
  ${VULKAN_LIBRARY}
  ${X11_XCB_LIBRARIES})
target_include_directories(SDL_vulkan PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/../include
  ${SDL2_INCLUDE_DIR}
  ${VULKAN_INCLUDE_DIR})
install(TARGETS SDL_vulkan DESTINATION lib)
