cmake_minimum_required(VERSION 3.21)

set(VANE_VERSION 0.0.1)
project(vane VERSION ${VANE_VERSION})
add_definitions(-DVANE_VERSION="${VANE_VERSION}")

set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_INSTALL_PREFIX}/bin")
set(CMAKE_INSTALL_RPATH ${CMAKE_INSTALL_PREFIX}/bin)
set(VANE_SHARED_EXT ${CMAKE_SHARED_LIBRARY_SUFFIX})
set(VANE_STATIC_EXT ${CMAKE_STATIC_LIBRARY_SUFFIX})
set(IMPORTED_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/external/install/include")
set(IMPORTED_LIBRARY_DIR "${CMAKE_SOURCE_DIR}/external/install/lib")

macro (VaneImport libtype libname filename)
    if(${libtype} STREQUAL "STATIC")
        set(fname ${filename}${CMAKE_STATIC_LIBRARY_SUFFIX})
    elseif(${libtype} STREQUAL "SHARED")
        set(fname ${filename}${CMAKE_SHARED_LIBRARY_SUFFIX})
    else()
        message(FATAL_ERROR "Invalid libtype ${libtype}")
    endif()
    add_library(${libname} ${libtype} IMPORTED)
    set_target_properties(
        ${libname} PROPERTIES
        IMPORTED_LOCATION "${IMPORTED_LIBRARY_DIR}/${fname}"
        INTERFACE_INCLUDE_DIRECTORIES "${IMPORTED_INCLUDE_DIR}"
    )
endmacro()

find_package(OpenGL REQUIRED)
find_package(assimp PATHS "${CMAKE_SOURCE_DIR}/external/install/lib/cmake/assimp-6.0" NO_DEFAULT_PATHS)

VaneImport(STATIC zlib-static libzlibstatic)
VaneImport(STATIC glad libglad)
VaneImport(STATIC glm libglm)
VaneImport(STATIC SDL3 libSDL3)

include_directories("${IMPORTED_INCLUDE_DIR}")


include_directories("${CMAKE_SOURCE_DIR}/include/")
include_directories("${CMAKE_SOURCE_DIR}/external/install/include/")
link_directories("${CMAKE_SOURCE_DIR}/external/install/lib/")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/src/")
add_executable(VaneEngine "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")
set_target_properties(VaneEngine PROPERTIES OUTPUT_NAME "vane")
target_compile_features(VaneEngine PUBLIC cxx_std_20)
target_link_libraries(VaneEngine PUBLIC vane_common SDL3 assimp::assimp)


install(TARGETS VaneEngine RUNTIME DESTINATION ".")
# install(TARGETS VaneEngine LIBRARY DESTINATION ".")
install(
    FILES
        "${IMPORTED_LIBRARY_DIR}/libassimp.so"
        "${IMPORTED_LIBRARY_DIR}/libassimp.so.6"
        "${IMPORTED_LIBRARY_DIR}/libassimp.so.6.0.2"
    DESTINATION "bin"
)

add_custom_command(
    OUTPUT vdata.pkg
    COMMAND $<TARGET_FILE:vpkg> -i ${CMAKE_SOURCE_DIR}/vane -o ${CMAKE_INSTALL_PREFIX}/vdata.pkg
    DEPENDS vpkg #
    COMMENT "Running vpkg to create vdata.pkg"
)
add_custom_target(GenerateFiles ALL DEPENDS vdata.pkg)
