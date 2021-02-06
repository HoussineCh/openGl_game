/*
    Class: Game_info
    Author:	H.CHERGUI
    First version: 3.0
    First version date: 05/02/2021
    current version: 3.0
    current version date: 05/02/2021
*/

// Sys includes
/*NONE*/

// User includes
#include "Game_info.h"


Game_info::Game_info() {
	Hi_Score = GC_HI_SCORE;
}

void Game_info::Set_new_hi_Score(long long p_new_record) {
    Hi_Score = p_new_record;
}

void Game_info::Set_state(e_State p_state) {
    State = p_state;
}

void Game_info::Set_code(e_Cmd p_code) {
    Code = p_code;
}

Game_info::e_State Game_info::Get_state() {
    return State;
}

Game_info::e_Cmd Game_info::Get_code() {
    return Code;
}

