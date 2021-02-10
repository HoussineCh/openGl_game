/*
	File: Update_Cmd.cpp
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


// Check for a game over
Game_info::e_Cmd Update_Cmd(Snake p_snake) {

	// Local variable
	Game_info::e_Cmd l_cmd = Game_info::e_Cmd::RUN_CMD;

	// Check if a collision happened
	for (int i = 0; i < p_snake.Get_Tail_length(); i++) {
		if (p_snake.Get_Coordinates() == p_snake.Get_Tail(i)) {
			l_cmd = Game_info::e_Cmd::COLLISION_CMD;
			break;
		}
	}

	// Check if the snake hit a wall
	if (p_snake.Get_Coordinates().first == 0 || \
		p_snake.Get_Coordinates().first == GC_COL - 1 || \
		p_snake.Get_Coordinates().second == 0 || \
		p_snake.Get_Coordinates().second == GC_ROW - 3)
	{
		l_cmd = Game_info::e_Cmd::WALL_HIT_CMD;
	}

	// Return execution cmd
	return l_cmd;
}
