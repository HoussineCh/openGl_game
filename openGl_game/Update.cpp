/*
	File: Update.cpp
	Author: H.CHERGUI
	First version: 2.0
	First version date: 03/02/2021
	current version: 3.1
	current version date: 06/02/2021
*/

// System files includes
/*NONE*/

// User defined files includes
#include "Update.h"


// Definition of the update function
s_Data_Cluster Update(s_Data_Cluster p_data) {

	// Local variables
	
	// Determining the current state
	g_Game_info = State_Engine(g_Game_info);

	if (g_Game_info.Get_state() == Game_info::e_State::RUNNING) {

		// Check if snaek ate the fruit
		check_fruit();

		// Updating the snake
		ud_snake();

		// Check if a game over occured
		check_game_over();
	}

	// Return Updated data
	s_Data_Cluster local = { g_Game_info, g_Snake, g_Food };
	return local;
}

void ud_snake() {

	// update da tael!
	std::pair<int, int> l_prev;
	for (int i = 1; i < g_Snake.Get_Tail_length(); i++) {
		l_prev = g_Snake.Get_Tail(i);
		g_Snake.Set_Tail(g_Snake.Get_Tail(0), i);
		g_Snake.Set_Tail(l_prev, 0);

	}
	g_Snake.Set_Tail(g_Snake.Get_Coordinates(), 0);
	
	// Move the snake
	if (g_Snake.Get_Direction() == Snake::e_Direction::UP)
		g_Snake.IncY();
	else if (g_Snake.Get_Direction() == Snake::e_Direction::DOWN)
		g_Snake.DecY();
	else if (g_Snake.Get_Direction() == Snake::e_Direction::RIGHT)
		g_Snake.IncX();
	else if (g_Snake.Get_Direction() == Snake::e_Direction::LEFT)
		g_Snake.DecX();
}


// Check if the snaek ate the fruit
void check_fruit() {
	if (g_Snake.Get_Coordinates() == g_Food.Get_Coordinates()) {
		g_Game_info.Determine_Score();		
		g_Snake.Grow_Tail();
		g_Food.Generate_cordinates();
	}
}


// Check for a game over
void check_game_over() {

	// Local variable
	//Game_info::e_Cmd l_cmd = Game_info::e_Cmd::RUN_CMD;

	// Check if a collision happened
	for (int i = 0; i < g_Snake.Get_Tail_length(); i++) {
		if (g_Snake.Get_Coordinates() == g_Snake.Get_Tail(i)) {
			g_Game_info.Set_code(Game_info::e_Cmd::COLLISION_CMD);
			break;
		}
	}

	// Check if snaek hit a wall
	if (g_Snake.Get_Coordinates().first == 0		  || \
		g_Snake.Get_Coordinates().first == GC_COL - 1 || \
		g_Snake.Get_Coordinates().second == 0		  || \
		g_Snake.Get_Coordinates().second == GC_ROW - 3) 
	{
		g_Game_info.Set_code(Game_info::e_Cmd::WALL_HIT_CMD);
	}

	// Return status command
	//return l_cmd;
}