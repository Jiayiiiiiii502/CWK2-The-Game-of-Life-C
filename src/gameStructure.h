//
// Created by Jiayi on 2022/4/21.
//

//window:
//#include "SDL/SDL2/SDL.h"
//linux:
#include "SDL2/SDL.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define between_rect 12
#define len_rect 20
#define len_allgrid 200
#define game_interval 40


//SDL window initialisation
int game[len_allgrid][len_allgrid];// width max:1000; heigth max:1000
int width,height;
int edge_x;
int edge_y;


//main:
//clean the stream which may have invalid input
void clear();
//get into the page of initial game
void new_game_page();


//game.c:
//update game grids based on the rules provide
void game_update();
//get number of the alive neighbors of those who are not on the edge
int cell_neighbor(int,int);
//copy the current game into a new grid for storing data to file
void game_temp(int cur[len_allgrid][len_allgrid], int temp[len_allgrid][len_allgrid]);
//render the whole game(single cell) into the SDL window
void render_cells(SDL_Renderer *renderer, int paused);


//gameInit.c:
//randomly initialise the game
void game_random();
//initialise game by reading data from file
void game_init();
//render the basic game(background, size) into the SDL window
void game_show();
//store current game shot into file
void game_store();


//gameTest.c:
//test rules:
void test();
//Test rule 1: Any live cell with 0 or 1 live neighbours becomes dead
void test_rule1();
//Test rule 2+ rule4: Any live cell with 2 or 3 live neighbours stays alive + Any dead cell with exactly 3 live neighbours becomes alive
void test_rule234();
//Test rule 3: Any live cell with more than 3 live neighbours becomes dead
int test_rule3();
