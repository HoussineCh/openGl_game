#pragma once

// System files includes
#include<iostream>

// User defined files includes
/*NONE*/


// Resolution of window
const long long GC_H = 720;
const long long GC_W = 1280;

// In-game grid resolution
const long long GC_ROW = GC_H/20;
const long long GC_COL = GC_W/20;

// Const messages
extern const char* WIN_NAME;

// Initial hi-score
const long long GC_HI_SCORE = 100;

// Offset constants for pause message
const long long GC_P_OS_X = (GC_COL / 2) - 10;
const long long GC_P_OS_Y = GC_ROW / 2;

// Offset constants for game over message
const long long GC_GO_OS_X = (GC_COL / 2) - 12;
const long long GC_GO_OS_Y1 = GC_ROW / 2 + 1;
const long long GC_GO_OS_Y2 = GC_ROW / 2 - 5;

// Offset constants for start page message
const long long GC_S_OS_X1 = (GC_COL / 2) - 27;
const long long GC_S_OS_X2 = (GC_COL / 2) - 12;
const long long GC_S_OS_Y1 = GC_ROW / 2 + 2;
const long long GC_S_OS_Y2 = GC_ROW / 2 - 6;

// Message box constants
const char MSG_NO_NEW_HS[16] = "teh score is : ";
const char MSG_NEW_HS[19]	 = "NEW HI-SCORE : ";
const char MSG_WALL_HIT[134]	 = "\n\n\nYou just hit yourself!!! Dont do that again!!\n\nSnaeke!...                           SNAAAEKE!\n\n                    (continue y/n?)";
const char MSG_COLLISION[126]	 = "\n\n\nDon't run away! stay inside the map!!\n\nSnaeke!...                           SNAAAEKE!\n\n                    (continue y/n?)";
const char MSG_GAME_OVER[11]	 = "Game Over!";

// Strings' max length
const long long MAX_SCORE_LEN = 11;
const long long MSG_LEN = 159;
