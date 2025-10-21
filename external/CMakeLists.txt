cmake_minimum_required(VERSION 3.5)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib/")

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/GLEW/")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/SDL2-2.32.10/")
