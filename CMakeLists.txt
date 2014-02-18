cmake_minimum_required(VERSION 2.8.0)

project(RabbitDemo)

set(RabbitDemo_VERSION_MAJOR 0)
set(RabbitDemo_VERSION_MINOR 1)

set(CMAKE_CXX_FLAGS "-std=c++0x")

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
message("Please check out that you have a proper GLFW installation.")
# find_package(GLFW REQUIRED)

include_directories(include)

add_subdirectory(src)