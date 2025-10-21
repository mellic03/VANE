cmake_minimum_required(VERSION 3.5)

project(vane_core LANGUAGES CXX)

file(
    GLOB SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/cfgparser.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/file.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/log.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/object.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/scene.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/scenegroup.cpp"
)

add_library(
    ${PROJECT_NAME} OBJECT
    ${SOURCES}
)
