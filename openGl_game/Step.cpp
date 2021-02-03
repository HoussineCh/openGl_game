/*
	File: Update.cpp
	Author:	H.CHERGUI
	First version: 2.0
	First version date: 03/02/2021
	current version: 2.0
	current version date: 03/02/2021
*/

// Sys includes
/*NONE*/

// User includes
#include "Step.h"


// Definitions
void Step() {
	g_Game_info = Update(g_Game_info, g_key);
	Draw(g_Game_info);
}



