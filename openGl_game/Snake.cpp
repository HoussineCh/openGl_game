/*
    Class: Snake
    Author:	H.CHERGUI
    First version: 3.0
    First version date: 05/02/2021
	Current version: 3.4
	Current version date: 09/02/2021
*/


// Sys includes
/*NONE*/

// User includes
#include "Snake.h"


// Default constructor
Snake::Snake() {
	Tail.resize(100);
    Speed = 1;
}

// Initialize the snake
void Snake::Init() {
    // Init direction
    Direction = e_Direction::UP;
    
    // Init position in the middle of screen
    Coordinates = std::make_pair(GC_COL / 2,  GC_ROW / 2);

    // Init tail
    Tail_len = 3;
    for (int i = 0; i <= Tail_len; i++) {
        Tail[i] = std::make_pair(GC_COL / 2, GC_ROW / 2 - i - 1);
    }
    Speed = 1;
}

// Increase and decrease the snake's coordinates
void Snake::IncX() {
	Coordinates.first++;
}

void Snake::DecX() {
	Coordinates.first--;
}

void Snake::IncY() {
	Coordinates.second++;
}

void Snake::DecY() {
	Coordinates.second--;
}

// Access the snake's coordinates
std::pair<long long, long long> Snake::Get_Coordinates() {
	return Coordinates;
}

// Increment tail length
void Snake::Grow_Tail() {
    Tail_len++;
}

// Get tail length
long long Snake::Get_Tail_length() {
    return Tail_len;
}

// Access the snake's Direction
void Snake::Set_Direction(e_Direction p_Direction) {
	Direction = p_Direction;
}

Snake::e_Direction Snake::Get_Direction() {
	return Direction;
}

// Access the snake's speed
void Snake::Set_Speed(long long p_Speed) {
    Speed = p_Speed;
}

long long Snake::Get_Speed() {
    return Speed;
}

// Access the snake's tail
void Snake::Set_Tail(std::pair<long long, long long> p_current_pair, long long p_index) {
    Tail[p_index] = p_current_pair;
}

std::pair<long long, long long> Snake::Get_Tail(long long p_index) {
    return Tail[p_index];
}
