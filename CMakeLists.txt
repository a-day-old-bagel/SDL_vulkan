cmake_minimum_required(VERSION 2.8.7)
project(SDL_vulkan)

option(DEV_BUILD "Development Build" OFF)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 0)
set(VERSION_PATCH 0)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

find_package(SDL2 REQUIRED)
find_package(Vulkan REQUIRED)
include_directories(
  ${SDL2_INCLUDE_DIRS}
  ${Vulkan_INCLUDE_DIRS})

find_package(X11_XCB)
if(X11_XCB_FOUND)
  add_definitions(-DHAVE_X11_XCB)
  list(APPEND SUBSYSTEMS [X11])
  include_directories(${X11_XCB_INCLUDE_DIRS})
endif()

include (CheckCCompilerFlag)

if(DEV_BUILD)
  check_c_compiler_flag(-Wall HAVE_Wall)
  if(HAVE_Wall)
    add_compile_options(-Wall)
  endif()

  check_c_compiler_flag(-Werror HAVE_Werror)
  if(HAVE_Wall)
    add_compile_options(-Werror)
  endif()
endif()

check_c_compiler_flag(-std=c99 HAVE_C99)
if(HAVE_C99)
  add_compile_options(-std=c99)
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
install(DIRECTORY include/ DESTINATION include)

add_subdirectory(src)
add_subdirectory(examples)

message(STATUS "Build type: " ${CMAKE_BUILD_TYPE})
message(STATUS "Development mode: " ${DEV_BUILD})
message(STATUS "Subsystems: " ${SUBSYSTEMS})
