cmake_minimum_required(VERSION 3.11)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${VANE_OUTPUT_DIR}/bin/srv")

project(vproj_game)

add_executable(vgame main.cpp main.cpp)
target_compile_features(vgame PUBLIC cxx_std_20)
target_compile_options(vgame PRIVATE ${VANE_COMPILE_OPTIONS})
target_link_libraries(vgame PUBLIC vane_full ${SDL2_OPENGL_LIBRARIES})


project(vproj_srv)

add_library(srv-gfx SHARED srv-gfx.cpp)
target_compile_features(srv-gfx PUBLIC cxx_std_20)
target_compile_options(srv-gfx PRIVATE ${VANE_COMPILE_OPTIONS})
target_link_libraries(srv-gfx PUBLIC vane_core ${SDL2_OPENGL_LIBRARIES})

add_library(srv-game SHARED srv-game.cpp)
target_compile_features(srv-game PUBLIC cxx_std_20)
target_compile_options(srv-game PRIVATE ${VANE_COMPILE_OPTIONS})
target_link_libraries(srv-game PUBLIC vane_core ${SDL2_OPENGL_LIBRARIES})


set(qual ${PROJECT_NAME}-${PROJECT_VERSION})

install(
    TARGETS vproj_game vproj_srv EXPORT vproj_targets
    RUNTIME DESTINATION "/${qual}"
    ARCHIVE DESTINATION "/${qual}"
    INCLUDES DESTINATION include/${qual}
)
