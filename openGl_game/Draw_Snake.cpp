/*
	File: Draw_Snake.cpp
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


// Draw the snake
void Draw_Snake(Snake p_Snake) {

	// Draw snake's head
	glColor3f(0.29, 0.29, 0.85);
	glRectd(p_Snake.Get_Coordinates().first + 0.1, p_Snake.Get_Coordinates().second + 0.1, \
		p_Snake.Get_Coordinates().first + 0.9, p_Snake.Get_Coordinates().second + 0.9);

	// Draw his tail
	glColor3f(0.29, 0.29, 0.7);
	for (int i = 0; i < p_Snake.Get_Tail_length(); i++) {
		glRectd(p_Snake.Get_Tail(i).first + 0.3, p_Snake.Get_Tail(i).second + 0.3, \
			p_Snake.Get_Tail(i).first + 0.7, p_Snake.Get_Tail(i).second + 0.7);
	}
}
