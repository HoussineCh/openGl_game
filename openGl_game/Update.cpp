/*
	File: Update.cpp
	Author:	H.CHERGUI
	First version: 1.0
	First version date: 02/02/2021
	current version: 1.0
	current version date: 02/02/2021
*/

// Sys includes
/*NONE*/

// User includes
#include "Update.h"



// Definitions
void Update() {
	drawgrid();
	draw_snake();
	check_collision();
	draw_fewd();
	draw_txt();
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
	// update da tael!
	std::pair<int, int> prev;
	for (int i = 1; i < tail_len; i++) {
		prev = tail[i];
		tail[i] = tail[0];
		tail[0] = prev;
	}
	tail[0] = std::make_pair(xx, yy);

	glColor3f(0.29, 0.29, 0.85);
	if (sDirection == UP)
		yy++;
	else if (sDirection == DOWN)
		yy--;
	else if (sDirection == RIGHT)
		xx++;
	else if (sDirection == LEFT)
		xx--;

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

void draw_txt() {
	char s[10];
	_itoa_s(score, s, 10);
	std::string s_score = "score: ";
	s_score += s;

	char s2[10];
	_itoa_s(hi_score, s2, 10);
	std::string s_hi_score = "hi-score: ";
	s_hi_score += s2;

	/*DrawText(NULL, (LPCTSTR)s_score.data(), s_score.size(), &get_rect, DT_LEFT);
	DrawText(NULL, (LPCTSTR)s_hi_score.data(), s_hi_score.size(), &get_rect, DT_RIGHT);*/

}

void check_collision() {
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