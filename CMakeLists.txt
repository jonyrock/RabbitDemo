cmake_minimum_required(VERSION 2.8.0)

project(RabbitDemo)

set(RabbitDemo_VERSION_MAJOR 0)
set(RabbitDemo_VERSION_MINOR 1)

set(CMAKE_CXX_FLAGS "-std=c++0x -Wall -g")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

set(EXE "rabbitDemo")

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(GLM REQUIRED)
find_package(GLFW REQUIRED)

include_directories(include)
include_directories(libs/AntTweakBar/include/)

file(COPY res DESTINATION .)

add_subdirectory(libs)
add_subdirectory(src)

add_executable(${EXE} $<TARGET_OBJECTS:src>)

target_link_libraries(${EXE} libs)
target_link_libraries(${EXE} GL X11 GLEW glfw)