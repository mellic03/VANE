cmake_minimum_required(VERSION 3.11)

project(GLAD)
add_library(GLAD STATIC "src/glad.c")
target_include_directories(GLAD PUBLIC "include/")

install(
    TARGETS GLAD
    RUNTIME DESTINATION "bin/"
    LIBRARY DESTINATION "bin/"
    ARCHIVE DESTINATION "lib/"
    INCLUDES DESTINATION "include/"
)

install(
    DIRECTORY "include/"
    DESTINATION "include/"
)
