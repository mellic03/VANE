cmake_minimum_required(VERSION 3.11)

project(vane)

find_package(OpenGL REQUIRED)
add_subdirectory("external/")

add_executable(vane "src/main.cpp")
add_subdirectory("src/core/")
add_subdirectory("src/dsa/")
add_subdirectory("src/gfx/")
add_subdirectory("src/util/")
add_subdirectory("src/vfs/")
add_subdirectory("src/world/")

target_compile_features(vane PUBLIC cxx_std_20)
target_include_directories(vane PRIVATE "include/")

target_link_libraries(
    vane PRIVATE
    SDL3::SDL3-static OpenGL::GL GLAD glm assimp
)

install(
    TARGETS vane assimp
    RUNTIME DESTINATION "bin/"
    LIBRARY DESTINATION "bin/"
)

install(
    DIRECTORY ${CMAKE_SOURCE_DIR}/vaneroot/
    DESTINATION "."
)




# find_package(OpenGL REQUIRED)

# if(CMAKE_BUILD_TYPE STREQUAL "Debug")
#     set(VANE_OUTPUT_DIR "${CMAKE_BINARY_DIR}/../vane_debug")
# else()
#     set(VANE_OUTPUT_DIR "${CMAKE_BINARY_DIR}/../vane_release")
# endif()

# # set(VANE_COMPILE_OPTIONS -Wno-missing-field-initializers)

# add_subdirectory("${CMAKE_SOURCE_DIR}/external/glew/")

# set(SDL2_OPENGL_LIBRARIES ${OPENGL_LIBRARIES} GLEW SDL2::SDL2)


# include_directories(
#     "${CMAKE_SOURCE_DIR}/include/"
#     "${GLEW_BINARY_DIR}/include/"
#     "${SDL2_BINARY_DIR}/include/"
# )


# add_subdirectory("${CMAKE_SOURCE_DIR}/external/")
# add_subdirectory("${CMAKE_SOURCE_DIR}/src/")
# add_subdirectory("${CMAKE_SOURCE_DIR}/vaneproj/")


# install(TARGETS vane RUNTIME DESTINATION "bin/")
# install(TARGETS vgame ARCHIVE DESTINATION "bin/srv/")
# install(TARGETS srv-gfx srv-game RUNTIME DESTINATION "bin/srv/")

# install(
#     DIRECTORY ${CMAKE_SOURCE_DIR}/vaneroot/
#     DESTINATION "."
# )

