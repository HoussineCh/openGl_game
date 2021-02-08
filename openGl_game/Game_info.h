#pragma once

// Sys includes
/*None*/

// User includes
#include "Global_Constants.h"

class Game_info
{
public:
	enum class e_Cmd {
		START_CMD = 10,
		RUN_CMD = 'g',
		PAUSE_CMD = 'p',
		ESC_CMD = 27,
		RESTART_CMD = 'r',
		WALL_HIT_CMD = 11,
		COLLISION_CMD = 12,
		NO_CMD = 13
	};

	enum class e_State {
		START_SCREEN,
		RUNNING,
		PAUSE,
		GAME_OVER
	};
private:
	long long Score;
	long long Hi_Score;
	e_State State;
	e_Cmd Code;
	bool New_record;
	unsigned char Input_key;
	int Special_key;

public:
	Game_info();

	void Init_Game_info();
	void Determine_Score();
	long long Get_Score();
	bool Get_New_record();

	void Set_state(e_State);
	void Set_code(e_Cmd);
	e_State Get_state();
	e_Cmd Get_code();

	void Set_Input_key(unsigned char);
	unsigned char Get_Input_key();
	void Clear_Input_key();

	void Set_Special_key(long long);
	long long Get_Special_key();
	void Clear_Special_key();
};
