/*
    File: Start.cpp
    Author:	H.CHERGUI
    First version: 1.0
    First version date: 02/02/2021
    current version: 3.1
    current version date: 06/02/2021
*/


// Sys includes
/*NONE*/

// User includes
#include "Init.h"


// Definitions
void Init() {

    // Initialize score
    g_Game_info.Init_Score();

    // Initialize snake
    g_Snake.Init();

    // Hide cursor
    ShowCursor(false);

    // Initialize food cordinates
    g_Food.Generate_cordinates();
}
