add_library(libs)
add_subdirectory(AntTweakBar)
add_subdirectory (glfw-3.0.3)
target_link_libraries(libs AntTweakBar GLFW_303)