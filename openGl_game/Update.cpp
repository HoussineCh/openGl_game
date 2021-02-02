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
void Update() {
	ud_snake();
	check_event();
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

	if (sDirection == UP)
		yy++;
	else if (sDirection == DOWN)
		yy--;
	else if (sDirection == RIGHT)
		xx++;
	else if (sDirection == LEFT)
		xx--;
}


void check_event() {
	bool state = 0;
	for (int i = 0; i < tail_len; i++) {
		if (xx == tail[i].first && yy == tail[i].second) {
			state = 1;
			break;
		}
	}
	if (xx == 0 || xx == COL - 1 || yy == 0 || yy == ROW - 3) {
		state = 1;
	}
	if (state) {
		char s[15];
		_itoa_s(score, s, 10);
		char t[250] = "teh score is: ";
		strcat_s(t, s);
		strcat_s(t, "\nSnaeke!...                           SNAAAEKE!\n\n                    (continue y/n?)");
		MessageBox(NULL, LPCSTR(t), LPCSTR("Game Over!"), 0);
		exit(0);
	}
	if (fx == xx && fy == yy) {
		score += 10;
		tail_len++;
		srand(time(NULL));
		fx = rand() % (COL - 2) + 1;
		fy = rand() % (ROW - 4) + 1;
	}
}