cmake_minimum_required(VERSION 3.11)

file(COPY "${CMAKE_SOURCE_DIR}/include/"
     DESTINATION "${CMAKE_SOURCE_DIR}/build/vane_sdk/include/"
)

file(COPY "${CMAKE_SOURCE_DIR}/vane_sdk/example/"
     DESTINATION "${CMAKE_SOURCE_DIR}/build/vane_sdk/example/"
)

# file(
#     ARCHIVE_CREATE
#     OUTPUT "${CMAKE_SOURCE_DIR}/build/vane_sdk/vanepkg.tar"
#     PATHS  "."
#     WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/vanepkg/"
#     FORMAT "gnutar"
# )
