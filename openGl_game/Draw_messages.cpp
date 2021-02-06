/*
	File: Draw_messages.cpp
	Author:	H.CHERGUI
	First version: 2.7
	First version date: 04/02/2021
	current version: 2.7
	current version date: 04/02/2021
*/


// System files includes
/*NONE*/

// User defined files includes
#include "Draw.h"

// On-screen messages definition
void draw_pause() {
	glColor3f(0.35, 0.2, 0.65);

	/* P */
	glRectd(GC_P_OS_X,	   GC_P_OS_Y,	  GC_P_OS_X + 1, GC_P_OS_Y + 5);
	glRectd(GC_P_OS_X + 1, GC_P_OS_Y + 2, GC_P_OS_X + 2, GC_P_OS_Y + 3);
	glRectd(GC_P_OS_X + 1, GC_P_OS_Y + 4, GC_P_OS_X + 2, GC_P_OS_Y + 5);
	glRectd(GC_P_OS_X + 2, GC_P_OS_Y + 3, GC_P_OS_X + 3, GC_P_OS_Y + 4);

	/* A */
	glRectd(GC_P_OS_X + 4, GC_P_OS_Y,	  GC_P_OS_X + 5, GC_P_OS_Y + 4);
	glRectd(GC_P_OS_X + 5, GC_P_OS_Y + 2, GC_P_OS_X + 6, GC_P_OS_Y + 3);
	glRectd(GC_P_OS_X + 5, GC_P_OS_Y + 4, GC_P_OS_X + 6, GC_P_OS_Y + 5);
	glRectd(GC_P_OS_X + 6, GC_P_OS_Y,	  GC_P_OS_X + 7, GC_P_OS_Y + 4);

	/* U */
	glRectd(GC_P_OS_X + 8,  GC_P_OS_Y + 0, GC_P_OS_X + 9,  GC_P_OS_Y + 5);
	glRectd(GC_P_OS_X + 9,  GC_P_OS_Y,	   GC_P_OS_X + 10, GC_P_OS_Y + 1);
	glRectd(GC_P_OS_X + 10, GC_P_OS_Y + 0, GC_P_OS_X + 11, GC_P_OS_Y + 5);

	/* S */
	glRectd(GC_P_OS_X + 12, GC_P_OS_Y,	   GC_P_OS_X + 14, GC_P_OS_Y + 1);
	glRectd(GC_P_OS_X + 14, GC_P_OS_Y + 1, GC_P_OS_X + 15, GC_P_OS_Y + 2);
	glRectd(GC_P_OS_X + 13, GC_P_OS_Y + 2, GC_P_OS_X + 14, GC_P_OS_Y + 3);
	glRectd(GC_P_OS_X + 12, GC_P_OS_Y + 3, GC_P_OS_X + 13, GC_P_OS_Y + 4);
	glRectd(GC_P_OS_X + 13, GC_P_OS_Y + 4, GC_P_OS_X + 15, GC_P_OS_Y + 5);

	/* E */
	glRectd(GC_P_OS_X + 16, GC_P_OS_Y,	   GC_P_OS_X + 17, GC_P_OS_Y + 5);
	glRectd(GC_P_OS_X + 17, GC_P_OS_Y,     GC_P_OS_X + 19, GC_P_OS_Y + 1);
	glRectd(GC_P_OS_X + 17, GC_P_OS_Y + 2, GC_P_OS_X + 18, GC_P_OS_Y + 3);
	glRectd(GC_P_OS_X + 17, GC_P_OS_Y + 4, GC_P_OS_X + 19, GC_P_OS_Y + 5);
}

