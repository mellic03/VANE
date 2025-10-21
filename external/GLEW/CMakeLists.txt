cmake_minimum_required(VERSION 3.11)

project(GLEW)

add_library(
    GLEW STATIC
    "${CMAKE_CURRENT_SOURCE_DIR}/glew.c"
)

set_target_properties(
    GLEW PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib/"
)

file(
    COPY "${CMAKE_CURRENT_SOURCE_DIR}/GL/"
    DESTINATION "${CMAKE_SOURCE_DIR}/include/GL/"
)
