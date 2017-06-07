add_executable(example example.c)
target_link_libraries(example SDL_vulkan ${SDL2_LIBRARY} ${VULKAN_LIBRARY})