void draw_game_over() {
	glColor3f(0.62, 0.5, 0.75);

	/* G */
	glRectd(GC_GO_OS_X,		GC_GO_OS_Y1 + 1, GC_GO_OS_X + 1, GC_GO_OS_Y1 + 4);
	glRectd(GC_GO_OS_X + 1, GC_GO_OS_Y1,	 GC_GO_OS_X + 4, GC_GO_OS_Y1 + 1);
	glRectd(GC_GO_OS_X + 1, GC_GO_OS_Y1 + 4, GC_GO_OS_X + 4, GC_GO_OS_Y1 + 5);
	glRectd(GC_GO_OS_X + 3, GC_GO_OS_Y1 + 2, GC_GO_OS_X + 5, GC_GO_OS_Y1 + 3);
	glRectd(GC_GO_OS_X + 4, GC_GO_OS_Y1 + 1, GC_GO_OS_X + 5, GC_GO_OS_Y1 + 2);

	/* A */
	glRectd(GC_GO_OS_X + 6,  GC_GO_OS_Y1,	  GC_GO_OS_X + 7,  GC_GO_OS_Y1 + 4);
	glRectd(GC_GO_OS_X + 10, GC_GO_OS_Y1,	  GC_GO_OS_X + 11, GC_GO_OS_Y1 + 4);
	glRectd(GC_GO_OS_X + 7,  GC_GO_OS_Y1 + 2, GC_GO_OS_X + 10, GC_GO_OS_Y1 + 3);
	glRectd(GC_GO_OS_X + 7,  GC_GO_OS_Y1 + 4, GC_GO_OS_X + 10, GC_GO_OS_Y1 + 5);

	/* M */
	glRectd(GC_GO_OS_X + 12, GC_GO_OS_Y1,	  GC_GO_OS_X + 13, GC_GO_OS_Y1 + 5);
	glRectd(GC_GO_OS_X + 13, GC_GO_OS_Y1 + 3, GC_GO_OS_X + 14, GC_GO_OS_Y1 + 4);
	glRectd(GC_GO_OS_X + 14, GC_GO_OS_Y1 + 2, GC_GO_OS_X + 15, GC_GO_OS_Y1 + 3);
	glRectd(GC_GO_OS_X + 15, GC_GO_OS_Y1 + 3, GC_GO_OS_X + 16, GC_GO_OS_Y1 + 4);
	glRectd(GC_GO_OS_X + 16, GC_GO_OS_Y1,	  GC_GO_OS_X + 17, GC_GO_OS_Y1 + 5);

	/* E */
	glRectd(GC_GO_OS_X + 18, GC_GO_OS_Y1,	  GC_GO_OS_X + 19, GC_GO_OS_Y1 + 5);
	glRectd(GC_GO_OS_X + 19, GC_GO_OS_Y1,	  GC_GO_OS_X + 23, GC_GO_OS_Y1 + 1);
	glRectd(GC_GO_OS_X + 19, GC_GO_OS_Y1 + 2, GC_GO_OS_X + 22, GC_GO_OS_Y1 + 3);
	glRectd(GC_GO_OS_X + 19, GC_GO_OS_Y1 + 4, GC_GO_OS_X + 23, GC_GO_OS_Y1 + 5);


	/* O */
	glRectd(GC_GO_OS_X,		GC_GO_OS_Y2 + 1, GC_GO_OS_X + 1, GC_GO_OS_Y2 + 4);
	glRectd(GC_GO_OS_X + 4, GC_GO_OS_Y2 + 1, GC_GO_OS_X + 5, GC_GO_OS_Y2 + 4);
	glRectd(GC_GO_OS_X + 1, GC_GO_OS_Y2,	 GC_GO_OS_X + 4, GC_GO_OS_Y2 + 1);
	glRectd(GC_GO_OS_X + 1, GC_GO_OS_Y2 + 4, GC_GO_OS_X + 4, GC_GO_OS_Y2 + 5);

	/* V */
	glRectd(GC_GO_OS_X + 6,  GC_GO_OS_Y2 + 2, GC_GO_OS_X + 7,  GC_GO_OS_Y2 + 5);
	glRectd(GC_GO_OS_X + 10, GC_GO_OS_Y2 + 2, GC_GO_OS_X + 11, GC_GO_OS_Y2 + 5);
	glRectd(GC_GO_OS_X + 7,  GC_GO_OS_Y2 + 1, GC_GO_OS_X + 8,  GC_GO_OS_Y2 + 2);
	glRectd(GC_GO_OS_X + 9,  GC_GO_OS_Y2 + 1, GC_GO_OS_X + 10, GC_GO_OS_Y2 + 2);
	glRectd(GC_GO_OS_X + 8,  GC_GO_OS_Y2 + 0, GC_GO_OS_X + 9,  GC_GO_OS_Y2 + 1);

	/* E */
	glRectd(GC_GO_OS_X + 12, GC_GO_OS_Y2,	  GC_GO_OS_X + 13, GC_GO_OS_Y2 + 5);
	glRectd(GC_GO_OS_X + 13, GC_GO_OS_Y2,	  GC_GO_OS_X + 17, GC_GO_OS_Y2 + 1);
	glRectd(GC_GO_OS_X + 13, GC_GO_OS_Y2 + 2, GC_GO_OS_X + 16, GC_GO_OS_Y2 + 3);
	glRectd(GC_GO_OS_X + 13, GC_GO_OS_Y2 + 4, GC_GO_OS_X + 17, GC_GO_OS_Y2 + 5);

	/* R */
	glRectd(GC_GO_OS_X + 18, GC_GO_OS_Y2,	  GC_GO_OS_X + 19, GC_GO_OS_Y2 + 5);
	glRectd(GC_GO_OS_X + 19, GC_GO_OS_Y2 + 2, GC_GO_OS_X + 22, GC_GO_OS_Y2 + 3);
	glRectd(GC_GO_OS_X + 19, GC_GO_OS_Y2 + 4, GC_GO_OS_X + 22, GC_GO_OS_Y2 + 5);
	glRectd(GC_GO_OS_X + 22, GC_GO_OS_Y2 + 3, GC_GO_OS_X + 23, GC_GO_OS_Y2 + 4);
	glRectd(GC_GO_OS_X + 22, GC_GO_OS_Y2,	  GC_GO_OS_X + 23, GC_GO_OS_Y2 + 2);
}

