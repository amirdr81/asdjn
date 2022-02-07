cmake_minimum_required(VERSION 3.19)

project(state.io C)

set(CMAKE_C_STANDARD 11)

set(SOURCE src/main.c src/functions.c)

include_directories(/opt/homebrew/var/homebrew/linked/sdl2/include/SDL2)
include_directories(/opt/homebrew/var/homebrew/linked/sdl2_gfx/include/SDL2)
include_directories(/opt/homebrew/var/homebrew/linked/sdl2_ttf/include/SDL2)
include_directories(/opt/homebrew/var/homebrew/linked/sdl2_image/include/SDL2)
include_directories(/Users/amir/Desktop/test/header)
include_directories(/Users/amir/Desktop/test/src)

link_directories(/opt/homebrew/var/homebrew/linked/sdl2/lib)
link_directories(/opt/homebrew/var/homebrew/linked/sdl2_gfx/lib)
link_directories(/opt/homebrew/var/homebrew/linked/sdl2_ttf/lib)
link_directories(/opt/homebrew/var/homebrew/linked/sdl2_image/lib)

add_executable(state.io ${SOURCE})

target_link_libraries(state.io m sdl2 sdl2_gfx sdl2_ttf sdl2_image)



