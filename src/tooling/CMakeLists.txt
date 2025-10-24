cmake_minimum_required(VERSION 3.11)

include_directories(${CMAKE_SOURCE_DIR}/include/)

add_executable(vpart vpart.cpp)
target_link_libraries(vpart PUBLIC vane_full)

add_executable(vpkg vpkg.cpp)
target_link_libraries(vpkg PUBLIC vane_full)

add_executable(vukg vukg.cpp)
target_link_libraries(vukg PUBLIC vane_full)
