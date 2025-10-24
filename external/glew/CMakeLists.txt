cmake_minimum_required(VERSION 3.11)

project(GLEW)

set(GLEW_INCLUDE_DIRS "${GLEW_BINARY_DIR}/include")
file(COPY "include" DESTINATION "${GLEW_BINARY_DIR}/")

add_library(GLEW SHARED src/glew.c)
target_link_libraries(GLEW PUBLIC ${OPENGL_LIBRARIES})

