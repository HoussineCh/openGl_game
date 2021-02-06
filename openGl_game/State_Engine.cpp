/*
	File: Input.cpp
	Author: H.CHERGUI
	First version: 2.0
	First version date: 03/02/2021
	Current version: 3.1
	Current version date: 06/02/2021
*/


// System files includes
/*NONE*/

// User defined files includes
#include "State_Engine.h"


// Determining the current state of the game
Game_info State_Engine(Game_info p_game_info) {

	// Local variables
	//Game_info g_Game_info = g_Game_info;

	// Start screen
	if (g_Game_info.Get_state() == Game_info::e_State::START_SCREEN) {
		
		// Initializing
		Init();
		
		// Checking if a start is requested
		if (g_Game_info.Get_input_key() == (unsigned char)Game_info::e_Cmd::RUN_CMD) {

			// Run the game
			g_Game_info.Set_state(Game_info::e_State::RUNNING) ;
		}

		// Exiting the if requested
		if (g_Game_info.Get_input_key() == (unsigned char)Game_info::e_Cmd::ESC_CMD) {
			// Quit the game
			exit(55);
		}
	}

	// Running state
	else if (g_Game_info.Get_state() ==Game_info::e_State::RUNNING) {

		// Checking if the game is over
		if (g_Game_info.Get_code() == Game_info::e_Cmd::WALL_HIT_CMD || g_Game_info.Get_code() == Game_info::e_Cmd::COLLISION_CMD) {
			// Put an end to the game
			g_Game_info.Set_state(Game_info::e_State::GAME_OVER);
		}

		// Checking if a pause is requested
		else if (g_Game_info.Get_input_key() == (unsigned short)Game_info::e_Cmd::PAUSE_CMD || g_Game_info.Get_input_key() == (unsigned short)Game_info::e_Cmd::ESC_CMD) {
			// Pause the game
			g_Game_info.Set_state(Game_info::e_State::PAUSE);
		}
	}

	// Pause state
	else if (g_Game_info.Get_state() ==Game_info::e_State::PAUSE) {
		
		// Checking whether the game is resumed
		if (g_Game_info.Get_input_key() == (unsigned short)Game_info::e_Cmd::PAUSE_CMD || g_Game_info.Get_input_key() == (unsigned short)Game_info::e_Cmd::ESC_CMD) {
			// Resume the game
			g_Game_info.Set_state(Game_info::e_State::RUNNING);
		}

		// Checking if a restart is requested
		else if (g_Game_info.Get_input_key() == (unsigned short)Game_info::e_Cmd::RESTART_CMD) {
			// Back to main menu
			g_Game_info.Set_state(Game_info::e_State::START_SCREEN);
		}
	}

	// Game over state
	else if (g_Game_info.Get_state() ==Game_info::e_State::GAME_OVER) {
		
		// Restart the game
		if (g_Game_info.Get_input_key() == (unsigned short)Game_info::e_Cmd::RESTART_CMD) {
			g_Game_info.Set_state(Game_info::e_State::START_SCREEN);
			g_Game_info.Set_code(Game_info::e_Cmd::NO_CMD);
		}

		// Quit the game
		else if (g_Game_info.Get_input_key() == (unsigned short)Game_info::e_Cmd::ESC_CMD) {
			exit(0);
		}
	}
	g_Game_info.Set_input_key(0);
	// Return the updated state
	return g_Game_info;
}

