#pragma once

// Sys includes
/*NONE*/

// User includes
#include "Global_Constants.h"


// Game info class definition
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
	long long Special_key;

public:
	// Default constructor
	Game_info();

	// Initializing the game informations
	void Init_Game_info();

	// Score related methods
	void Determine_Score();
	long long Get_Score();
	bool Get_New_record();

	// Access the games's state and the internal code
	void Set_state(e_State);
	void Set_code(e_Cmd);
	e_State Get_state();
	e_Cmd Get_code();

	// Acccess the input keys
	void Set_Special_key(long long);
	long long Get_Special_key();
	void Clear_Special_key();

	// Acccess the special keys 
	void Set_Input_key(unsigned char);
	unsigned char Get_Input_key();
	void Clear_Input_key();
};
