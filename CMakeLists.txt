cmake_minimum_required(VERSION 3.5)

project(vane_test LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build/")
set(CMAKE_CXX_STANDARD "20")

include_directories("${CMAKE_SOURCE_DIR}/include")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/src/")

add_executable(${PROJECT_NAME} vane_test.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC vane_engine)

file(
    COPY        "${CMAKE_CURRENT_SOURCE_DIR}/include/"
    DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/build/include/"
)
