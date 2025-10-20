cmake_minimum_required(VERSION 3.5)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build/")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../build/vaneproj/include/")
link_directories("${CMAKE_CURRENT_SOURCE_DIR}/../build/vaneproj/lib/")

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/src/")
