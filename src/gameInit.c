//
// Created by Jiayi on 2022/5/5.
//
#include <stdlib.h>
#include "gameStructure.h"

//initialise game by reading data from file
void game_init(char* filename) {
    FILE* file = fopen("history.txt", "rb");
    if(file==NULL){
        file=fopen(filename,"wb");
        if(file==NULL){
            printf("Please start a new game first!\n");
            exit(0);
        }
    }
    int game_width, game_height;
    while (!feof(file)) {
        fscanf(file, "%d", &width);
        fscanf(file, "%d", &height);
        game_width = width/20;
        game_height = height/20;
        break;
    }
    for (int i = 0; i < game_height; i++) {
        for (int j = 0; j < game_width; j++) {
            fscanf(file, "%d", &game[i][j]);
        }
    }
    fclose(file);
}

//store current game shot into file
void game_store(){
    FILE* file = fopen("history.txt", "wb");
    fprintf(file, "%d ", width);
    fprintf(file, "%d\n", height);
    for (int i = 0; i < height/20; i++) {
        for (int j = 0; j < width/20; j++) {
            fprintf(file, "%d ", game[i][j]);
        }
        fprintf(file, "\n");
    }
    printf("Store successfully!");
    fclose(file);
}

//randomly initialise the game
void game_random() {
    srand(time(NULL));
    for (int m = 0; m < len_allgrid; ++m) {
        for (int n = 0; n < len_allgrid; ++n) {
            int r = rand();
            game[m][n] = r > RAND_MAX / 2;
        }
    }
}


//render the basic game(background, size) into the SDL window
void game_show(){
    printf("show the game!\n");
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *window = SDL_CreateWindow("Conway's Game of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_RESIZABLE);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);



    int game_running = 1;
    int game_paused = 1;
    // Set camera to the middle of the usable area.

    int interval = game_interval;
    while (game_running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    game_running = 0;
                    break;
                case SDL_KEYDOWN: {
                    if (event.key.keysym.sym == SDLK_SPACE || event.key.keysym.sym == SDLK_RETURN) {
                        game_paused = !game_paused;
                        interval = 0;
                    }
                    else if (event.key.keysym.sym == SDLK_o) {
                        game_random();
                    }
                    else if (event.key.keysym.sym == SDLK_b) {
                        printf("Store successfully by jiayi!\n");
                        game_store();
                        exit(0);
                    }
                }
            }
        }


        SDL_SetRenderDrawColor(renderer, 210, 188, 167, 255);
        SDL_RenderClear(renderer);


        if (!game_paused) {
            if (interval == 0) {
                game_update();
                interval = game_interval;
            }
            else {
                interval--;
            }
        }

        render_cells(renderer, game_paused);

        // Render everything to the screen.
        SDL_RenderPresent(renderer);
    }

    // Free stuff.

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
}
