#pragma once

// Sys includes
/*None*/

// User includes
#include "Game_info.h"
#include "Snake.h"
#include "Food.h"

enum class e_Direction {
	UP,
	DOWN ,
	RIGHT,
	LEFT 
};

// Commands
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

// Defining states enumeration class
enum class e_State {
	START_SCREEN,
	RUNNING,
	PAUSE,
	GAME_OVER
};

// Game status
struct s_Game_info {
	e_State state;
	e_Cmd code;
};
