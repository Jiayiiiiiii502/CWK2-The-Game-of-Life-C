#include <string.h>
#include "gameStructure.h"

//game instruction
//'o' to begin random new game
//'space' to run/stop the game
//'b' to put current game data into file and exit
int main(int argc, char **argv) {
    printf("Welcome to life game!\n");
    printf("1.Randomly show a game\n");
    printf("2.Read from file\n");
    printf("3.Exit game\n");
    printf("4.Test game\n");
    char choice[10];
    scanf("%s", choice);
    if(strspn(choice,"0123456789")!=strlen(choice)){
        printf("Invalid choice\n");
        exit(0);
    }
    int option;
    option=atoi(choice);
    clear();
    switch (option) {
        case 1:
            printf("Start a new game!\n");
            new_game_page();
            break;
        case 2:
            printf("Read game from file!\n");
            game_init();
            break;
        case 3:
            exit(0);
        case 4:
            test();
        default: {
            fflush(stdin);
            printf("Invalid choice! Please try again!\n");
            exit(0);
        }
    }
    game_show();
    return 0;
}


//get into the page of initial game
void new_game_page(){
    while(1){
        printf("Please enter the width of game (0<20*n<=1000):\n");
        char choice[10];
        scanf("%s", choice);
        if(strspn(choice,"0123456789")!=strlen(choice)){
            printf("Invalid choice\n");
            clear();
            exit(0);
        }
        else{
            int width;
            width=atoi(choice);
            if(width%20 !=0 || width>1000 ||width<=0){
                printf("Invalid choice!\n");
                exit(0);
            }
        }
        width=atoi(choice);


        printf("Please enter the height of window (0<20*n<=1000):\n");
        char option[10];
        scanf("%s",option);
        if(strspn(option,"0123456789")!=strlen(option)){
            printf("Invalid choice\n");
            exit(0);
        }
        else{
            int height;
            height=atoi(option);
            if(height%20 !=0 ||height>1000 ||height<=0) {
                printf("Invalid choice!\n");
                exit(0);
            }
        }

        height=atoi(option);

        printf("Enter o to begin the random game!\n");
        break;
    }
}

//clean the stream which may have invalid input
void clear(){
    char b;
    do
    {
        scanf("%c",&b);
    }
    while(b !='\n');
}




