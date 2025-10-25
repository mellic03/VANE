cmake_minimum_required(VERSION 3.11)



project(vane)
find_package(OpenGL REQUIRED)
# add_subdirectory("${CMAKE_SOURCE_DIR}/external/submodule/glad/")
# add_subdirectory("${CMAKE_SOURCE_DIR}/external/submodule/glm/")

set(VANE_SHARED_EXT ${CMAKE_SHARED_LIBRARY_SUFFIX})
set(VANE_STATIC_EXT ${CMAKE_STATIC_LIBRARY_SUFFIX})
set(IMPORTED_LIBDIR "${CMAKE_SOURCE_DIR}/external/install/lib/")
set(IMPORTED_INCDIR "${CMAKE_SOURCE_DIR}/external/install/include/")

add_library(ass_imp SHARED IMPORTED)
set_target_properties(ass_imp PROPERTIES
    IMPORTED_LOCATION "${IMPORTED_LIBDIR}/libassimp.so"
    INTERFACE_INCLUDE_DIRECTORIES "${IMPORTED_INCDIR}"
)

add_library(g_lad STATIC IMPORTED)
set_target_properties(g_lad PROPERTIES
    IMPORTED_LOCATION "${IMPORTED_LIBDIR}/libGLAD.a"
    INTERFACE_INCLUDE_DIRECTORIES "${IMPORTED_INCDIR}"
)

add_library(g_lm STATIC IMPORTED)
set_target_properties(g_lm PROPERTIES
    IMPORTED_LOCATION "${IMPORTED_LIBDIR}/libglm.a"
    INTERFACE_INCLUDE_DIRECTORIES "${IMPORTED_INCDIR}"
)

add_library(sdl_3 STATIC IMPORTED)
set_target_properties(sdl_3 PROPERTIES
    IMPORTED_LOCATION "${IMPORTED_LIBDIR}/libSDL3.a"
    INTERFACE_INCLUDE_DIRECTORIES "${IMPORTED_INCDIR}"
)


add_executable(vane "src/main.cpp")
add_subdirectory("src/core/")
add_subdirectory("src/dsa/")
add_subdirectory("src/gfx/")
add_subdirectory("src/util/")
add_subdirectory("src/vfs/")
add_subdirectory("src/world/")

target_compile_features(vane PUBLIC cxx_std_20)
target_include_directories(vane PRIVATE
    "${CMAKE_SOURCE_DIR}/include/"
    "${CMAKE_SOURCE_DIR}/external/install/include/"
)

target_link_libraries(
    vane PRIVATE sdl_3 OpenGL::GL g_lad g_lm ass_imp
)


install(TARGETS vane RUNTIME DESTINATION "bin/")
# install(TARGETS vane LIBRARY DESTINATION "bin/")

install(DIRECTORY "${CMAKE_SOURCE_DIR}/vaneroot/" DESTINATION ".")
