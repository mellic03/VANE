set(SDL_STATIC ON CACHE BOOL "Build static SDL3 library")
# set(SDL_LIBC ON CACHE BOOL "" FORCE)
# set(SDL_TEST OFF CACHE BOOL "" FORCE)
add_subdirectory("SDL3/" EXCLUDE_FROM_ALL)


add_subdirectory("glad/")
