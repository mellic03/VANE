cmake_minimum_required(VERSION 3.21)

target_sources(
    vane_common PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/node.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/tree.cpp"
)
