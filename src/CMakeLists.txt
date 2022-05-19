#cmake_minimum_required(VERSION 3.21)
#project(CWK2_The_Game_of_Life_C C)
#
#cmake_minimum_required(VERSION 3.17)
#project(CWK2_The_Game_of_Life_C)
#set(CMAKE_CXX_STANDARD 20)
#include_directories(SDL)
#add_executable(CWK2_The_Game_of_Life_C main.c main.h game.c)
#target_link_libraries(CWK2_The_Game_of_Life_C mingw32 SDL2main SDL2)




cmake_minimum_required(VERSION 3.21)
project(CWK2_The_Game_of_Life_C)

set(CMAKE_C_STANDARD 11)

include_directories(..)

add_executable(CWK2_The_Game_of_Life_C
        main.c
        gameInit.c
        game.c gameTest.c)