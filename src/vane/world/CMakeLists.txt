cmake_minimum_required(VERSION 3.11)

project(vane_world LANGUAGES CXX)

add_library(
    ${PROJECT_NAME} OBJECT
    "${CMAKE_CURRENT_SOURCE_DIR}/object.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/scene.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/world.cpp"
)
