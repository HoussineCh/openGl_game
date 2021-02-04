/*
	File: Update.cpp
	Author: H.CHERGUI
	First version: 2.0
	First version date: 03/02/2021
	current version: 2.7.5
	current version date: 04/02/2021
*/

// System files includes
/*NONE*/

// User defined files includes
#include "Update.h"


// Definition of the update function
s_Game_info Update(s_Game_info p_status, unsigned short p_in_cmd) {

	// Local variables
	s_Game_info l_status;

	// Determining the current state
	l_status.state = State_Engine(p_status, p_in_cmd);

	if (l_status.state == e_State::RUNNING) {

		// Check if snaek ate the fruit
		check_fruit();

		// Updating the snake
		ud_snake();

		// Check if a game over occured
		l_status.code = check_game_over();
	}

	// Return game status
	return l_status;
}

void ud_snake() {

	// update da tael!
	std::pair<int, int> prev;
	for (int i = 1; i < tail_len; i++) {
		prev = tail[i];
		tail[i] = tail[0];
		tail[0] = prev;
	}
	tail[0] = std::make_pair(xx, yy);

	// Move the snake
	if (g_Direction == e_DIrection::UP)
		yy++;
	else if (g_Direction == e_DIrection::DOWN)
		yy--;
	else if (g_Direction == e_DIrection::RIGHT)
		xx++;
	else if (g_Direction == e_DIrection::LEFT)
		xx--;
}


// Check if the snaek ate the fruit
void check_fruit() {
	if (fx == xx && fy == yy) {
		score += 10;
		tail_len++;
		srand(unsigned int(time(NULL)));
		fx = rand() % (GC_COL - 6) + 3;
		fy = rand() % (GC_ROW - 7) + 2;
	}
}


// Check for a game over
e_Cmd check_game_over() {

	// Local variable
	e_Cmd l_cmd = e_Cmd::RUN;

	// Check if a collision happened
	for (int i = 0; i < tail_len; i++) {
		if (xx == tail[i].first && yy == tail[i].second) {
			l_cmd = e_Cmd::COLLISION;
			break;
		}
	}

	// Check if snaek hit a wall
	if (xx == 0 || xx == GC_COL - 1 || yy == 0 || yy == GC_ROW - 3) {
		l_cmd = e_Cmd::WALL_HIT;
	}

	// Return status command
	return l_cmd;
}