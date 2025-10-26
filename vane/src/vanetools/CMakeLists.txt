cmake_minimum_required(VERSION 3.11)
# include_directories(${CMAKE_SOURCE_DIR}/include/)

project(vanetools)

add_executable(vpart vpart.cpp)
target_link_libraries(vpart PUBLIC vanelib)

add_executable(vpkg vpkg.cpp)
target_link_libraries(vpkg PUBLIC vanelib)

add_executable(vukg vukg.cpp)
target_link_libraries(vukg PUBLIC vanelib)


install(
    TARGETS vpart vpkg vukg
    RUNTIME DESTINATION "bin/"
)
