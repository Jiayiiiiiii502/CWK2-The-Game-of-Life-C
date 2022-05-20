//
// Created by Jiayi on 2022/4/21.
//

#include "gameStructure.h"

//update game grids based on the rules provide
void game_update() {
    int grid_temp[len_allgrid][len_allgrid] = { 0 };

    game_temp(game, grid_temp);

    for (int y = 0; y < height/20; ++y) {
        for (int x = 0; x < width/20; ++x) {


            int neighbours=0;

            if(x==0 && y==0){//左上
                neighbours=game[0][1]+game[1][0]+game[1][1];
                if (game[y][x] == 1 && (neighbours < 2 || neighbours > 3)) {
                    grid_temp[y][x] = 0;
                }
                else if (game[y][x] == 0 && neighbours == 3) {
                    grid_temp[y][x] = 1;
                }
            }
            else if(x==(width/20)-1 && y==0){//右上
                neighbours=game[0][(width/20)-2]+game[1][(width/20)-2]+game[1][(width/20)-1];
                if (game[y][x] == 1 && (neighbours < 2 || neighbours > 3)) {
                    grid_temp[y][x] = 0;
                }
                else if (game[y][x] == 0 && neighbours == 3) {
                    grid_temp[y][x] = 1;
                }
            }
            else if(x==0 && y==(height/20)-1){//左下
                neighbours=game[y][1]+game[(height/20)-2][x]+game[(height/20)-2][1];

                if (game[y][x] == 1 && (neighbours < 2 || neighbours > 3)) {
                    grid_temp[y][x] = 0;
                }
                else if (game[y][x] == 0 && neighbours == 3) {
                    grid_temp[y][x] = 1;
                }
            }
            else if(x==(width/20)-1 && y==(height/20)-1){//右下
                neighbours=game[y][x-1]+game[y-1][x-1]+game[y-1][x];
                if (game[y][x] == 1 && (neighbours < 2 || neighbours > 3)) {
                    grid_temp[y][x] = 0;
                }
                else if (game[y][x] == 0 && neighbours == 3) {
                    grid_temp[y][x] = 1;
                }
            }
            else if(x==0 && y!=0 && y!=(height/20)-1){//left
                neighbours=game[y-1][0]+game[y+1][0]+game[y-1][1]+game[y][1]+game[y+1][1];
                if (game[y][x] == 1 && (neighbours < 2 || neighbours > 3)) {
                    grid_temp[y][x] = 0;
                }
                else if (game[y][x] == 0 && neighbours == 3) {
                    grid_temp[y][x] = 1;
                }
            }
            else if(x==(width/20)-1 && y!=0 && y!=(height/20)-1){//right
                neighbours=game[y-1][x]+game[y-1][x-1]+game[y][x-1]+game[y+1][x-1]+game[y+1][x];
                if (game[y][x] == 1 && (neighbours < 2 || neighbours > 3)) {
                    grid_temp[y][x] = 0;
                }
                else if (game[y][x] == 0 && neighbours == 3) {
                    grid_temp[y][x] = 1;
                }
            }
            else if(y==0 && x!=0 && x!=(width/20)-1){//top
                neighbours=game[0][x-1]+game[1][x-1]+game[1][x]+game[1][x+1]+game[0][x+1];
                if (game[y][x] == 1 && (neighbours < 2 || neighbours > 3)) {
                    grid_temp[y][x] = 0;
                }
                else if (game[y][x] == 0 && neighbours == 3) {
                    grid_temp[y][x] = 1;
                }
            }
            else if(y==(height/20)-1 && x!=0 && x!=(width/20)-1){//bottom
                neighbours=game[y][x-1]+game[y-1][x-1]+game[y-1][x]+game[y-1][x+1]+game[y][x+1];
                if (game[y][x] == 1 && (neighbours < 2 || neighbours > 3)) {
                    grid_temp[y][x] = 0;
                }
                else if (game[y][x] == 0 && neighbours == 3) {
                    grid_temp[y][x] = 1;
                }
            }
            else{
                neighbours=cell_neighbor(x, y);
                if (game[y][x] == 1 && (neighbours < 2 || neighbours > 3)) {
                    grid_temp[y][x] = 0;
                }
                else if (game[y][x] == 0 && neighbours == 3) {
                    grid_temp[y][x] = 1;
                }
            }


        }
    }

    game_temp(grid_temp, game);
}


//render the whole game(single cell) into the SDL window
void render_cells(SDL_Renderer *renderer, int paused) {
    for (int y = 0; y < len_allgrid; ++y) {
        if (y * len_rect < edge_y || y * len_rect > edge_y + 1200) continue; // Culling
        for (int x = 0; x < len_allgrid; ++x) {
            if (x * len_rect < edge_x || x * len_rect > edge_x + 1500) continue; // Culling

            if (game[y][x] == 1) {
                if (!paused) {
                    SDL_SetRenderDrawColor(renderer, 32, 36, 46, 255);
                }
                else {
                    SDL_SetRenderDrawColor(renderer, 201, 138, 131, 255);
                }
                SDL_Rect rect = { (x - between_rect) * len_rect + 240 - edge_x, (y - between_rect) * len_rect + 240 - edge_y, len_rect - 1, len_rect - 1 };
                SDL_RenderFillRect(renderer, &rect);
            }
        }
    }
}

//get number of the alive neighbors of those who are not on the edge
int cell_neighbor(int x, int y) {
//    int neighbours = 0;
//
//    for (int sy = y - 1; sy < y + 2; sy++) {
//        for (int sx = x - 1; sx < x + 2; sx++) {
//            if (sx == x && sy == y) continue;
//
//            if (grid[sy][sx] == 1) neighbours++;
//        }
//    }
//
//    return neighbours;
    int alive_neighbor=0;
    int down_y=y-1;
    int up_y=y+1;
    int down_x=x-1;
    int up_x=x+1;
    for(int m=down_x;m<=up_x;m++){
        for(int n=down_y;n<=up_y;n++){
            if(x==m & y==n){
                continue;
            }
            else if(game[m][n]==1){
                alive_neighbor++;
            }
        }
    }
    return alive_neighbor;
}

//copy the current game into a new grid for storing data to file
void game_temp(int cur[len_allgrid][len_allgrid], int temp[len_allgrid][len_allgrid]) {
    int m,n;
    for(m=0;m<len_allgrid;m++){
        for(n=0;n<len_allgrid;n++){
            temp[m][n]=cur[m][n];
        }
    }
}

