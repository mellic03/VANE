cmake_minimum_required(VERSION 3.5)

project(vgame LANGUAGES CXX)

set(CMAKE_CXX_STANDARD "20")
set(CMAKE_CXX_FLAGS "-Ofast -Wall -Wextra -Wpedantic -Werror -Wno-missing-field-initializers")

add_executable(
    ${PROJECT_NAME}
    "${CMAKE_CURRENT_SOURCE_DIR}/game.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp"
)

target_link_libraries(
    ${PROJECT_NAME} PUBLIC
    vane
    SDL2::SDL2-static
    SDL2::SDL2main
    ${VANE_GLEW_LIBRARIES}
    OpenGL::GL
)

set_target_properties(
    ${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build/vaneproj/"
)
