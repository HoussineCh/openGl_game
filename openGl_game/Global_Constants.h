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
