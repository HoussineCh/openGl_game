/*
	File: Update.cpp
	Author: H.CHERGUI
	First version: 2.0
	First version date: 03/02/2021
	Current version: 3.6
	Current version date: 10/02/2021
*/


// Sys includes
/*NONE*/

// User includes
#include "Update.h"


// Definition of the update function
s_Data_Cluster Update(s_Data_Cluster p_data) {

	// Local variables
	s_Data_Cluster l_Data = p_data;

	// Determining the current state of the game
	l_Data = State_Engine(p_data);

	if (l_Data.game_info.Get_state() == Game_info::e_State::RUNNING) {

		// Check if the snake ate the fruit
		l_Data = Update_Food(l_Data);

		// Updating the snake
		l_Data = Update_Snake(l_Data);

		// Check if a game over occured
		l_Data.game_info.Set_cmd(Update_Cmd(l_Data.snake));
	}

	// Clearing the input values
	l_Data.game_info.Clear_Special_key();
	l_Data.game_info.Clear_Input_key();	

	// Return Updated data
	return l_Data;
}
