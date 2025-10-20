cmake_minimum_required(VERSION 3.5)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build/vaneproj/lib")

file(
    COPY "${CMAKE_SOURCE_DIR}/vane_sdk/"
    DESTINATION "${CMAKE_SOURCE_DIR}/build/vaneproj/"
)

file(
    COPY "${CMAKE_SOURCE_DIR}/include/"
    DESTINATION "${CMAKE_SOURCE_DIR}/build/vaneproj/include/"
)

include_directories("${CMAKE_SOURCE_DIR}/include")
add_subdirectory("${CMAKE_SOURCE_DIR}/src/")
