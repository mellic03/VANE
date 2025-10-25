cmake_minimum_required(VERSION 3.11)

project(GLEW)

add_library(GLEW-static STATIC src/glew.c)
target_include_directories(GLEW-static PRIVATE "include/")
target_link_libraries(GLEW-static PRIVATE OpenGL::GL)

file(COPY "include" DESTINATION "${GLEW_BINARY_DIR}/")
