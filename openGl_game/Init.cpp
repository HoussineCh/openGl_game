/*
    File: Init.cpp
    Author:	H.CHERGUI
    First version: 1.0
    First version date: 02/02/2021
    current version: 1.0
    current version date: 02/02/2021
*/

// Sys includes
/*NONE*/

// User includes
#include "Init.h"


/*Global Variables*/

tagRECT get_rect = { 0, 42, 64, 40 };

int gridX, gridY;

int score;
int hi_score;

short sDirection = UP;
int xx = COL / 2, yy = ROW / 2;
int tail_len;
std::vector<std::pair<int, int>> tail;
short supeedo_wagon_val;

int fx, fy;

// Definitions
void Init() {
    score = 0;
    hi_score = 100;
    glClearColor(0.1, 0.1, 0.15, 1.0);
    initGrid(COL, ROW);
    tail.resize(100);
    tail_len = 4;
    for (int i = 0; i < tail_len; i++) {
        tail[i] = std::make_pair(COL / 2, ROW / 2 - i - 1);
    }
    srand(time(NULL));
    fx = rand() % (COL - 2) + 1;
    fy = rand() % (ROW - 4) + 1;

    supeedo_wagon_val = 1;
}


void initGrid(int x, int y) {
    gridX = x;
    gridY = y;
}