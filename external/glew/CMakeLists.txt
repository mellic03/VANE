cmake_minimum_required(VERSION 3.11)

project(GLEW)

include_directories("include/")
add_library(GLEW SHARED src/glew.c)

# add_library(GLEW-static STATIC src/glew.c)
# target_compile_features(GLEW-static PUBLIC cxx_std_20)
# target_compile_options(GLEW-static PUBLIC ${VANE_COMPILE_OPTIONS})
# set_target_properties(GLEW-static PROPERTIES OUTPUT_NAME "GLEW")

