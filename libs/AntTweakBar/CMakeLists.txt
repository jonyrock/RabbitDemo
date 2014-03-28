file(GLOB SRCS src/*.cpp)
file(GLOB SRCS_C src/*.c)

include_directories(../include)

set(CMAKE_CXX_FLAGS "-Wall -fPIC -fno-strict-aliasing -D_UNIX -D__PLACEMENT_NEW_INLINE")

add_library(AntTweakBar ${SRCS} ${SRCS_C})
target_link_libraries(AntTweakBar)

