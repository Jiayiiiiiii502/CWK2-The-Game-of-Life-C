//
// Created by Jiayi on 2022/4/21.
//

//int game_temp(int cur[][],int temp[][]){
//
//}

#include "gameStructure.h"
//manipulate the grid
void game_update(){
    for(int x=0;x<len_grid;x++){
        for(int y=0;y<len_grid;y++){
            if(x==0 || y==0){
                continue;
            }
            int alive_neighbor= cell_neighbor(x,y);
            if(game[x][y]==1 &&(alive_neighbor>3 || alive_neighbor<2)){
                game[x][y]=0;
            }
            else if(game[x][y]==0 && alive_neighbor==3){
                game[x][y]=1;
            }
        }
    }
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
    int m,n=0;
    for(m=0;m<len_grid;m++){
        for(n=0;n<len_grid;n++){
            temp[m][n]=cur[m][n];
        }
    }
}
