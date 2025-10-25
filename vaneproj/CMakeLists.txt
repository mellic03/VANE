cmake_minimum_required(VERSION 3.11)

# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${VANE_OUTPUT_DIR}/bin/srv")

# add_executable(vgame main.cpp main.cpp)
# target_compile_features(vgame PUBLIC cxx_std_20)
# target_compile_options(vgame PRIVATE ${VANE_COMPILE_OPTIONS})
# target_link_libraries(vgame PUBLIC vane_full ${SDL2_OPENGL_LIBRARIES})

add_library(srv-gfx SHARED srv-gfx.cpp)
target_link_libraries(srv-gfx PUBLIC vane_full GLEW SDL2::SDL2main SDL2::SDL2)

add_library(srv-game SHARED srv-game.cpp)
target_link_libraries(srv-game PUBLIC vane_full GLEW SDL2::SDL2main SDL2::SDL2)

