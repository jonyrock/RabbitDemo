file(GLOB SRCS *.cpp)
file(GLOB INCS *.cpp)
add_library(src OBJECT ${SRCS} ${INCS})