void draw_start() {
	glColor3f(0.55, 0.55, 0.85);

	/* H */
	glRectd(GC_S_OS_X1,		GC_S_OS_Y1,		GC_S_OS_X1 + 1, GC_S_OS_Y1 + 5);
	glRectd(GC_S_OS_X1 + 1, GC_S_OS_Y1 + 2, GC_S_OS_X1 + 4, GC_S_OS_Y1 + 3);
	glRectd(GC_S_OS_X1 + 4, GC_S_OS_Y1,		GC_S_OS_X1 + 5, GC_S_OS_Y1 + 5);

	/* O */
	glRectd(GC_S_OS_X1 + 6,  GC_S_OS_Y1 + 1, GC_S_OS_X1 + 7,  GC_S_OS_Y1 + 4);
	glRectd(GC_S_OS_X1 + 10, GC_S_OS_Y1 + 1, GC_S_OS_X1 + 11, GC_S_OS_Y1 + 4);
	glRectd(GC_S_OS_X1 + 7,  GC_S_OS_Y1,	 GC_S_OS_X1 + 10, GC_S_OS_Y1 + 1);
	glRectd(GC_S_OS_X1 + 7,  GC_S_OS_Y1 + 4, GC_S_OS_X1 + 10, GC_S_OS_Y1 + 5);

	/* U */
	glRectd(GC_S_OS_X1 + 12, GC_S_OS_Y1 + 1, GC_S_OS_X1 + 13, GC_S_OS_Y1 + 5);
	glRectd(GC_S_OS_X1 + 13, GC_S_OS_Y1,	 GC_S_OS_X1 + 16, GC_S_OS_Y1 + 1);
	glRectd(GC_S_OS_X1 + 16, GC_S_OS_Y1 + 1, GC_S_OS_X1 + 17, GC_S_OS_Y1 + 5);

	/* S */
	glRectd(GC_S_OS_X1 + 18, GC_S_OS_Y1,	 GC_S_OS_X1 + 22, GC_S_OS_Y1 + 1);
	glRectd(GC_S_OS_X1 + 22, GC_S_OS_Y1 + 1, GC_S_OS_X1 + 23, GC_S_OS_Y1 + 2);
	glRectd(GC_S_OS_X1 + 19, GC_S_OS_Y1 + 2, GC_S_OS_X1 + 22, GC_S_OS_Y1 + 3);
	glRectd(GC_S_OS_X1 + 18, GC_S_OS_Y1 + 3, GC_S_OS_X1 + 19, GC_S_OS_Y1 + 4);
	glRectd(GC_S_OS_X1 + 19, GC_S_OS_Y1 + 4, GC_S_OS_X1 + 23, GC_S_OS_Y1 + 5);

	/* S */
	glRectd(GC_S_OS_X1 + 24, GC_S_OS_Y1,	 GC_S_OS_X1 + 28, GC_S_OS_Y1 + 1);
	glRectd(GC_S_OS_X1 + 28, GC_S_OS_Y1 + 1, GC_S_OS_X1 + 29, GC_S_OS_Y1 + 2);
	glRectd(GC_S_OS_X1 + 25, GC_S_OS_Y1 + 2, GC_S_OS_X1 + 28, GC_S_OS_Y1 + 3);
	glRectd(GC_S_OS_X1 + 24, GC_S_OS_Y1 + 3, GC_S_OS_X1 + 25, GC_S_OS_Y1 + 4);
	glRectd(GC_S_OS_X1 + 25, GC_S_OS_Y1 + 4, GC_S_OS_X1 + 29, GC_S_OS_Y1 + 5);

	/* I */
	glRectd(GC_S_OS_X1 + 31, GC_S_OS_Y1,	 GC_S_OS_X1 + 34, GC_S_OS_Y1 + 1);
	glRectd(GC_S_OS_X1 + 32, GC_S_OS_Y1 + 1, GC_S_OS_X1 + 33, GC_S_OS_Y1 + 4);
	glRectd(GC_S_OS_X1 + 31, GC_S_OS_Y1 + 4, GC_S_OS_X1 + 34, GC_S_OS_Y1 + 5);

	/* N */
	glRectd(GC_S_OS_X1 + 36, GC_S_OS_Y1,	 GC_S_OS_X1 + 37, GC_S_OS_Y1 + 5);
	glRectd(GC_S_OS_X1 + 37, GC_S_OS_Y1 + 4, GC_S_OS_X1 + 38, GC_S_OS_Y1 + 5);
	glRectd(GC_S_OS_X1 + 38, GC_S_OS_Y1 + 1, GC_S_OS_X1 + 39, GC_S_OS_Y1 + 4);
	glRectd(GC_S_OS_X1 + 39, GC_S_OS_Y1,	 GC_S_OS_X1 + 40, GC_S_OS_Y1 + 1);
	glRectd(GC_S_OS_X1 + 40, GC_S_OS_Y1,	 GC_S_OS_X1 + 41, GC_S_OS_Y1 + 5);

	/* E */
	glRectd(GC_S_OS_X1 + 42, GC_S_OS_Y1,	 GC_S_OS_X1 + 43, GC_S_OS_Y1 + 5);
	glRectd(GC_S_OS_X1 + 43, GC_S_OS_Y1,	 GC_S_OS_X1 + 47, GC_S_OS_Y1 + 1);
	glRectd(GC_S_OS_X1 + 43, GC_S_OS_Y1 + 2, GC_S_OS_X1 + 46, GC_S_OS_Y1 + 3);
	glRectd(GC_S_OS_X1 + 43, GC_S_OS_Y1 + 4, GC_S_OS_X1 + 47, GC_S_OS_Y1 + 5);

	/* ' */
	glRectd(GC_S_OS_X1 + 48, GC_S_OS_Y1 + 4, GC_S_OS_X1 + 49, GC_S_OS_Y1 + 5);

	/* S */
	glRectd(GC_S_OS_X1 + 50, GC_S_OS_Y1,	 GC_S_OS_X1 + 54, GC_S_OS_Y1 + 1);
	glRectd(GC_S_OS_X1 + 54, GC_S_OS_Y1 + 1, GC_S_OS_X1 + 55, GC_S_OS_Y1 + 2);
	glRectd(GC_S_OS_X1 + 51, GC_S_OS_Y1 + 2, GC_S_OS_X1 + 54, GC_S_OS_Y1 + 3);
	glRectd(GC_S_OS_X1 + 50, GC_S_OS_Y1 + 3, GC_S_OS_X1 + 51, GC_S_OS_Y1 + 4);
	glRectd(GC_S_OS_X1 + 51, GC_S_OS_Y1 + 4, GC_S_OS_X1 + 55, GC_S_OS_Y1 + 5);


	/* G */
	glRectd(GC_S_OS_X2,		GC_S_OS_Y2 + 1, GC_S_OS_X2 + 1, GC_S_OS_Y2 + 4);
	glRectd(GC_S_OS_X2 + 1, GC_S_OS_Y2,		GC_S_OS_X2 + 4, GC_S_OS_Y2 + 1);
	glRectd(GC_S_OS_X2 + 1, GC_S_OS_Y2 + 4, GC_S_OS_X2 + 4, GC_S_OS_Y2 + 5);
	glRectd(GC_S_OS_X2 + 3, GC_S_OS_Y2 + 2, GC_S_OS_X2 + 5, GC_S_OS_Y2 + 3);
	glRectd(GC_S_OS_X2 + 4, GC_S_OS_Y2 + 1, GC_S_OS_X2 + 5, GC_S_OS_Y2 + 2);

	/* A */
	glRectd(GC_S_OS_X2 + 6,  GC_S_OS_Y2,	 GC_S_OS_X2 + 7,  GC_S_OS_Y2 + 4);
	glRectd(GC_S_OS_X2 + 10, GC_S_OS_Y2,	 GC_S_OS_X2 + 11, GC_S_OS_Y2 + 4);
	glRectd(GC_S_OS_X2 + 7,  GC_S_OS_Y2 + 2, GC_S_OS_X2 + 10, GC_S_OS_Y2 + 3);
	glRectd(GC_S_OS_X2 + 7,  GC_S_OS_Y2 + 4, GC_S_OS_X2 + 10, GC_S_OS_Y2 + 5);

	/* M */
	glRectd(GC_S_OS_X2 + 12, GC_S_OS_Y2,	 GC_S_OS_X2 + 13, GC_S_OS_Y2 + 5);
	glRectd(GC_S_OS_X2 + 13, GC_S_OS_Y2 + 3, GC_S_OS_X2 + 14, GC_S_OS_Y2 + 4);
	glRectd(GC_S_OS_X2 + 14, GC_S_OS_Y2 + 2, GC_S_OS_X2 + 15, GC_S_OS_Y2 + 3);
	glRectd(GC_S_OS_X2 + 15, GC_S_OS_Y2 + 3, GC_S_OS_X2 + 16, GC_S_OS_Y2 + 4);
	glRectd(GC_S_OS_X2 + 16, GC_S_OS_Y2,	 GC_S_OS_X2 + 17, GC_S_OS_Y2 + 5);

	/* E */
	glRectd(GC_S_OS_X2 + 18, GC_S_OS_Y2,	 GC_S_OS_X2 + 19, GC_S_OS_Y2 + 5);
	glRectd(GC_S_OS_X2 + 19, GC_S_OS_Y2,	 GC_S_OS_X2 + 23, GC_S_OS_Y2 + 1);
	glRectd(GC_S_OS_X2 + 19, GC_S_OS_Y2 + 2, GC_S_OS_X2 + 22, GC_S_OS_Y2 + 3);
	glRectd(GC_S_OS_X2 + 19, GC_S_OS_Y2 + 4, GC_S_OS_X2 + 23, GC_S_OS_Y2 + 5);
}