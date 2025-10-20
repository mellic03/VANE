cmake_minimum_required(VERSION 3.5)

project(vaneproj LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build/")
set(CMAKE_CXX_STANDARD "20")

find_package(SDL2 REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

add_executable(
    ${PROJECT_NAME}
    "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/game.cpp"
)

target_link_libraries(
    ${PROJECT_NAME} PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/lib/libvane.a"
    SDL2::SDL2
    SDL2::SDL2main
    GLEW::GLEW
    OpenGL::GL
)
