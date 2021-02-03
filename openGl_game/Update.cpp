/*
	File: Update.cpp
	Author: H.CHERGUI
	First version: 2.0
	First version date: xxxxxxx
	current version: 2.0
	current version date: xxxxxxxx
*/

// System files includes
/*NONE*/

// User defined files includes
#include "Update.h"

/*Global Variables definition*/
/*NONE*/

/*Global Constants*/
/*NONE*/


// Definition of the update function
s_Game_info Update(s_Game_info p_status, unsigned short p_in_cmd) {

	// Local variables
	s_Game_info l_status;

	// Determining the current state
	l_status.state = State_Engine(p_status, p_in_cmd);

	if (l_status.state == e_State::RUNNING) {

		// Updating the snake
		ud_snake();

		// Check if snaek ate the fruit, and if a game over occured
		l_status.code = check_event();
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

	if (g_Direction == e_DIrection::UP)
		yy++;
	else if (g_Direction == e_DIrection::DOWN)
		yy--;
	else if (g_Direction == e_DIrection::RIGHT)
		xx++;
	else if (g_Direction == e_DIrection::LEFT)
		xx--;
}


e_Cmd check_event() {

	// Local variable
	e_Cmd l_cmd = e_Cmd::RUN;


	for (int i = 0; i < tail_len; i++) {
		if (xx == tail[i].first && yy == tail[i].second) {
			l_cmd = e_Cmd::COLLISION;
			break;
		}
	}

	if (xx == 0 || xx == GC_COL - 1 || yy == 0 || yy == GC_ROW - 3) {
		l_cmd = e_Cmd::WALL_HIT;
	}
		

	if (fx == xx && fy == yy) {
		score += 10;
		tail_len++;
		srand(unsigned int(time(NULL)));
		fx = rand() % (GC_COL - 2) + 1;
		fy = rand() % (GC_ROW - 4) + 1;
	}

	// Return status command
	return l_cmd;
}