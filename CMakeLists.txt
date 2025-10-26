cmake_minimum_required(VERSION 3.21)

set(VANE_VERSION 0.0.1)
project(vane VERSION ${VANE_VERSION})
add_definitions(-DVANE_VERSION="${VANE_VERSION}")

set(VANE_SHARED_EXT ${CMAKE_SHARED_LIBRARY_SUFFIX})
set(VANE_STATIC_EXT ${CMAKE_STATIC_LIBRARY_SUFFIX})
set(IMPORTED_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/external/install/include")
set(IMPORTED_LIBRARY_DIR "${CMAKE_SOURCE_DIR}/external/install/lib")

set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH
    "$ORIGIN"
    "${IMPORTED_LIBRARY_DIR}"
)

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


include_directories("${CMAKE_SOURCE_DIR}/include/" "${IMPORTED_INCLUDE_DIR}")

find_package(OpenGL REQUIRED)
find_package(assimp REQUIRED PATHS "${IMPORTED_LIBRARY_DIR}/cmake/assimp-6.0" NO_DEFAULT_PATH)
find_package(SDL3 REQUIRED PATHS "${IMPORTED_LIBRARY_DIR}/cmake/SDL3" NO_DEFAULT_PATH)
VaneImport(SHARED glad libglad)
VaneImport(SHARED glm libglm)

# add_subdirectory("${CMAKE_SOURCE_DIR}/external/repo/SDL3/")
add_subdirectory("${CMAKE_SOURCE_DIR}/src/")

add_executable(VaneEngine "${CMAKE_SOURCE_DIR}/src/main.cpp")
set_target_properties(VaneEngine PROPERTIES OUTPUT_NAME "vane")
target_compile_features(VaneEngine PUBLIC cxx_std_20)
target_link_libraries(VaneEngine PUBLIC glad vane_common SDL3::SDL3-shared assimp::assimp)

file(
    COPY "${IMPORTED_LIBRARY_DIR}/libglad.so"
         "${IMPORTED_LIBRARY_DIR}/libglm.so"
    DESTINATION "${CMAKE_INSTALL_PREFIX}/bin"
)

add_custom_command(
    OUTPUT vdata.pkg DEPENDS vpkg COMMENT "Packing root vdata.pkg"
    COMMAND $<TARGET_FILE:vpkg> -i ${CMAKE_SOURCE_DIR}/vane -o ${CMAKE_INSTALL_PREFIX}/vdata.pkg
)
add_custom_target(GenerateFiles ALL DEPENDS vdata.pkg)


install(TARGETS VaneEngine RUNTIME DESTINATION ".")
# install(TARGETS SDL3-shared LIBRARY DESTINATION "bin")
install(FILES $<TARGET_RUNTIME_DLLS:VaneEngine> DESTINATION "bin")

install(
    FILES
        "${IMPORTED_LIBRARY_DIR}/libglad.so"
        "${IMPORTED_LIBRARY_DIR}/libglm.so"
    DESTINATION "bin"
)

install(FILES ${resolved_deps} DESTINATION ${CMAKE_INSTALL_BINDIR})

