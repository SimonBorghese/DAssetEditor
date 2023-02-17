cmake_minimum_required(VERSION 3.0.0)

project(DAsset VERSION 1.0)


file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(DAsset ${SOURCES} extern/src/glad.c )

# Set their include directories or something
target_include_directories(DAsset PUBLIC extern/include)
target_include_directories(DAsset PUBLIC src)

# link the libraries
target_link_libraries(DAsset SDL2 GL X11 pthread Xrandr Xi dl)


include_directories("/usr/include")
include_directories(${CMAKE_SOURCE_DIR})
include_directories("extern")


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror -g")
