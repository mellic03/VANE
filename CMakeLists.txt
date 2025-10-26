cmake_minimum_required(VERSION 3.11)
cmake_policy(SET CMP0095 OLD) # CMake>=3.16 handles $ORIGIN escaping differently

project(vane)

set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH "$ORIGIN")
set(VANE_SHARED_EXT ${CMAKE_SHARED_LIBRARY_SUFFIX})
set(VANE_STATIC_EXT ${CMAKE_STATIC_LIBRARY_SUFFIX})
set(IMPORTED_LIBDIR "${CMAKE_SOURCE_DIR}/external/install/lib/")
set(IMPORTED_INCDIR "${CMAKE_SOURCE_DIR}/external/install/include/")
set(VANE_SHARED_DEPENDENCIES "${IMPORTED_LIBDIR}/libassimp.so")


find_package(OpenGL REQUIRED)

add_library(assimp SHARED IMPORTED)
set_target_properties(assimp PROPERTIES
    IMPORTED_LOCATION "${IMPORTED_LIBDIR}/libassimp.so"
    INTERFACE_INCLUDE_DIRECTORIES "${IMPORTED_INCDIR}"
)

add_library(GLAD STATIC IMPORTED)
set_target_properties(GLAD PROPERTIES
    IMPORTED_LOCATION "${IMPORTED_LIBDIR}/libGLAD.a"
    INTERFACE_INCLUDE_DIRECTORIES "${IMPORTED_INCDIR}"
)

add_library(GLM STATIC IMPORTED)
set_target_properties(GLM PROPERTIES
    IMPORTED_LOCATION "${IMPORTED_LIBDIR}/libglm.a"
    INTERFACE_INCLUDE_DIRECTORIES "${IMPORTED_INCDIR}"
)

add_library(SDL3 SHARED IMPORTED)
set_target_properties(SDL3 PROPERTIES
    IMPORTED_LOCATION "${IMPORTED_LIBDIR}/libSDL3.so"
    INTERFACE_INCLUDE_DIRECTORIES "${IMPORTED_INCDIR}"
)

add_library(SDL3-static STATIC IMPORTED)
set_target_properties(SDL3-static PROPERTIES
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
    vane PUBLIC SDL3 OpenGL::GL GLAD GLM assimp
)

install(TARGETS vane RUNTIME DESTINATION "bin/")

install(
    DIRECTORY "${IMPORTED_LIBDIR}/"
    DESTINATION "bin/"
    FILES_MATCHING
        PATTERN "*.so"
        PATTERN "*.so.*"
)

install(DIRECTORY "${CMAKE_SOURCE_DIR}/vaneroot/" DESTINATION ".")
