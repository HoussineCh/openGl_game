/*
    File: Init.cpp
    Author:	H.CHERGUI
    First version: 3.0
    First version date: 05/02/2021
	Current version: 3.1
	Current version date: 06/02/2021
*/


// Sys includes
/*NONE*/

// User includes
#include "Global_Init.h"


/*Global Variables*/

Game_info g_Game_info;
Snake g_Snake;
Food g_Food;

/*Global Constants*/

char local[11] = "snake gaem";
const char* WIN_NAME = local;


// Definitions
void Global_Init() {
    // Background color
    glClearColor(0.15, 0.15, 0.3, 1.0);
}
