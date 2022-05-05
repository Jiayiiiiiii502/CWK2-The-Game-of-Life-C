//
// Created by Jiayi on 2022/4/21.
//

#ifndef CWK2_THE_GAME_OF_LIFE_C_GAMESTRUCTURE_H
#define CWK2_THE_GAME_OF_LIFE_C_GAMESTRUCTURE_H

#define len_cell 40
#define len_grid 200

//main.c:
//function to clear incorrect input
void clear();

//grid
int grid[len_grid][len_grid];

//window size
int width;
int height;

void new_game_page();

//game.c:
void game_update();
int cell_neighbor(int,int);
int game_temp(int cur[len_grid][len_grid], int temp[len_grid][len_grid]);

//gameInit.c:
int game_init(char*);
int game_store(char*);
int game_random();
void game_show(int,int);

int camera_x,camera_y;

#endif
