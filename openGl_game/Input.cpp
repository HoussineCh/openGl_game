/*
    File: Input.cpp
    Author:	H.CHERGUI
    First version: 1.0
    First version date: 02/02/2021
    current version: 3.3
    current version date: 08/02/2021
*/

// Sys includes
/*NONE*/

// User includes
#include "Input.h"


// Special and normal keys input functions
void Special_callback(int key, int, int) {    
    g_Game_info.Set_Special_key(key);
}

void keyboard_callback(unsigned char key, int, int) {
    g_Game_info.Set_Input_key(key);
}