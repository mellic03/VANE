cmake_minimum_required(VERSION 3.11)

target_sources(
    vanelib PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/app.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/gl.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/keyboard.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/log.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/mouse.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/platform.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/service.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/window.cpp"
)
