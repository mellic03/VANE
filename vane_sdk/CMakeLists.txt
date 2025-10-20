cmake_minimum_required(VERSION 3.5)

set(
    CMAKE_RUNTIME_OUTPUT_DIRECTORY
    "${CMAKE_CURRENT_SOURCE_DIR}/build/"
)

file(
    COPY "${CMAKE_CURRENT_SOURCE_DIR}/gamefolder/"
    DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/build/"
)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include/")
link_directories("${CMAKE_CURRENT_SOURCE_DIR}/lib/")


# ./src/
# add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/src/")

# ./src_example/
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/src_example/")
