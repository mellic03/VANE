cmake_minimum_required(VERSION 3.11)


project(vpart LANGUAGES CXX)

add_executable(
    ${PROJECT_NAME}
    "${CMAKE_CURRENT_SOURCE_DIR}/vpart.cpp"
)

target_link_libraries(
    ${PROJECT_NAME} PUBLIC
    ${VANE_LIBRARIES}
)



project(vpkg LANGUAGES CXX)

add_executable(
    ${PROJECT_NAME}
    "${CMAKE_CURRENT_SOURCE_DIR}/vpkg.cpp"
)

target_link_libraries(
    ${PROJECT_NAME} PUBLIC
    ${VANE_LIBRARIES}
)
