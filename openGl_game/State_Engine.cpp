/*
	File: Input.cpp
	Author: H.CHERGUI
	First version: 2.5
	First version date: 25/01/2021
	Current version: 2.6
	Current version date: 29/01/2021
*/


// System files includes
/*NONE*/

// User defined files includes
#include "State_Engine.h"


// Definition of the function State_Engine()

e_State State_Engine(s_Game_info p_current_state, int p_in_cmd) {

	// Local variables
	e_State l_current_state = p_current_state.state;

	// Start screen
	if (p_current_state.state == e_State::START_SCREEN) {
		
		// Initializing
		Init();

		// Checking if a start is requested
		if (p_in_cmd == (unsigned short)e_Cmd::RUN) {

			// Run the game
			l_current_state = e_State::RUNNING;
		}
	}

	// Running state
	else if (p_current_state.state == e_State::RUNNING) {

		// Checking if the game is over
		if (p_current_state.code == e_Cmd::WALL_HIT || p_current_state.code == e_Cmd::COLLISION) {
			// Put an end to the game
			l_current_state = e_State::GAME_OVER;
		}

		// Checking if a pause is requested
		else if (p_in_cmd == (unsigned short)e_Cmd::PAUSE || p_in_cmd == (unsigned short)e_Cmd::PAUSE2) {
			// Pause the game
			l_current_state = e_State::PAUSE;
			g_key = 0;
		}
	}

	// Pause state
	else if (p_current_state.state == e_State::PAUSE) {
		
		// Checking whether the game is resumed
		if (p_in_cmd == (unsigned short)e_Cmd::PAUSE || p_in_cmd == (unsigned short)e_Cmd::PAUSE2) {
			// Resume the game
			l_current_state = e_State::RUNNING;
			g_key = 0;
		}

		// Checking if a restart is requested
		else if (p_in_cmd == (unsigned short)e_Cmd::RESTART) {
			// Back to main menu
			l_current_state = e_State::START_SCREEN;
		}
	}

	// Game over state
	else if (p_current_state.state == e_State::GAME_OVER) {
		// Back to main menu
		l_current_state = e_State::START_SCREEN;	
		e_Cmd::NO_CMD;
	}

	// Return the updated state
	return l_current_state;
}

