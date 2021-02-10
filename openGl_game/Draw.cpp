/*
	File: Draw.cpp
	Author:	H.CHERGUI
	First version: 2.0
	First version date: 03/02/2021
	Current version: 3.6
	Current version date: 10/02/2021
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
		Draw_Food(p_Data.food);
		Draw_Snake(p_Data.snake);
		g_Pop_Once = true;
	}

	// Pause screen
	else if( p_Data.game_info.Get_state() == Game_info::e_State::PAUSE) {
		Draw_Food(p_Data.food);
		Draw_Snake(p_Data.snake);
		Draw_Pause();
	}

	// Game over screen
	else if (p_Data.game_info.Get_state() == Game_info::e_State::GAME_OVER) {
		Draw_Game_Over();
		
		// Show the pop-up only once
		if(g_Pop_Once){
			
			char t1[GC_MSG_LEN];
			char t2[GC_MSG_LEN];

			for (int i = 0; i < sizeof(GC_NO_NEW_HS_MSG) / sizeof(char); i++) {
				t1[i] = GC_NO_NEW_HS_MSG[i];
				t2[i] = GC_NEW_HS_MSG[i];
			}

			char s[GC_MAX_SCORE_LEN];
			_ltoa_s(p_Data.game_info.Get_Score(), s, 10);
			
			if (p_Data.game_info.Get_New_record()) {
				strcat_s(t2, s);
				strcat_s(t2, " !");
				for (int i = 0; i < GC_MSG_LEN; i++)t1[i] = t2[i];
			}
			else {
				strcat_s(t1, s);
			}
			if (p_Data.game_info.Get_cmd() == Game_info::e_Cmd::COLLISION_CMD) {
				strcat_s(t1, GC_WALL_HIT_MSG);
			}
			else if (p_Data.game_info.Get_cmd() == Game_info::e_Cmd::WALL_HIT_CMD) {
				strcat_s(t1, GC_COLLISION_MSG);
			}
			MessageBox(NULL, LPCSTR(t1), LPCSTR(), 0);
		}
		g_Pop_Once = false;
	}
	Draw_Grid();
	
	// Print the content of the buffer
	glutSwapBuffers();
}
