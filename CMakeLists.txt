cmake_minimum_required(VERSION 3.5)

set(VANE_SDK_DIRECTORY "${CMAKE_SOURCE_DIR}/build/vane_sdk/")
set(VANE_PROJ_DIRECTORY "${CMAKE_SOURCE_DIR}/build/vaneproj/")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${VANE_SDK_DIRECTORY}/lib/")

include_directories("${CMAKE_SOURCE_DIR}/include")

add_subdirectory("${CMAKE_SOURCE_DIR}/src/")
add_subdirectory("${CMAKE_SOURCE_DIR}/vane_sdk/")
add_subdirectory("${CMAKE_SOURCE_DIR}/vaneproj/")
