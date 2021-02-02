/*
	File: Draw.cpp
	Author:	H.CHERGUI
	First version: 2.0
	First version date: xxxxxxxxxx
	current version: 2.0
	current version date: xxxxxxxxxx
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
void Draw() {
	drawgrid();
	draw_snake();
	draw_fewd();
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
	glColor3f(0.35, 0.35, 0.35);
	glRectd(fx + 0.1, fy + 0.1, fx + 0.9, fy + 0.9);

	glColor3f(0.1, 0.1, 0.1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(fx + 0.3F, fy + 0.3F);
	glVertex2f(fx + 0.7F, fy + 0.3F);
	glVertex2f(fx + 0.7F, fy + 0.7F);
	glVertex2f(fx + 0.3F, fy + 0.7F);
	glEnd();
}
