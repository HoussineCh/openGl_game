/*
    File: Init.cpp
    Author:	H.CHERGUI
    First version: 3.0
    First version date: 05/02/2021
    current version: 3.0
    current version date: 05/02/2021
*/

// Sys includes
/*NONE*/

// User includes
#include "Global_Init.h"


/*Global Variables*/

int score;
int hi_score = GC_HI_SCORE;

e_Direction g_Direction;
int xx , yy;
int tail_len;
std::vector<std::pair<int, int>> tail;
short supeedo_wagon_val;

int fx, fy;

int g_key;


char local[11] = "snake gaem";
const char* WIN_NAME = local;

// Definitions
void Global_Init() {
    
    // Background color
    glClearColor(0.15, 0.15, 0.3, 1.0);
    
    // Initialize hi-score
    hi_score = GC_HI_SCORE;

    // Initilize speed
    supeedo_wagon_val = 1;
}

