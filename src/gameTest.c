//
// Created by Jiayi on 2022/5/18.
//

//This is the file that test game functions
#include "gameStructure.h"
void test(){
    width = 60;
    height = 60;
    test_rule1();
}
void test_rule1() {
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
        exit(0);
    }
}


void test_rule24(){
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            if (x == 1 && y == 0) {
                game[1][1] = 1;
            } else if (x == 1 && y == 1) {
                game[1][2] = 1;
            } else if(x==2 && y==2){
                game[2][2]=1;
            }
            else {
                game[y][x] = 0;
            }
        }
    }


}

