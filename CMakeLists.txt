cmake_minimum_required(VERSION 3.21)
project(CWK2_The_Game_of_Life_C C)

set(CMAKE_C_STANDARD 99)

set(SDL2_DIR D:/softwares/SDL2/SDL2-devel-2.0.20-mingw.tar/SDL2-devel-2.0.20-mingw/SDL2-2.0.20/x86_64-w64-mingw32)

include_directories(${SDL2_DIR}/include)
link_directories(${SDL2_DIR}/bin)
add_executable(CWK2_The_Game_of_Life_C main.c)
target_link_libraries(CWK2_The_Game_of_Life_C mingw32 SDL2 SDL2main)



