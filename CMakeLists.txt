cmake_minimum_required(VERSION 3.5)

project(vane LANGUAGES CXX)

set(CMAKE_CXX_STANDARD "20")
set(CMAKE_CXX_FLAGS
   "-Ofast \
    -Wall -Wextra -Wpedantic -Werror \
    -Wno-missing-field-initializers"
)

find_package(SDL2 REQUIRED)
find_package(GLEW REQUIRED)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/src/core/")

add_library(
    ${PROJECT_NAME} STATIC
    $<TARGET_OBJECTS:vane_core>
)

target_link_libraries(
    ${PROJECT_NAME} PUBLIC
    SDL2::SDL2
    SDL2::SDL2main
    ${GLEW_LIBRARIES}
)



add_executable(
    test
    main.cpp
)

target_link_libraries(
    test PUBLIC
    vane
)

