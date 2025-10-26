cmake_minimum_required(VERSION 3.11)

project(vanelib)
find_package(OpenGL REQUIRED)

add_library(vanelib OBJECT)
add_subdirectory("core/")
add_subdirectory("dsa/")
add_subdirectory("gfx/")
add_subdirectory("tooling/")
add_subdirectory("util/")
add_subdirectory("vfs/")
add_subdirectory("world/")

target_compile_features(vanelib PUBLIC cxx_std_20)
target_include_directories(vanelib PRIVATE
    "${CMAKE_SOURCE_DIR}/include/"
    "${CMAKE_SOURCE_DIR}/external/install/include/"
)

target_link_libraries(
    vanelib PRIVATE SDL3 OpenGL::GL GLAD GLM
)

# install(TARGETS vane RUNTIME DESTINATION "bin/")

# install(
#     DIRECTORY "${IMPORTED_LIBDIR}/"
#     DESTINATION "bin/"
#     FILES_MATCHING
#         PATTERN "*.so"
#         PATTERN "*.so.*"
# )

# install(DIRECTORY "${CMAKE_SOURCE_DIR}/vaneroot/" DESTINATION ".")
