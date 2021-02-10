/*
	File: Draw_Grid.cpp
	Author:	H.CHERGUI
	First version: 3.6
	First version date: 10/02/2021
	Current version: 3.6
	Current version date: 10/02/2021
*/


// System files includes
/*NONE*/

// User defined files includes
#include "Draw.h"


// Draw the grid
void Draw_Grid() {
	glColor3f(0.45, 0.45, 0.55);
	for (int y = 0; y < GC_ROW - 2; y++) {
		glRectd(0 + 0.1, y + 0.1, 0.9, y + 0.9);
	}
	for (int x = 1; x < GC_COL; x++) {
		glRectd(x + 0.1, 0 + 0.1, x + 0.9, 0.9); glRectd(x + 0.1, GC_ROW - 3 + 0.1, x + 0.9, GC_ROW - 2.1);
	}
	for (int y = 0; y < GC_ROW - 2; y++) {
		glRectd(GC_COL - 1 + 0.1, y + 0.1, GC_COL, y + 0.9);
	}

	for (int y = 0; y < GC_ROW - 2; y++) {
		Draw_Unit(0, y);
	}
	for (int x = 1; x < GC_COL; x++) {
		Draw_Unit(x, 0);  Draw_Unit(x, GC_ROW - 3);
	}
	for (int y = 0; y < GC_ROW - 2; y++) {
		Draw_Unit(GC_COL - 1, y);
	}
	glColor3f(0.0, 0.0, 0.0);
	for (int x = 1; x < GC_COL - 1; x++) {
		for (int y = 1; y < GC_ROW - 3; y++) {
			Draw_Unit(x, y);
		}
	}
}

// Draw an unfilled rectangle
void Draw_Unit(double x, double y) {
	glLineWidth(0.5);
	glBegin(GL_LINE_LOOP);
	glVertex2f(x, y);
	glVertex2f(x + 1.0F, y);
	glVertex2f(x + 1.0F, y + 1.0F);
	glVertex2f(x, y + 1.0F);
	glEnd();
}
