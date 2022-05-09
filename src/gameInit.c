//
// Created by Jiayi on 2022/5/5.
//
#include <stdio.h>
#include <time.h>
#include "gameStructure.h"
#include "SDL/SDL2/SDL.h"
int game_init(char* filename){
    FILE *file=fopen(filename,"rb");
        int game_width=width/20;
        int game_height=height/20;
        while(!feof(file)){
            fscanf(file,"%d",&game_interval);
            fscanf(file,"%d",&height);
            fscanf(file,"%d",&width);
            break;
        }
        int m,n;
        for(m=0;m<game_width;m++){
            for(n=0;n<game_height;n++){
                fscanf(file,"%d",&game[n][m]);
            }
        }

    fclose(file);
}

int game_store(char* filename){
    FILE *file=fopen(filename,"wb");
    fprintf(file,"%d\n",game_interval);
    fprintf(file,"%d\n",height);
    fprintf(file,"%d\n",width);
    int m,n;
    for(m=0;m<width/20;m++){
        for(n=0;n<height/20;n++){
            fprintf(file,"%d ",game[m][n]);
        }
        fprintf(file,"\n");
    }
    printf("Store successfully!\n");
    fclose(file);
}

int game_random(){
    srand(time(NULL));
    for(int m=0;m<len_grid;m++){
        for(int n=0;n<len_grid;n++){
            int r=rand();
            game[m][n]=r>RAND_MAX/2;
        }
    }
}

void game_show(){
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window =SDL_CreateWindow("Game of life",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,width,height,SDL_WINDOW_RESIZABLE);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    SDL_Rect rect = { 1, 1, width, height };

    int game_running=1;
    int game_paused=1;  //game_paused=paused
    int controller=game_interval;  //controller=frames  ,step=game_interval

    while (game_running==1) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    game_running = 0;
                    break;
                case SDL_KEYDOWN: {
                    if (event.key.keysym.sym == SDLK_SPACE || event.key.keysym.sym == SDLK_RETURN) {
                        game_paused = !game_paused;
                        controller=0;
                    } else if (event.key.keysym.sym == SDLK_o) {
                        printf("Start a new random game!\n");
                        game_random();
                    } else if (event.key.keysym.sym == SDLK_b) {
                        printf("Store the data and over the game!\n");
                        game_store("history.txt");
                        game_running=0;
                    }
                }
            }
        }

        // set background color
        SDL_SetRenderDrawColor(renderer, 210, 188, 167, 255);
        SDL_RenderClear(renderer);


        // pause case -->run/stop
        if (!game_paused) {
            if (controller == 0) {
                game_update();
                controller = game_interval;
            } else {
                controller--;
            }
        }
        game_render(renderer,game_paused);

        // game rendering
        SDL_RenderPresent(renderer);
    }
    //free SDL game
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void game_render(SDL_Renderer *renderer, int game_paused){
    for(int m=0;m<len_grid;m++){
        for(int n=0;n<len_grid;n++){
            if(game[m][n]==1){
                if(!game_paused){
                    //black grid if it is running
                    SDL_SetRenderDrawColor(renderer, 32, 36, 46, 255);
                }
                else {
                    //pink grid if it stops
                    SDL_SetRenderDrawColor(renderer, 201, 138, 131, 255);
                }
                SDL_Rect game_grid= {len_cell*(m-between_grid)+240,len_cell*(n-between_grid)+240,len_cell-1,len_cell-1};
                SDL_RenderFillRect(renderer,&game_grid);
            }
        }
    }
}