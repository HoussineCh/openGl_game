/*
	File: Update.cpp
	Author:	H.CHERGUI
	First version: 2.0
	First version date: 03/02/2021
	Current version: 3.6
	Current version date: 10/02/2021
*/


// Sys includes
/*NONE*/

// User includes
#include "Step.h"


/*Global Variables*/

s_Data_Cluster g_Data;


// Function definition
void Step() {

	// Local variables
	s_Data_Cluster l_Prev = g_Data;
	s_Data_Cluster l_Updated;

	l_Updated = Update(l_Prev);
	Draw(l_Updated);

	g_Data = l_Updated;
}
