//
// Created by Jiayi on 2022/4/21.
//

#ifndef CWK2_THE_GAME_OF_LIFE_C_GAMESTRUCTURE_H
#define CWK2_THE_GAME_OF_LIFE_C_GAMESTRUCTURE_H

#include "SDL/SDL2/SDL.h"
#include "stdio.h"
#define between_grid 12
#define len_cell 40
#define len_grid 200

//main.c:
//function to clear incorrect input
void clear();

//grid
int game[len_grid][len_grid];
int game_copy[len_grid][len_grid];
//window size
int width;
int height;

//game setting
int game_interval=20;

void new_game_page();

//game.c:
void game_update();
int cell_neighbor(int,int);
void game_temp(int cur[len_grid][len_grid], int temp[len_grid][len_grid]);

//gameInit.c:
int game_init(char*);
int game_store(char*);
int game_random();
void game_show();
void game_render(SDL_Renderer*, int);

//int camera_x,camera_y;

#endif
