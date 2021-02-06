#pragma once

// Sys includes
/*None*/

// User includes
#include "Types.h"
#include "Global_Constants.h"

class Game_info
{
	enum class e_Cmd {
		START = 10,
		RUN = 'g',
		PAUSE = 'p',
		ESC = 27,
		RESTART = 'r',
		WALL_HIT = 11,
		COLLISION = 12,
		NO_CMD = 13
	};

	enum class e_State {
		START_SCREEN,
		RUNNING,
		PAUSE,
		GAME_OVER
	};

	long long Score;
	long long Hi_Score;
	e_State State;
	e_Cmd Code;
	bool New_hi_Score;

public:
	Game_info();
	void Set_new_hi_Score(long long);
	void Set_state(e_State);
	void Set_code(e_Cmd);
	e_State Get_state();
	e_Cmd Get_code();	
};
