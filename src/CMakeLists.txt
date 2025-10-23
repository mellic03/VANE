cmake_minimum_required(VERSION 3.11)

if(NOT DEFINED VANE_OUTPUT_DIR)
    message(FATAL_ERROR "VANE_OUTPUT_DIR must be set!")
endif()


project(vane LANGUAGES CXX)

set(CMAKE_CXX_STANDARD "20")
set(CMAKE_CXX_FLAGS "-Ofast -Wall -Wextra -Wpedantic -Werror -Wno-missing-field-initializers")

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/vane/core/")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/vane/gfx/")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/vane/platform/")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/vane/tooling/")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/vane/vfs/")

add_library(
    ${PROJECT_NAME} STATIC
    "${CMAKE_CURRENT_SOURCE_DIR}/vane/vane.cpp"
    $<TARGET_OBJECTS:vane_core>
    $<TARGET_OBJECTS:vane_gfx>
    $<TARGET_OBJECTS:vane_platform>
    $<TARGET_OBJECTS:vane_vfs>
)


file(
    COPY "${CMAKE_CURRENT_SOURCE_DIR}/vaneroot/"
    DESTINATION "${VANE_OUTPUT_DIR}/"
)

