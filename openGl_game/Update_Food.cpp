/*
	File: Update_Food.cpp
	Author: H.CHERGUI
	First version: 3.6
	First version date: 10/02/2021
	Current version: 3.6
	Current version date: 10/02/2021
*/


// Sys includes
/*NONE*/

// User includes
#include "Update.h"


// Check if the snake ate the fruit
s_Data_Cluster Update_Food(s_Data_Cluster p_Data) {

	// Local variable
	s_Data_Cluster l_Data = p_Data;

	if (p_Data.snake.Get_Coordinates() == p_Data.food.Get_Coordinates()) {
		l_Data.game_info.Determine_Score();
		l_Data.snake.Grow_Tail();
		l_Data.food.Generate_cordinates();
	}

	return l_Data;
}
