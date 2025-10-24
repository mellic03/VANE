cmake_minimum_required(VERSION 3.11)

project(GLEW)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include/")

add_library(GLEW-static STATIC src/glew.c)
target_compile_features(GLEW-static PUBLIC cxx_std_20)
target_compile_options(GLEW-static PUBLIC ${VANE_COMPILE_OPTIONS})
set_target_properties(GLEW-static PROPERTIES OUTPUT_NAME "GLEW")

add_library(GLEW SHARED src/glew.c)
target_compile_features(GLEW PUBLIC cxx_std_20)
target_compile_options(GLEW PUBLIC -fPIC ${VANE_COMPILE_OPTIONS})
set_target_properties(GLEW PROPERTIES OUTPUT_NAME "GLEW")


file(COPY "include/GL" DESTINATION "${GLEW_BINARY_DIR}/include/")
