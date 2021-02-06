#pragma once

// Sys includes
#include<vector>

// User includes
#include "Global_Constants.h"
#include "Types.h"


extern Game_info g_Game_info;
extern Snake g_Snake;
extern Food g_Food;


extern int score;
extern int hi_score;

extern e_Direction g_Direction;
extern int xx, yy;
extern int tail_len;
extern std::vector<std::pair<int, int>> tail;
extern short supeedo_wagon_val;

extern int fx, fy;

extern int g_key;

extern s_Game_info gs_Game_info;