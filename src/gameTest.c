//
// Created by Jiayi on 2022/5/18.
//

//This is the file that test game functions
#include "gameStructure.h"
void test(){
    width = 60;
    height = 60;
    test_rule1();
    test_rule234();
    exit(0);
}
void test_rule1() {
    printf("Begin the first rule test:\n");
    printf(" Any live cell with 0 or 1 live neighbours becomes dead\n");
    printf("\n");
    printf("The input game grid:\n");
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            if (x == 1 && y == 1) {
                game[1][1] = 1;
            } else if (x == 1 && y == 2) {
                game[1][2] = 1;
            } else {
                game[y][x] = 0;
            }
        }
    }

    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            printf("%d ", game[y][x]);
        }
        printf("\n");
    }
    game_update();
    printf("After one generation updating:\n");
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            printf("%d ", game[y][x]);
        }
        printf("\n");
    }

    int answer[3][3];
    int not_equal = 0;
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            answer[y][x] = 0;
            if (answer[y][x] != game[y][x]) {
                not_equal++;
            }
        }
    }
    if (not_equal > 0) {
        printf("number of not equal: %d", not_equal);
        printf("Not equal!\n");
        exit(0);
    } else {
        printf("Pass test!\n");
        //exit(0);
    }
}


void test_rule234(){
    printf("Begin the second rule, third rule and forth rule test:\n");
    printf("Second rule: Any live cell with 2 or 3 live neighbours stays alive\n");
    printf("Third rule: Any live cell with more than 3 live neighbours becomes dead\n");
    printf("Any dead cell with exactly 3 live neighbours becomes alive\n");
    printf("\n");
    printf("The input game grid:\n");
    //set beginning game
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            if(x==0 && y==2){
                game[y][x]=0;
            }
            else if (x == 2 && y == 0) {
                game[y][x] = 0;
            } else if (x == 2 && y == 1) {
                game[y][x] = 0;
            } else if(x==2 && y==2){
                game[y][x]=0;
            }
            else {
                game[y][x] = 1;
            }
        }
    }
    //show the beginning game grid
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            printf("%d ", game[y][x]);
        }
        printf("\n");
    }
    //update grid
    game_update();

    printf("After one generation updating:\n");
    //show the current game
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            printf("%d ", game[y][x]);
        }
        printf("\n");
    }

    int answer[3][3];
    int not_equal = 0;
    //set answer grid
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            if(x==2 && y==0){
                answer[y][x]=0;
            }
            else if(x==0 && y==1){
                answer[y][x]=0;
            }
            else if(x==1 && y==1){
                answer[y][x]=0;
            }
            else if(x==2 && y==2){
                answer[y][x]=0;
            }
            else{
                answer[y][x] = 1;
            }
        }
    }

    //compare answer with game
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            if(game[y][x]!=answer[y][x]){
                not_equal++;
            }
        }
    }

    if (not_equal > 0) {
        printf("number of not equal: %d", not_equal);
        printf("Not equal!\n");
        exit(0);
    } else {
        printf("Pass test!\n");
        exit(0);
    }
}

