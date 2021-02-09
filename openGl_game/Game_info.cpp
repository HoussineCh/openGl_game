/*
    Class: Game_info
    Author:	H.CHERGUI
    First version: 3.0
    First version date: 05/02/2021
    current version: 3.4
    current version date: 09/02/2021
*/


// Sys includes
/*NONE*/

// User includes
#include "Game_info.h"


// Default constructor
Game_info::Game_info() {
	Hi_Score = GC_HI_SCORE;
}

// Initialize the game's informations
void Game_info::Init_Game_info() {
    Score = 0;
    New_record = false;
    Input_key = 0;
    Special_key = 0;
}

// Initialize the game's score and hi-score
void Game_info::Determine_Score() {
    if (Score < Hi_Score) {
        Score += 10;
    }else{
        Score += 10;
        Hi_Score = Score;
        New_record = true;
    }
}

long long Game_info::Get_Score() {
    return Score;
}

// Verify if a new record is obtained
bool Game_info::Get_New_record() {
    return New_record;
}

// Access the games's state and the internal code
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

// Acccess the input keys 
void Game_info::Set_Input_key(unsigned char p_key) {
    Input_key = p_key;
}

unsigned char Game_info::Get_Input_key() {
    return Input_key;
}

void Game_info::Clear_Input_key() {
    Input_key = 0;
}

// Acccess the special keys 
void Game_info::Set_Special_key(long long p_special_key) {
    Special_key = p_special_key;
}

long long Game_info::Get_Special_key() {
    return Special_key;
}

void Game_info::Clear_Special_key() {
    Special_key = 0;
}
