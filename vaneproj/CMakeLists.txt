cmake_minimum_required(VERSION 3.11)

add_executable(vgame main.cpp main.cpp)
target_compile_features(vgame PUBLIC cxx_std_20)
target_compile_options(vgame PRIVATE ${VANE_COMPILE_OPTIONS})
target_link_libraries(vgame PUBLIC vane_full ${VANE_SDL2_OPENGL_LIBRARIES})


add_library(srv-gfx SHARED srv-gfx.cpp)
target_compile_features(srv-gfx PUBLIC cxx_std_20)
target_compile_options(srv-gfx PRIVATE -fPIC ${VANE_COMPILE_OPTIONS})
target_link_libraries(srv-gfx PUBLIC vane_core GLEW OpenGL::GL SDL2::SDL2main SDL2::SDL2)
set_target_properties(srv-gfx PROPERTIES PREFIX "")

add_library(srv-game SHARED srv-game.cpp)
target_compile_features(srv-game PUBLIC cxx_std_20)
target_compile_options(srv-game PRIVATE -fPIC ${VANE_COMPILE_OPTIONS})
target_link_libraries(srv-game PUBLIC vane_core GLEW OpenGL::GL SDL2::SDL2main SDL2::SDL2)
set_target_properties(srv-game PROPERTIES PREFIX "")
# add_library(vmodule SHARED "${CMAKE_CURRENT_SOURCE_DIR}/game.cpp")

# target_compile_features(vmodule PUBLIC cxx_std_20)
# target_compile_options(vmodule PRIVATE -fPIC -Ofast -Wall -Wextra -Wpedantic -Werror -Wno-missing-field-initializers)

# target_link_libraries(
#     vmodule PUBLIC
#     ${VANE_LIBRARIES}
#     SDL2
#     ${GLEW_LIBRARIES}
#     ${OPENGL_LIBRARIES}
# )
