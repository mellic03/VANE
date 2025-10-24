cmake_minimum_required(VERSION 3.11)

target_sources(
    vane_full PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/object.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/scene.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/world.cpp"
)
