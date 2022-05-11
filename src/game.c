//
// Created by Jiayi on 2022/4/21.
//

#include "gameStructure.h"

int cell_neighbor_top(int y){
    int alive_neighbor=0;
    if(y==0){
        alive_neighbor=game[0][1]+game[1][0]+game[1][1];
    }
    else if(y==(width/40)-1){
        alive_neighbor=game[0][y-1]+game[1][y-1]+game[1][y];
    }
    else{
        alive_neighbor=game[0][y-1]+game[0][y+1]+game[1][y-1]+game[1][y]+game[1][y+1];
    }
    return alive_neighbor;
}
int cell_neighbor_left(int x){
    int alive_neighbor;
    if(x==0){
        alive_neighbor=game[0][1]+game[1][0]+game[1][1];
    }
    else if(x==(height/40)-1){
        alive_neighbor=game[x-1][0]+game[x-1][1]+game[x][1];
    }
    else{
        alive_neighbor=game[x-1][0]+game[x-1][1]+game[x][1]+game[x+1][1]+game[x+1][0];
    }
    return alive_neighbor;
}
//manipulate the game grid based on the rule
void game_update(){
    for(int x=0;x<height/40;x++){//row
        for(int y=0;y<width/40;y++){//column
            int alive_neighbor;
            if(x==0){
                alive_neighbor= cell_neighbor_top(y);
            }
            else if(y==0){
                alive_neighbor= cell_neighbor_left(x);
            }
            else{
                alive_neighbor= cell_neighbor(x,y);
            }

            if(game[x][y]==1 &&(alive_neighbor>3 || alive_neighbor<2)){
                game[x][y]=0;
            }
            else if(game[x][y]==0 && alive_neighbor==3){
                game[x][y]=1;
            }
        }
    }
    game_temp(game,game_copy);
}



//get the alive neighbor number of one cell
int cell_neighbor(int x,int y){
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

//copy the current grid to temp grid
void game_temp(int cur[len_grid][len_grid], int temp[len_grid][len_grid]){
    int m,n;
    for(m=0;m<len_grid;m++){
        for(n=0;n<len_grid;n++){
            temp[m][n]=cur[m][n];
        }
    }
}
