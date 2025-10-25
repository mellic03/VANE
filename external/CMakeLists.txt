project(vane_external)

find_package(OpenGL REQUIRED)
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/submodule/glad/")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/submodule/glm/")

set(VANE_SHARED_EXT ${CMAKE_SHARED_LIBRARY_SUFFIX})
set(VANE_STATIC_EXT ${CMAKE_STATIC_LIBRARY_SUFFIX})
set(IMPORTED_LIBDIR "${CMAKE_SOURCE_DIR}/external/install/lib/")
set(IMPORTED_INCDIR "${CMAKE_SOURCE_DIR}/external/install/include/")

add_library(ass_imp SHARED IMPORTED)
set_target_properties(ass_imp PROPERTIES
    IMPORTED_LOCATION "${IMPORTED_LIBDIR}/libassimp.so"
    INTERFACE_INCLUDE_DIRECTORIES "${IMPORTED_INCDIR}"
)

add_library(sdl_3 STATIC IMPORTED)
set_target_properties(sdl_3 PROPERTIES
    IMPORTED_LOCATION "${IMPORTED_LIBDIR}/libSDL3.a"
    INTERFACE_INCLUDE_DIRECTORIES "${IMPORTED_INCDIR}"
)


# macro(SharedLibThing tgtname libname)
#     add_library(${tgtname} SHARED IMPORTED)
#     set_target_properties(${tgtname} PROPERTIES
#         IMPORTED_LOCATION "${IMPORTED_LIBDIR}/lib${libname}${VANE_SHARED_EXT}"
#         INTERFACE_INCLUDE_DIRECTORIES ${IMPORTED_INCDIR}
#     )
# endmacro()

# macro(StaticLibThing libname)
#     add_library(${libname} STATIC IMPORTED)
#     set_target_properties(${libname} PROPERTIES
#         IMPORTED_LOCATION "${IMPORTED_LIBDIR}/lib${libname}${VANE_STATIC_EXT}"
#         INTERFACE_INCLUDE_DIRECTORIES ${IMPORTED_INCDIR}
#     )
# endmacro()
