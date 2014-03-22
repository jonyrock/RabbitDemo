set(CMAKE_C_FLAGS "-Wall -g")

set(EXE "rabbitDemo")

file(GLOB SRCS *.cpp)

set(OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR}/..)
set(EXECUTABLE_OUTPUT_PATH ${OUTPUT_DIR} CACHE PATH "Build directory" FORCE)

add_executable(${EXE} ${SRCS})

target_link_libraries(${EXE} GL GLEW glfw)