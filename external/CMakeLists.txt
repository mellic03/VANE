
add_subdirectory("assimp/" EXCLUDE_FROM_ALL)
add_subdirectory("SDL3/" EXCLUDE_FROM_ALL)
add_subdirectory("glad/")


set(MY_OPTION ON CACHE BOOL "My custom option" FORCE)
add_compile_definitions(
    -DBUILD_SHARED_LIBS=OFF
    -DBUILD_STATIC_LIBS=ON
    -DGLM_BUILD_TESTS=OFF
    -DGLM_FORCE_INLINE=ON
    -DGLM_FORCE_INTRINSICS=ON
)
add_subdirectory("glm/")
