/*
    File: Init.cpp
    Author:	H.CHERGUI
    First version: 1.0
    First version date: 02/02/2021
	Current version: 3.4
	Current version date: 09/02/2021
*/


// Sys includes
/*NONE*/

// User includes
#include "Init.h"


// Definitions
s_Data_Cluster Init(s_Data_Cluster p_Data) {

    // local variable
    s_Data_Cluster l_Initialized_data = p_Data;

    // Initialize score
    l_Initialized_data.game_info.Init_Game_info();

    // Initialize snake
    l_Initialized_data.snake.Init();

    // Initialize food cordinates
    l_Initialized_data.food.Generate_cordinates();

    // Hide cursor
    ShowCursor(false);

    // Return initialized data
    return l_Initialized_data;
}
