set( BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE )

set(SDL_LIBC ON CACHE BOOL "" FORCE)
set(SDL_TEST OFF CACHE BOOL "" FORCE)
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/SDL2/")
target_link_libraries(vane SDL2::SDL2main SDL2::SDL2-static)


add_compile_definitions(GLEW_STATIC)
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/glew/")
target_link_libraries(vane GLEW)


# if(CMAKE_BUILD_TYPE STREQUAL "Debug")
#     file(
#         COPY "${SDL2_BINARY_DIR}/include-config-debug/"
#         DESTINATION "${SDL2_BINARY_DIR}/include/"
#     )

# else()
#     file(
#         COPY "${SDL2_BINARY_DIR}/include-config-release/"
#         DESTINATION "${SDL2_BINARY_DIR}/include/"
#     )
# endif()

