//
// Created by Jiayi on 2022/4/21.
//

#ifndef CWK2_THE_GAME_OF_LIFE_C_GAMESTRUCTURE_H
#define CWK2_THE_GAME_OF_LIFE_C_GAMESTRUCTURE_H

//window:
#include "SDL/SDL2/SDL.h"
//linux:
#include "SDL2/SDL.h"
#include "stdio.h"
#define between_grid 12
#define len_cell 40
#define len_grid 200
#define game_interval 40

//gird for game and grid for storing in file
int game[len_grid][len_grid];
int game_copy[len_grid][len_grid];

//window size
int width;
int height;

//game time spare setting
//int game_interval=20;


//main.c:
//function to clear incorrect input
void clear();
//new page choice
void new_game_page();


//game.c:
//update the game grid based on the rule
void game_update();
//get the alive cell numbers of a single cell
int cell_neighbor(int,int);
//copy current game grid to temp grid for storing game history
void game_temp(int cur[len_grid][len_grid], int temp[len_grid][len_grid]);

//gameInit.c:
//read game history from file to game grid
int game_init(char*);
//store game grid data to file
int game_store(char*);
//load a random new game
int game_random();
// control the whole game procedure and input information
void game_show();
//render the game grid
void game_render(SDL_Renderer*, int);
#endif
