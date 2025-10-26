cmake_minimum_required(VERSION 3.11)

project(VaneEngine)

add_definitions(
    "-DASSIMP_BUILD_TESTS=OFF"
    "-DASSIMP_INSTALL=OFF"
    "-DASSIMP_BUILD_ZLIB=ON"
    "-DGLM_BUILD_TESTS=OFF"
    "-DSDL_SHARED=ON"
    "-DSDL_STATIC=OFF"
    # "-DSDL_LIBC=ON"
    # "-DSDL_TEST_LIBRARY=OFF"
    # "-DSDL_TESTS=OFF"
    # "-DSDL_DISABLE_INSTALL=ON"
    # "-DSDL_DISABLE_INSTALL_DOCS=ON"
)

set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH "$ORIGIN")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_INSTALL_PREFIX}/bin")

find_package(OpenGL REQUIRED)
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/submodule/glad" EXCLUDE_FROM_ALL)
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/submodule/glm" EXCLUDE_FROM_ALL)
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/submodule/SDL3" EXCLUDE_FROM_ALL)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include/")


add_executable(${PROJECT_NAME} "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include/")

target_link_libraries(
    ${PROJECT_NAME} PRIVATE
    SDL3::SDL3 OpenGL::GL glad glm vane_common
    # zlib-static assimp
)

install(
    TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION "bin/"
)

install(
    FILES 
        "${CMAKE_CURRENT_SOURCE_DIR}/vroot/env.sh"
        "${CMAKE_CURRENT_SOURCE_DIR}/vroot/vane.cfg"
    DESTINATION "."
)

# set(VANE_SHARED_EXT ${CMAKE_SHARED_LIBRARY_SUFFIX})
# set(VANE_STATIC_EXT ${CMAKE_STATIC_LIBRARY_SUFFIX})
# set(IMPORTED_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/external/${CMAKE_BUILD_TYPE}/lib/")
# set(IMPORTED_LIBRARY_DIR "${CMAKE_SOURCE_DIR}/external/${CMAKE_BUILD_TYPE}/include/")

# macro (VaneImport libtype libname filename)
#     if(NOT DEFINED filename)
#         set(filename lib${libname})
#     endif()

#     if(${libtype} STREQUAL "STATIC")
#         set(filename ${filename}${CMAKE_STATIC_LIBRARY_SUFFIX})
#     elseif(${libtype} STREQUAL "SHARED")
#         set(filename ${filename}${CMAKE_SHARED_LIBRARY_SUFFIX})
#     else()
#         message(FATAL_ERROR "Invalid libtype ${libtype}")
#     endif()

#     add_library(${libname} ${libtype} IMPORTED)
#     set_target_properties(
#         ${libname} PROPERTIES
#         IMPORTED_LOCATION "${IMPORTED_LIBRARY_DIR}/${filename}"
#         INTERFACE_INCLUDE_DIRECTORIES "${IMPORTED_INCLUDE_DIR}"
#     )
# endmacro()

# VaneImport(SHARED assimp libassimpd)
# VaneImport(STATIC zlib-static libzlibstaticd)
# VaneImport(STATIC GLAD libGLAD)
# VaneImport(STATIC GLM libglm)
# VaneImport(SHARED SDL3 libSDL3)
# VaneImport(STATIC SDL3-static libSDL3)
# include_directories("${IMPORTED_INCLUDE_DIR}")
