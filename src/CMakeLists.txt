
include_directories("${CMAKE_SOURCE_DIR}/include/")
include_directories("${VANE_EXTERN_INCLUDE_DIR}")
link_directories("${VANE_EXTERN_LIBRARY_DIR}")


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


add_executable(vpart "${CMAKE_CURRENT_SOURCE_DIR}/vpart.cpp")
add_executable(vpkg "${CMAKE_CURRENT_SOURCE_DIR}/vpkg.cpp")
add_executable(vukg "${CMAKE_CURRENT_SOURCE_DIR}/vukg.cpp")
target_link_libraries(vpart PUBLIC vane_common)
target_link_libraries(vpkg PUBLIC vane_common)
target_link_libraries(vukg PUBLIC vane_common)
install(TARGETS vpart vpkg vukg RUNTIME DESTINATION "bin")



add_executable(tccdemo "${CMAKE_SOURCE_DIR}/src/tccdemo.cpp")
target_link_libraries(tccdemo PUBLIC tcc)
target_include_directories(tccdemo PUBLIC ${VANE_EXTERN_INCLUDE_DIR})
install(TARGETS tccdemo RUNTIME DESTINATION "bin")

