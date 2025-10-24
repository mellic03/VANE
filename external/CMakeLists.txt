cmake_minimum_required(VERSION 3.11)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${VANE_OUTPUT_DIR}/bin/thirdparty")

add_subdirectory("glew" EXCLUDE_FROM_ALL)
add_subdirectory("SDL2" EXCLUDE_FROM_ALL)


if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    file(
        COPY "${SDL2_BINARY_DIR}/include-config-debug/"
        DESTINATION "${SDL2_BINARY_DIR}/include/"
    )

else()
    file(
        COPY "${SDL2_BINARY_DIR}/include-config-release/"
        DESTINATION "${SDL2_BINARY_DIR}/include/"
    )
endif()

