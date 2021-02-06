/*
	File: Draw.cpp
	Author:	H.CHERGUI
	First version: 2.0
	First version date: 03/02/2021
	Current version: 3.1
	Current version date: 06/02/2021
*/


// System files includes
/*NONE*/

// User defined files includes
#include "Draw.h"


// Drawing the content on the screen
void Draw() {
	static bool g_box_pop;

	if (g_Game_info.Get_state() == Game_info::e_State::START_SCREEN) {
		draw_start();		
	}
	else if (g_Game_info.Get_state() == Game_info::e_State::RUNNING) {
		draw_fewd();
		draw_snake();
		g_box_pop = true;
	}
	else if( g_Game_info.Get_state() == Game_info::e_State::PAUSE) {
		draw_snake();
		draw_fewd();
		draw_pause();
	}
	else if (g_Game_info.Get_state() == Game_info::e_State::GAME_OVER) {
		draw_game_over();
		if(g_box_pop){
			
			char t1[250] = "teh score is : ";	// make const
			char t2[250] = "NEW HI-SCORE : ";

			char s[15];
			_itoa_s(g_Game_info.Get_Score(), s, 10);

			if (g_Game_info.Get_New_record()) {
				strcat_s(t2, s);
				strcat_s(t2, " !");
				for (int i = 0; i < 250; i++)t1[i] = t2[i];
			}
			else {
				strcat_s(t1, s);
			}
			if (g_Game_info.Get_code() == Game_info::e_Cmd::COLLISION_CMD) {
				strcat_s(t1, "\n\n\nYou just hit yourself!!! Dont do that again!!");
				strcat_s(t1, "\n\nSnaeke!...                           SNAAAEKE!\n\n                    (continue y/n?)");
			}
			else if (g_Game_info.Get_code() == Game_info::e_Cmd::WALL_HIT_CMD) {
				strcat_s(t1, "\n\n\nDon't run away! stay inside the map!!");
				strcat_s(t1, "\n\nSnaeke!...                           SNAAAEKE!\n\n                    (continue y/n?)");
			}
			else {
				strcat_s(t1, "\n\n\n>>[ERROR_409]::<p_Game_info.code>'s value is [UNKNOWN] !!");
				std::cout << "p_Game_info.code: " << (long long)g_Game_info.Get_code() << std::endl;
			}
			MessageBox(NULL, LPCSTR(t1), LPCSTR("Game Over!"), 0);
		}
		g_box_pop = false;
	}
	drawgrid();
}

void drawgrid() {
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
		unit(0, y);
	}
	for (int x = 1; x < GC_COL; x++) {
		unit(x, 0);  unit(x, GC_ROW - 3);
	}
	for (int y = 0; y < GC_ROW - 2; y++) {
		unit(GC_COL - 1, y);
	}
	glColor3f(0.0, 0.0, 0.0);
	for (int x = 1; x < GC_COL - 1; x++) {
		for (int y = 1; y < GC_ROW - 3; y++) {
			unit(x, y);
		}
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
	
	// Draw snaek
	glColor3f(0.29, 0.29, 0.85);
	glRectd( g_Snake.Get_Coordinates().first + 0.1, g_Snake.Get_Coordinates().second + 0.1, \
		     g_Snake.Get_Coordinates().first + 0.9, g_Snake.Get_Coordinates().second + 0.9 );

	// Draw his tail
	glColor3f(0.29, 0.29, 0.7);
	for (int i = 0; i < g_Snake.Get_Tail_length(); i++) {
		glRectd( g_Snake.Get_Tail(i).first + 0.3, g_Snake.Get_Tail(i).second + 0.3, \
			     g_Snake.Get_Tail(i).first + 0.7, g_Snake.Get_Tail(i).second + 0.7 );
	}
}

void draw_fewd() {
	glColor3f(0.55, 0.55, 0.65);
	glRectd( g_Food.Get_Coordinates().first + 0.1, g_Food.Get_Coordinates().second + 0.1, \
		     g_Food.Get_Coordinates().first + 0.9, g_Food.Get_Coordinates().second + 0.9) ;

	glColor3f(0.1, 0.1, 0.1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(g_Food.Get_Coordinates().first + 0.3F, g_Food.Get_Coordinates().second + 0.3F);
	glVertex2f(g_Food.Get_Coordinates().first + 0.7F, g_Food.Get_Coordinates().second + 0.3F);
	glVertex2f(g_Food.Get_Coordinates().first + 0.7F, g_Food.Get_Coordinates().second + 0.7F);
	glVertex2f(g_Food.Get_Coordinates().first + 0.3F, g_Food.Get_Coordinates().second + 0.7F);
	glEnd();
}
