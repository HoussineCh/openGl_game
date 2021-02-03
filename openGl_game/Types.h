#pragma once

enum class e_DIrection {
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
	PAUSE2 = 27,
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
