cmake_minimum_required(VERSION 2.8.11)
project(SDL_vulkan)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 0)
set(VERSION_PATCH 0)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

find_package(SDL2 REQUIRED)
find_package(Vulkan REQUIRED)
find_package(X11_XCB)
include_directories(
  ${SDL2_INCLUDE_DIRS}
  ${Vulkan_INCLUDE_DIRS}
  ${X11_XCB_INCLUDE_DIRS})

set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-Wall -Werror")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
install(DIRECTORY include/ DESTINATION include)

add_subdirectory(src)
add_subdirectory(examples)
