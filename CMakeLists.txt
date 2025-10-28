cmake_minimum_required(VERSION 3.21)

set(VANE_VERSION 0.0.1)
project(vane VERSION ${VANE_VERSION})
add_definitions(-DVANE_VERSION="${VANE_VERSION}")

set(VANE_INSTALL_DIR "${CMAKE_SOURCE_DIR}/build_d/install_d")
set(VANE_INSTALL_INCLUDE_DIR "${VANE_INSTALL_DIR}/include")
set(VANE_INSTALL_LIBRARY_DIR "${VANE_INSTALL_DIR}/lib")

set(VANE_EXTERN_INSTALL_DIR "${CMAKE_SOURCE_DIR}/external/install_d")
set(VANE_EXTERN_INCLUDE_DIR "${VANE_EXTERN_INSTALL_DIR}/include")
set(VANE_EXTERN_LIBRARY_DIR "${VANE_EXTERN_INSTALL_DIR}/lib")


set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH "$ORIGIN" "${VANE_EXTERN_LIBRARY_DIR}")

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
        IMPORTED_LOCATION "${VANE_EXTERN_LIBRARY_DIR}/${fname}"
        INTERFACE_INCLUDE_DIRECTORIES "${VANE_EXTERN_INCLUDE_DIR}"
    )
endmacro()


include_directories("${CMAKE_SOURCE_DIR}/include/" "${VANE_EXTERN_INCLUDE_DIR}")

find_package(OpenGL REQUIRED)
find_package(assimp REQUIRED PATHS "${VANE_EXTERN_LIBRARY_DIR}/cmake/assimp-6.0" NO_DEFAULT_PATH)
find_package(SDL3 REQUIRED PATHS "${VANE_EXTERN_LIBRARY_DIR}/cmake/SDL3" NO_DEFAULT_PATH)
# find_package(vanevm REQUIRED PATHS "${VANE_EXTERN_LIBRARY_DIR}/cmake/vanevm" NO_DEFAULT_PATH)
VaneImport(STATIC glad libglad)
VaneImport(STATIC glm libglm)

# add_subdirectory("${CMAKE_SOURCE_DIR}/external/submodule/SDL/")
add_subdirectory("${CMAKE_SOURCE_DIR}/src/")

add_executable(VaneEngine "${CMAKE_SOURCE_DIR}/src/main.cpp")
set_target_properties(VaneEngine PROPERTIES OUTPUT_NAME "vane")
target_compile_features(VaneEngine PUBLIC cxx_std_20)

target_link_libraries(
    VaneEngine PRIVATE
    glad vane_common SDL3::SDL3-shared
    assimp::assimp # vanevm::vanevm
)

install(
    TARGETS VaneEngine
    RUNTIME DESTINATION "."
)


file(GLOB VANE_RUNTIME_LIBS "${VANE_EXTERN_LIBRARY_DIR}/*.so*")
install(FILES ${VANE_RUNTIME_LIBS} DESTINATION "bin")
# add_custom_command(
#     OUTPUT vdata.pkg DEPENDS vpkg COMMENT "Packing root vdata.pkg"
#     COMMAND $<TARGET_FILE:vpkg> -i ${CMAKE_SOURCE_DIR}/vane -o ${CMAKE_INSTALL_PREFIX}/vdata.pkg
# )
# add_custom_target(GenerateFiles ALL DEPENDS vdata.pkg)
