#include <stdio.h>
//#include "SDL2/SDL.h"
#include "gameStructure.h"
#include "SDL/SDL2/SDL.h";



//begin the game initialisation
int main() {
    printf("Welcome to the Game of life!\n");
    printf("Please enter the option:\n");
    printf("1. Start a random new game\n");
    printf("2. Read last game from file\n");
    int choice;
    scanf("%d",&choice);
    clear();
    switch (choice) {
        case 1:
            printf("Start a new game!\n");
            new_game_page();
        break;
        case 2: printf("Read game from file!\n");
        break;
        default: printf("Invalid choice! Please try again!\n");
    }
    return 0;
}

//incorrect input
void clear()
{
    char b;
    do
    {
        scanf("%c",&b);
    }
    while(b !='\n');
}

void new_game_page(){
        printf("Please enter the width of window:\n");
    //int length;
    scanf("%d",&width);
    printf("Please enter the height of window:\n");
    //int height;
    scanf("%d",&height);

    printf("Enter b to begin the random game!\n");
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window =SDL_CreateWindow("Game of life",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,width,height,SDL_WINDOW_RESIZABLE);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    //SDL_Rect rect = { 1, 1, width, height };
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
       //SDL_RenderDrawRect(renderer, &rect);

       SDL_RenderPresent(renderer);

 SDL_DestroyRenderer(renderer);
   SDL_DestroyWindow(window);

   SDL_Quit();

}

//void new_game_page(){
//    printf("Please enter the width of window:\n");
//    //int length;
//    scanf("%d",&width);
//    printf("Please enter the height of window:\n");
//    //int height;
//    scanf("%d",&height);
//
//    printf("Enter b to begin the random game!\n");
//    SDL_Init(SDL_INIT_EVERYTHING);
//    SDL_Window *window =SDL_CreateWindow("Game of life",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,width,height,SDL_WINDOW_RESIZABLE);
//    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
//    //SDL_Rect rect = { 1, 1, width, height };
//
//
//
//
//    int playing=1;
//    int stop=1;
//    while(playing){
//        SDL_Event play;
//        while(SDL_PollEvent(&play)){
//            switch(play.type){
//                case SDL_QUIT:
//                    playing=0;
//                    break;
//                case SDL_KEYDOWN:
//                    if(play.key.keysym.sym==SDLK_s){
//                        //print s to store the file
//                        printf("Start storing game!\n");
//                    }
//                    else if(play.key.keysym.sym==SDLK_a){
//                        //a to begin new game
//                        printf("Generate new generation!\n");
//                        game_random();
//                    }
//            }
//        }
//
//        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
//        SDL_RenderClear(renderer);
//
//        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
//        //SDL_RenderDrawRect(renderer, &rect);
//
//        SDL_RenderPresent(renderer);
//
//
//    }
//
//
//
//
//
//
//
//
//    SDL_Delay(2000);
//    SDL_DestroyRenderer(renderer);
//    SDL_DestroyWindow(window);
//
//    SDL_Quit();
//}








