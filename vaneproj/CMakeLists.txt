cmake_minimum_required(VERSION 3.5)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build/vaneproj/")

include_directories("${CMAKE_SOURCE_DIR}/include/")
link_directories("${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/")

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/src/")

file(
    COPY "${CMAKE_SOURCE_DIR}/vanepkg/"
    DESTINATION "${CMAKE_SOURCE_DIR}/build/vaneproj/"
)

