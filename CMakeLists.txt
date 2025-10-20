cmake_minimum_required(VERSION 3.5)

project(vane LANGUAGES CXX)
set(CMAKE_CXX_STANDARD "20")
# set(MEMU_OUTPUT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/build/NesEmu")
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${MEMU_OUTPUT_DIR})

find_package(SDL2 REQUIRED)

# include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/src/core/")

# add_executable(
#     vane
#     "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp"
#     ${SOURCES}
# )

add_library(
    ${PROJECT_NAME} STATIC
    $<TARGET_OBJECTS:vane_core>
)

# target_link_libraries(
#     ${PROJECT_NAME} PRIVATE
#     vane_core
# )

# file(
#     COPY
#         "${CMAKE_CURRENT_SOURCE_DIR}/data/"
#     DESTINATION
#         "${MEMU_OUTPUT_DIR}/"
# )
