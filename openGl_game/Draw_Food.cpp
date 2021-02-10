/*
	File: Draw_Food.cpp
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


// Draw Food
void Draw_Food(Food p_Food) {

	// Draw the outline of the food
	glColor3f(0.55, 0.55, 0.65);
	glRectd(p_Food.Get_Coordinates().first + 0.1, p_Food.Get_Coordinates().second + 0.1, \
		p_Food.Get_Coordinates().first + 0.9, p_Food.Get_Coordinates().second + 0.9);

	// Decorate its inner
	glColor3f(0.1, 0.1, 0.1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(p_Food.Get_Coordinates().first + 0.3F, p_Food.Get_Coordinates().second + 0.3F);
	glVertex2f(p_Food.Get_Coordinates().first + 0.7F, p_Food.Get_Coordinates().second + 0.3F);
	glVertex2f(p_Food.Get_Coordinates().first + 0.7F, p_Food.Get_Coordinates().second + 0.7F);
	glVertex2f(p_Food.Get_Coordinates().first + 0.3F, p_Food.Get_Coordinates().second + 0.7F);
	glEnd();
}
