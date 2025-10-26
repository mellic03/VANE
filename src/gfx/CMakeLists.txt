cmake_minimum_required(VERSION 3.21)

target_sources(
    vane_common PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/camera.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/image.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/render.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/shader.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/srv.cpp"
)
