set( BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE )


set(SDL_LIBC ON CACHE BOOL "" FORCE)
set(SDL_TEST OFF CACHE BOOL "" FORCE)
add_subdirectory("SDL3/" EXCLUDE_FROM_ALL)


add_compile_definitions(GLEW_STATIC)
add_subdirectory("glew/")

