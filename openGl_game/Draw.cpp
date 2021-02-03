/*
	File: Draw.cpp
	Author:	H.CHERGUI
	First version: 2.0
	First version date: 03/02/2021
	current version: 2.5
	current version date: 03/02/2021
*/


// System files includes
/*NONE*/

// User defined files includes
#include "Draw.h"


/*Global Variables definition*/
/*NONE*/

/*Global Constants*/
/*NONE*/


// Drawing the content on the screen
void Draw(s_Game_info p_Game_info) {
	if (p_Game_info.state == e_State::RUNNING) {
		draw_snake();
		draw_fewd();
	}
	else if( p_Game_info.state == e_State::PAUSE) {
		draw_snake();
		draw_fewd();
		draw_pause();
	}
	else if (p_Game_info.state == e_State::GAME_OVER) {
		char s[15];
		_itoa_s(score, s, 10);
		char t[250] = "teh score is: ";
		strcat_s(t, s);
		if (p_Game_info.code == e_Cmd::COLLISION) {
			strcat_s(t, "\nYou just hit yourself!!! Dont do that again!!");
			strcat_s(t, "\n\n\nSnaeke!...                           SNAAAEKE!\n\n                    (continue y/n?)");
		}
		else if (p_Game_info.code == e_Cmd::WALL_HIT) {
			strcat_s(t, "\nDon't run away! stay inside the map!!");
			strcat_s(t, "\n\n\nSnaeke!...                           SNAAAEKE!\n\n                    (continue y/n?)");
		}
		MessageBox(NULL, LPCSTR(t), LPCSTR("Game Over!"), 0);
	}
	drawgrid();
}

void drawgrid() {
	glColor3f(0.29, 0.29, 0.39);
	for (int y = 0; y < gridY - 2; y++) {
		glRectd(0 + 0.1, y + 0.1, 0.9, y + 0.9);
	}
	for (int x = 1; x < gridX; x++) {
		glRectd(x + 0.1, 0 + 0.1, x + 0.9, 0.9); glRectd(x + 0.1, gridY - 3 + 0.1, x + 0.9, gridY - 2.1);
	}
	for (int y = 0; y < gridY - 2; y++) {
		glRectd(gridX - 1 + 0.1, y + 0.1, gridX, y + 0.9);
	}

	glColor3f(0.0, 0.0, 0.0);
	for (int x = 1; x < gridX - 1; x++) {
		for (int y = 1; y < gridY - 3; y++) {
			unit(x, y);
		}
	}

	glColor3f(0.29, 0.29, 0.39);
	for (int y = 0; y < gridY - 2; y++) {
		unit(0, y);
	}
	for (int x = 1; x < gridX; x++) {
		unit(x, 0);  unit(x, gridY - 3);
	}
	for (int y = 0; y < gridY - 2; y++) {
		unit(gridX - 1, y);
	}
}

void unit(float x, float y) {
	glLineWidth(0.5);

	glBegin(GL_LINE_LOOP);
	glVertex2f(x, y);
	glVertex2f(x + 1.0F, y);
	glVertex2f(x + 1.0F, y + 1.0F);
	glVertex2f(x, y + 1.0F);
	glEnd();
}

void draw_snake() {
	glColor3f(0.29, 0.29, 0.85);
	glRectd(xx + 0.1, yy + 0.1, xx + 0.9, yy + 0.9);
	glColor3f(0.29, 0.29, 0.7);

	for (int i = 0; i < tail_len; i++) {
		glRectd(tail[i].first + 0.3, tail[i].second + 0.3, tail[i].first + 0.7, tail[i].second + 0.7);
	}
}

void draw_fewd() {
	glColor3f(0.55, 0.55, 0.65);
	glRectd(fx + 0.1, fy + 0.1, fx + 0.9, fy + 0.9);

	glColor3f(0.1, 0.1, 0.1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(fx + 0.3F, fy + 0.3F);
	glVertex2f(fx + 0.7F, fy + 0.3F);
	glVertex2f(fx + 0.7F, fy + 0.7F);
	glVertex2f(fx + 0.3F, fy + 0.7F);
	glEnd();
}

void draw_pause() {
	glColor3f(0.35, 0.2, 0.65);
	
	/* P */
	glRectd(GC_OS_X, GC_OS_Y, GC_OS_X+1, GC_OS_Y+5);
	glRectd(GC_OS_X+1, GC_OS_Y+2, GC_OS_X+2, GC_OS_Y+3);
	glRectd(GC_OS_X+1, GC_OS_Y+4, GC_OS_X+2, GC_OS_Y+5);
	glRectd(GC_OS_X+2, GC_OS_Y+3, GC_OS_X+3, GC_OS_Y+4);

	/* A */
	glRectd(GC_OS_X+4, GC_OS_Y, GC_OS_X + 5, GC_OS_Y + 4);
	glRectd(GC_OS_X+5, GC_OS_Y+2, GC_OS_X + 6, GC_OS_Y + 3);
	glRectd(GC_OS_X+5, GC_OS_Y+4, GC_OS_X + 6, GC_OS_Y + 5);
	glRectd(GC_OS_X+6, GC_OS_Y, GC_OS_X + 7, GC_OS_Y + 4);

	/* U */
	glRectd(GC_OS_X + 8, GC_OS_Y+0, GC_OS_X + 9, GC_OS_Y + 5);
	glRectd(GC_OS_X + 9, GC_OS_Y , GC_OS_X + 10, GC_OS_Y + 1);
	glRectd(GC_OS_X + 10, GC_OS_Y+0, GC_OS_X + 11, GC_OS_Y + 5);

	/* S */
	glRectd(GC_OS_X+12, GC_OS_Y, GC_OS_X + 14, GC_OS_Y + 1);
	glRectd(GC_OS_X+14, GC_OS_Y+1, GC_OS_X + 15, GC_OS_Y + 2);
	glRectd(GC_OS_X+13, GC_OS_Y+2, GC_OS_X + 14, GC_OS_Y + 3);
	glRectd(GC_OS_X+12, GC_OS_Y+3, GC_OS_X + 13, GC_OS_Y + 4);
	glRectd(GC_OS_X+13, GC_OS_Y+4, GC_OS_X + 15, GC_OS_Y + 5);

	/* E */
	glRectd(GC_OS_X + 16, GC_OS_Y, GC_OS_X + 17, GC_OS_Y + 5);
	glRectd(GC_OS_X + 17, GC_OS_Y , GC_OS_X + 19, GC_OS_Y + 1);
	glRectd(GC_OS_X + 17, GC_OS_Y+2, GC_OS_X + 18, GC_OS_Y + 3);
	glRectd(GC_OS_X + 17, GC_OS_Y+4, GC_OS_X + 19, GC_OS_Y + 5);
}
