/*
    File: Start.cpp
    Author:	H.CHERGUI
    First version: 1.0
    First version date: 02/02/2021
    current version: 3.0
    current version date: 05/02/2021
*/


// Sys includes
/*NONE*/

// User includes
#include "Init.h"


/*Global Variables*/
s_Game_info gs_Game_info;

// Definitions
void Init() {

    // Initialize score
    score = 0;
    gs_Game_info = { e_State::START_SCREEN, e_Cmd::NO_CMD };

    // Initialize snake
    g_Direction = e_Direction::UP;
    xx = GC_COL / 2, yy = GC_ROW / 2;

    tail.resize(100);
    tail_len = 4;
    for (int i = 0; i < tail_len; i++) {
        tail[i] = std::make_pair(GC_COL / 2, GC_ROW / 2 - i - 1);
    }

    // Hide cursor
    ShowCursor(false);

    // Initialize food cordinates
    srand(unsigned int(time(NULL)));
    fx = rand() % (GC_COL - 2) + 1;
    fy = rand() % (GC_ROW - 4) + 1;
}
