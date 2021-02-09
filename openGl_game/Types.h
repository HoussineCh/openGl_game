#pragma once

// Sys includes
/*NONE*/

// User includes
#include "Game_info.h"
#include "Snake.h"
#include "Food.h"

// Game data structure
struct s_Data_Cluster {
	Game_info game_info;
	Snake snake;
	Food food;
};
