/*
	File: Update.cpp
	Author:	H.CHERGUI
	First version: 2.0
	First version date: 03/02/2021
	current version: 3.1
	current version date: 06/02/2021
*/

// Sys includes
/*NONE*/

// User includes
#include "Step.h"


// Function definition
void Step() {

	// Local variables
	s_Data_Cluster l_Prev = {g_Game_info, g_Snake, g_Food};
	s_Data_Cluster l_Updated;

	l_Updated = Update(l_Prev);
	Draw();
}



