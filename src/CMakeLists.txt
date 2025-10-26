project(vane_common)
include_directories( "${CMAKE_SOURCE_DIR}/include/")

add_library(vane_common OBJECT)
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/core/")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/dsa/")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/gfx/")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/util/")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/vfs/")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/world/")

target_compile_features(vane_common PUBLIC cxx_std_20)
target_link_libraries(
    vane_common PUBLIC
    glad OpenGL::GL glm
    SDL3::SDL3-shared
    # vane_common PUBLIC glad OpenGL::GL "${CMAKE_SOURCE_DIR}/external/install/lib/libSDL3.so" glm
)


project(vanetools VERSION ${VANE_VERSION})
include_directories( "${CMAKE_SOURCE_DIR}/include/")

add_executable(vpart "${CMAKE_CURRENT_SOURCE_DIR}/vpart.cpp")
add_executable(vpkg "${CMAKE_CURRENT_SOURCE_DIR}/vpkg.cpp")
add_executable(vukg "${CMAKE_CURRENT_SOURCE_DIR}/vukg.cpp")

target_link_libraries(vpart PUBLIC vane_common)
target_link_libraries(vpkg PUBLIC vane_common)
target_link_libraries(vukg PUBLIC vane_common)

install(
    TARGETS vpart vpkg vukg
    RUNTIME DESTINATION "bin/"
)
