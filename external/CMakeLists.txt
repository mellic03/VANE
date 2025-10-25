
add_subdirectory("assimp/" EXCLUDE_FROM_ALL)
add_subdirectory("SDL3/" EXCLUDE_FROM_ALL)
add_subdirectory("glad/")


add_subdirectory("glm/")
target_compile_definitions(
    glm PRIVATE
    -DBUILD_SHARED_LIBS=OFF
    -DGLM_BUILD_TESTS=OFF
    -DGLM_FORCE_INLINE
    -DGLM_FORCE_INTRINSICS
)

