/*
	File: Draw.cpp
	Author:	H.CHERGUI
	First version: 2.0
	First version date: 03/02/2021
	Current version: 3.4
	Current version date: 09/02/2021
*/


// System files includes
/*NONE*/

// User defined files includes
#include "Draw.h"


// Drawing the content on the screen
void Draw(s_Data_Cluster p_Data) {
	
	// Local variable
	static bool g_Pop_Once;

	// Clear the previous screen content
	glClear(GL_COLOR_BUFFER_BIT);

	// Main menu screen
	if (p_Data.game_info.Get_state() == Game_info::e_State::START_SCREEN) {
		Draw_Start();		
	}

	// Running the game
	else if (p_Data.game_info.Get_state() == Game_info::e_State::RUNNING) {
		Draw_Fewd(p_Data.food);
		Draw_Snake(p_Data.snake);
		g_Pop_Once = true;
	}

	// Pause screen
	else if( p_Data.game_info.Get_state() == Game_info::e_State::PAUSE) {
		Draw_Fewd(p_Data.food);
		Draw_Snake(p_Data.snake);
		Draw_Pause();
	}

	// Game over screen
	else if (p_Data.game_info.Get_state() == Game_info::e_State::GAME_OVER) {
		Draw_Game_Over();
		
		// Show the pop-up only once
		if(g_Pop_Once){
			
			char t1[250] = "teh score is : ";	// make const
			char t2[250] = "NEW HI-SCORE : ";

			char s[15];
			_itoa_s(p_Data.game_info.Get_Score(), s, 10);

			if (p_Data.game_info.Get_New_record()) {
				strcat_s(t2, s);
				strcat_s(t2, " !");
				for (int i = 0; i < 250; i++)t1[i] = t2[i];
			}
			else {
				strcat_s(t1, s);
			}
			if (p_Data.game_info.Get_code() == Game_info::e_Cmd::COLLISION_CMD) {
				strcat_s(t1, "\n\n\nYou just hit yourself!!! Dont do that again!!");
				strcat_s(t1, "\n\nSnaeke!...                           SNAAAEKE!\n\n                    (continue y/n?)");
			}
			else if (p_Data.game_info.Get_code() == Game_info::e_Cmd::WALL_HIT_CMD) {
				strcat_s(t1, "\n\n\nDon't run away! stay inside the map!!");
				strcat_s(t1, "\n\nSnaeke!...                           SNAAAEKE!\n\n                    (continue y/n?)");
			}
			else {
				strcat_s(t1, "\n\n\n>>[ERROR_409]::<p_Game_info.code>'s value is [UNKNOWN] !!");
				std::cout << "p_Game_info.code: " << (long long)p_Data.game_info.Get_code() << std::endl;
			}
			MessageBox(NULL, LPCSTR(t1), LPCSTR("Game Over!"), 0);
		}
		g_Pop_Once = false;
	}
	Draw_Grid();
	
	// Print the content of the buffer
	glutSwapBuffers();
}

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

// Draw the snake
void Draw_Snake(Snake p_Snake) {
	
	// Draw snake's head
	glColor3f(0.29, 0.29, 0.85);
	glRectd(p_Snake.Get_Coordinates().first + 0.1, p_Snake.Get_Coordinates().second + 0.1, \
		     p_Snake.Get_Coordinates().first + 0.9, p_Snake.Get_Coordinates().second + 0.9 );

	// Draw his tail
	glColor3f(0.29, 0.29, 0.7);
	for (int i = 0; i < p_Snake.Get_Tail_length(); i++) {
		glRectd( p_Snake.Get_Tail(i).first + 0.3, p_Snake.Get_Tail(i).second + 0.3, \
			     p_Snake.Get_Tail(i).first + 0.7, p_Snake.Get_Tail(i).second + 0.7 );
	}
}

// Draw Food
void Draw_Fewd(Food p_Food) {

	// Draw the outline of the food
	glColor3f(0.55, 0.55, 0.65);
	glRectd( p_Food.Get_Coordinates().first + 0.1, p_Food.Get_Coordinates().second + 0.1, \
		     p_Food.Get_Coordinates().first + 0.9, p_Food.Get_Coordinates().second + 0.9) ;

	// Decorate its inner
	glColor3f(0.1, 0.1, 0.1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(p_Food.Get_Coordinates().first + 0.3F, p_Food.Get_Coordinates().second + 0.3F);
	glVertex2f(p_Food.Get_Coordinates().first + 0.7F, p_Food.Get_Coordinates().second + 0.3F);
	glVertex2f(p_Food.Get_Coordinates().first + 0.7F, p_Food.Get_Coordinates().second + 0.7F);
	glVertex2f(p_Food.Get_Coordinates().first + 0.3F, p_Food.Get_Coordinates().second + 0.7F);
	glEnd();
}
