/*
	File: Update.cpp
	Author:	H.CHERGUI
	First version: 2.0
	First version date: xxxxxxxx
	current version: 2.0
	current version date: xxxxxxxxxxxx
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



