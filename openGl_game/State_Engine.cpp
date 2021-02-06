/*
	File: Input.cpp
	Author: H.CHERGUI
	First version: 2.0
	First version date: 03/02/2021
	Current version: 3.2
	Current version date: 06/02/2021
*/


// System files includes
/*NONE*/

// User defined files includes
#include "State_Engine.h"


// Determining the current state of the game
s_Data_Cluster State_Engine(s_Data_Cluster p_Data) {

	// Local variables
	s_Data_Cluster l_Data = p_Data;

	// Start screen
	if (p_Data.game_info.Get_state() == Game_info::e_State::START_SCREEN) {
		
		// Initializing
		l_Data = Init(p_Data);
		
		// Checking if a start is requested
		if (p_Data.game_info.Get_input_key() == (unsigned char)Game_info::e_Cmd::RUN_CMD) {

			// Run the game
			l_Data.game_info.Set_state(Game_info::e_State::RUNNING) ;
		}

		// Exiting the if requested
		if (p_Data.game_info.Get_input_key() == (unsigned char)Game_info::e_Cmd::ESC_CMD) {
			// Quit the game
			exit(55);
		}
	}

	// Running state
	else if (p_Data.game_info.Get_state() ==Game_info::e_State::RUNNING) {

		// Checking if the game is over
		if (p_Data.game_info.Get_code() == Game_info::e_Cmd::WALL_HIT_CMD || p_Data.game_info.Get_code() == Game_info::e_Cmd::COLLISION_CMD) {
			// Put an end to the game
			l_Data.game_info.Set_state(Game_info::e_State::GAME_OVER);
		}

		// Checking if a pause is requested
		else if (p_Data.game_info.Get_input_key() == (unsigned short)Game_info::e_Cmd::PAUSE_CMD || \
			     p_Data.game_info.Get_input_key() == (unsigned short)Game_info::e_Cmd::ESC_CMD	) {
			// Pause the game
			l_Data.game_info.Set_state(Game_info::e_State::PAUSE);
		}
	}

	// Pause state
	else if (p_Data.game_info.Get_state() ==Game_info::e_State::PAUSE) {
		
		// Checking whether the game is resumed
		if (p_Data.game_info.Get_input_key() == (unsigned short)Game_info::e_Cmd::PAUSE_CMD || p_Data.game_info.Get_input_key() == (unsigned short)Game_info::e_Cmd::ESC_CMD) {
			// Resume the game
			l_Data.game_info.Set_state(Game_info::e_State::RUNNING);
		}

		// Checking if a restart is requested
		else if (p_Data.game_info.Get_input_key() == (unsigned short)Game_info::e_Cmd::RESTART_CMD) {
			// Back to main menu
			l_Data.game_info.Set_state(Game_info::e_State::START_SCREEN);
		}
	}

	// Game over state
	else if (p_Data.game_info.Get_state() ==Game_info::e_State::GAME_OVER) {
		
		// Restart the game
		if (p_Data.game_info.Get_input_key() == (unsigned short)Game_info::e_Cmd::RESTART_CMD) {
			l_Data.game_info.Set_state(Game_info::e_State::START_SCREEN);
			l_Data.game_info.Set_code(Game_info::e_Cmd::NO_CMD);
		}

		// Quit the game
		else if (p_Data.game_info.Get_input_key() == (unsigned short)Game_info::e_Cmd::ESC_CMD) {
			exit(0);
		}
	}
	l_Data.game_info.Set_input_key(0);	/////////////////

	// Return the updated state
	return l_Data;
}
