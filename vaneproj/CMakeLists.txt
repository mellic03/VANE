cmake_minimum_required(VERSION 3.11)

project(vgame)

set(CMAKE_CXX_STANDARD "20")
set(CMAKE_CXX_FLAGS "-Ofast -Wall -Wextra -Wpedantic -Werror -Wno-missing-field-initializers")

add_executable(
    ${PROJECT_NAME}
    "${CMAKE_CURRENT_SOURCE_DIR}/game.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp"
)

target_link_libraries(
    ${PROJECT_NAME} PUBLIC
    ${VANE_LIBRARIES}
    ${SDL2_LIBRARIES}
    ${GLEW_LIBRARIES}
    ${OPENGL_LIBRARIES}
)
