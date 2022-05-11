#include <stdio.h>
#include "gameStructure.h"




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
        case 2:
            printf("Read game from file!\n");
            game_init("history.txt");
        break;
        default: printf("Invalid choice! Please try again!\n");
    }
    game_show();
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
    printf("Please enter the width of window (40*n):\n");
    scanf("%d",&width);
    if(width%40 !=0){
        printf("Invalid choice!\n");
        exit(0);
    }
    printf("Please enter the height of window (40*n):\n");
    scanf("%d",&height);
    if(height%40 !=0){
        printf("Invalid choice!\n");
        exit(0);
    }
    printf("Enter o to begin the random game!\n");
}










