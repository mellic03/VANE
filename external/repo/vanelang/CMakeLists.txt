cmake_minimum_required(VERSION 3.21)

project(vanevm)

set(VVM_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${VVM_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${VVM_BINARY_DIR}/lib")

add_library(vanevm SHARED "${CMAKE_CURRENT_SOURCE_DIR}/src/vvm.cpp")
add_library(vanevm::vanevm ALIAS vanevm)

target_include_directories(
    vanevm PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

install(
    DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include/"
    DESTINATION "include"
    FILES_MATCHING
        PATTERN "*.hpp"
        PATTERN "*.h"
)

install(
    TARGETS vanevm EXPORT vanevmConfig
    RUNTIME DESTINATION "bin"
    LIBRARY DESTINATION "lib"
    ARCHIVE DESTINATION "lib"
)

install(
    EXPORT vanevmConfig
    FILE vanevmConfig.cmake
    NAMESPACE vanevm::
    DESTINATION lib/cmake/vanevm
)
