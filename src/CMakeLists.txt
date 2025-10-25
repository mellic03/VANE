# cmake_minimum_required(VERSION 3.11)

# add_compile_options(--std=c++20 -fPIC ${VANE_COMPILE_OPTIONS})

# add_library(vane_core OBJECT)
# add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/core/")

# add_library(vane_full STATIC $<TARGET_OBJECTS:vane_core>)
# add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/dsa/")
# add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/gfx/")
# # add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/tooling/")
# add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/util/")
# add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/vfs/")
# add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/world/")
# target_link_libraries(vane_full PUBLIC vane_core ${SDL2_OPENGL_LIBRARIES})

# add_executable(vane main.cpp $<TARGET_OBJECTS:vane_core> $<TARGET_OBJECTS:vane_full>)
# target_link_libraries(vane PUBLIC vane_full ${SDL2_OPENGL_LIBRARIES})
