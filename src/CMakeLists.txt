set(CMAKE_C_FLAGS "-Wall -g")

set(EXE "rabbitDemo")

file(GLOB SRCS *.cpp)

set(OUTPUT_DIR ../)
set(EXECUTABLE_OUTPUT_PATH ${OUTPUT_DIR} CACHE PATH "Build directory" FORCE)

add_executable(${EXE} ${SRCS})


# LIBS 
file(MAKE_DIRECTORY "${PROJECT_BINARY_DIR}/libs/")
set(AntTweakBar "${PROJECT_BINARY_DIR}/libs/libAntTweakBar.a")
add_custom_command(
	OUTPUT ${AntTweakBar}
	COMMAND rm -rf ../lib
	COMMAND mkdir ../lib
	COMMAND make
	COMMAND mv ../lib/libAntTweakBar.a ${AntTweakBar}
	COMMAND rm -rf ../lib
	COMMAND make clean
	WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/libs/AntTweakBar/src/"
)

add_custom_target(
	AntTweakBar
	DEPENDS ${AntTweakBar}
)

target_link_libraries(${EXE} glfw GL GLEW)
target_link_libraries(${EXE} ${AntTweakBar})

add_dependencies(${EXE} AntTweakBar)