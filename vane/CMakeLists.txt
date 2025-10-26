cmake_minimum_required(VERSION 3.11)

set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH "$ORIGIN")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include/")

add_library(vanelib OBJECT)
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/src/core/")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/src/dsa/")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/src/gfx/")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/src/util/")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/src/vfs/")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/src/vanetools/")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/src/world/")
target_compile_features(vanelib PUBLIC cxx_std_20)
target_include_directories(vanelib PRIVATE "${CMAKE_SOURCE_DIR}/include/")
target_link_libraries(vanelib PRIVATE SDL3::SDL3 OpenGL::GL glad glm)


add_executable(vane "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")
target_compile_features(vane PUBLIC cxx_std_20)
target_include_directories(vane PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include/")


target_link_libraries(
    vane PRIVATE
    SDL3::SDL3 OpenGL::GL glad glm vanelib
    # zlib-static assimp)\
)

install(
    TARGETS vane
    RUNTIME DESTINATION "bin/"
)

# Install an executable target and its external runtime dependencies
install(
    TARGETS vane
    RUNTIME_DEPENDENCIES DESTINATION "bin/"
)

install(
    DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/vaneroot/"
    DESTINATION "."
)

