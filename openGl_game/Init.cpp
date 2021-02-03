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

int gridX, gridY;

int score;
int hi_score;

e_DIrection g_Direction;
int xx , yy;
int tail_len;
std::vector<std::pair<int, int>> tail;
short supeedo_wagon_val;

int fx, fy;

int g_key;
int g_special_key;

s_Game_info g_Game_info;

// Definitions
void Init() {
    
    score = 0;
    hi_score = 100;

    g_Direction = e_DIrection::UP;
    xx = GC_COL / 2, yy = GC_ROW / 2;

    g_key = 0;
    g_special_key = 0;

    glClearColor(0.1, 0.1, 0.15, 1.0);
    initGrid(GC_COL, GC_ROW);
    tail.resize(100);
    tail_len = 4;
    for (int i = 0; i < tail_len; i++) {
        tail[i] = std::make_pair(GC_COL / 2, GC_ROW / 2 - i - 1);
    }
    srand(unsigned int(time(NULL)));
    fx = rand() % (GC_COL - 2) + 1;
    fy = rand() % (GC_ROW - 4) + 1;

    supeedo_wagon_val = 1;

    g_Game_info = { e_State::START_SCREEN, e_Cmd::NO_CMD };
}

void initGrid(int x, int y) {
    gridX = x;
    gridY = y;
}