cmake_minimum_required(VERSION 3.21)

project(vane)

set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH "$ORIGIN/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_INSTALL_PREFIX}/bin")

set(VANE_SHARED_EXT ${CMAKE_SHARED_LIBRARY_SUFFIX})
set(VANE_STATIC_EXT ${CMAKE_STATIC_LIBRARY_SUFFIX})
set(IMPORTED_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/external/install/lib/")
set(IMPORTED_LIBRARY_DIR "${CMAKE_SOURCE_DIR}/external/install/include/")

macro (VaneImport libtype libname filename)
    if(NOT DEFINED filename)
        set(filename lib${libname})
    endif()

    if(${libtype} STREQUAL "STATIC")
        set(filename ${filename}${CMAKE_STATIC_LIBRARY_SUFFIX})
    elseif(${libtype} STREQUAL "SHARED")
        set(filename ${filename}${CMAKE_SHARED_LIBRARY_SUFFIX})
    else()
        message(FATAL_ERROR "Invalid libtype ${libtype}")
    endif()

    add_library(${libname} ${libtype} IMPORTED)
    set_target_properties(
        ${libname} PROPERTIES
        IMPORTED_LOCATION "${IMPORTED_LIBRARY_DIR}/${filename}"
        INTERFACE_INCLUDE_DIRECTORIES "${IMPORTED_INCLUDE_DIR}"
    )
endmacro()

VaneImport(SHARED assimp libassimpd)
VaneImport(STATIC zlib-static libzlibstaticd)
VaneImport(STATIC GLAD libGLAD)
VaneImport(STATIC GLM libglm)
VaneImport(SHARED SDL3 libSDL3)
VaneImport(STATIC SDL3-static libSDL3)
include_directories("${IMPORTED_INCLUDE_DIR}")


find_package(OpenGL REQUIRED)

# include(ExternalProject)

# ExternalProject_Add(
#     glm
#     SOURCE_DIR
#         "${CMAKE_SOURCE_DIR}/external/build/release/glm"
#     CMAKE_ARGS
#         -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
#         -DBUILD_SHARED_LIBS=OFF -DGLM_BUILD_TESTS=OFF
# )

# ExternalProject_Add(
#     SDL3
#     SOURCE_DIR
#         "${CMAKE_SOURCE_DIR}/external/build/release/SDL3"
#     HEADER_DIRS
#         "${CMAKE_SOURCE_DIR}/external/build/release/SDL3"
#     CMAKE_ARGS
#         -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
#         -DSDL_SHARED=ON -DSDL_STATIC=OFF -DSDL_LIBC=ON
# )

# ExternalProject_Add(
#     assimp
#     SOURCE_DIR
#         "${CMAKE_SOURCE_DIR}/external/build/release/assimp"
#     CMAKE_ARGS
#         -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
#         -DBUILD_SHARED_LIBS=ON
#         -DASSIMP_BUILD_TESTS=OFF
#         -DASSIMP_INSTALL=OFF
#         -DASSIMP_BUILD_ZLIB=ON
# )
# add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/external/repo/glad" EXCLUDE_FROM_ALL)


add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/src/")

add_executable(VaneEngine "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")
include_directories("${CMAKE_SOURCE_DIR}/include/")
set_target_properties(VaneEngine PROPERTIES OUTPUT_NAME "vane")
target_compile_features(VaneEngine PUBLIC cxx_std_20)
target_link_libraries(VaneEngine PRIVATE vane_common SDL3::SDL3 assimp::assimp)


install(TARGETS VaneEngine RUNTIME DESTINATION ".")
# install(TARGETS SDL3-shared RUNTIME DESTINATION "bin/")

add_custom_command(
    OUTPUT vdata.pkg
    COMMAND $<TARGET_FILE:vpkg> -i ${CMAKE_SOURCE_DIR}/vane -o $<TARGET_FILE_DIR:VaneEngine>/vdata.pkg
    DEPENDS vpkg #
    COMMENT "Running vpkg to create vdata.pkg"
)
add_custom_target(GenerateFiles ALL DEPENDS vdata.pkg)
