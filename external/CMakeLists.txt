cmake_minimum_required(VERSION 3.11)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${VANE_OUTPUT_DIR}/bin/thirdparty")

add_subdirectory("glew" EXCLUDE_FROM_ALL)
add_subdirectory("SDL2" EXCLUDE_FROM_ALL)
