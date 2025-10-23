cmake_minimum_required(VERSION 3.11)


add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/GLEW/")
file(
    COPY "${CMAKE_CURRENT_SOURCE_DIR}/GLEW/include/GL"
    DESTINATION "${VANE_INCLUDE_DIR}/"
)


# add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/SDL2/")
# file(
#     COPY
#         "${SDL2_BINARY_DIR}/include/SDL2"
#         "${SDL2_BINARY_DIR}/include-config-release/SDL2"
#     DESTINATION
#         "${VANE_INCLUDE_DIR}/"
# )
