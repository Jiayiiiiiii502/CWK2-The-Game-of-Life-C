//
// Created by Jiayi on 2022/5/5.
//
#include <stdio.h>
#include <time.h>
#include "gameStructure.h"
#include "SDL/SDL2/SDL.h"
int game_init(char* filename){

}

int game_store(char* filename){

}

int game_random(){
    srand(time(NULL));
    for(int m=0;m<len_grid;m++){
        for(int n=0;n<len_grid;n++){
            int r=rand();
            grid[m][n]=r>RAND_MAX/2;
        }
    }
}

void game_show(int wid, int hei){

}