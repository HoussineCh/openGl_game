/*
	File: Update_Snake.cpp
	Author: H.CHERGUI
	First version: 3.6
	First version date: 10/02/2021
	Current version: 3.6
	Current version date: 10/02/2021
*/


// Sys includes
/*NONE*/

// User includes
#include "Update.h"


// Update the snake
s_Data_Cluster Update_Snake(s_Data_Cluster p_Data) {

	// Local variables
	s_Data_Cluster l_Data = p_Data;
	std::pair<int, int> l_prev;
	static std::pair<long long, long long> l_prevXY = std::make_pair(-1, -1);

	// Update the tail
	for (int i = 1; i < p_Data.snake.Get_Tail_length(); i++) {
		l_prev = l_Data.snake.Get_Tail(i);
		l_Data.snake.Set_Tail(l_Data.snake.Get_Tail(0), i);
		l_Data.snake.Set_Tail(l_prev, 0);
	}
	l_Data.snake.Set_Tail(l_Data.snake.Get_Coordinates(), 0);

	// Update the direction
	if (p_Data.game_info.Get_Special_key() == GLUT_KEY_UP) {
		if (p_Data.snake.Get_Direction() == Snake::e_Direction::RIGHT || p_Data.snake.Get_Direction() == Snake::e_Direction::LEFT) {
			l_Data.snake.Set_Direction(Snake::e_Direction::UP);
			l_Data.snake.Set_Speed(1);
		}
		else if (p_Data.snake.Get_Direction() == Snake::e_Direction::UP) {
			l_Data.snake.Set_Speed(3);
		}
	}
	else if (p_Data.game_info.Get_Special_key() == GLUT_KEY_DOWN) {
		if (p_Data.snake.Get_Direction() == Snake::e_Direction::RIGHT || p_Data.snake.Get_Direction() == Snake::e_Direction::LEFT) {
			l_Data.snake.Set_Direction(Snake::e_Direction::DOWN);
			l_Data.snake.Set_Speed(1);
		}
		else if (p_Data.snake.Get_Direction() == Snake::e_Direction::DOWN) {
			l_Data.snake.Set_Speed(3);
		}
	}
	else if (p_Data.game_info.Get_Special_key() == GLUT_KEY_RIGHT) {
		if (p_Data.snake.Get_Direction() == Snake::e_Direction::UP || p_Data.snake.Get_Direction() == Snake::e_Direction::DOWN) {
			l_Data.snake.Set_Direction(Snake::e_Direction::RIGHT);
			l_Data.snake.Set_Speed(1);
		}
		else if (p_Data.snake.Get_Direction() == Snake::e_Direction::RIGHT) {
			l_Data.snake.Set_Speed(3);
		}
	}
	else if (p_Data.game_info.Get_Special_key() == GLUT_KEY_LEFT) {
		if (p_Data.snake.Get_Direction() == Snake::e_Direction::UP || p_Data.snake.Get_Direction() == Snake::e_Direction::DOWN) {
			l_Data.snake.Set_Direction(Snake::e_Direction::LEFT);
			l_Data.snake.Set_Speed(1);
		}
		else if (p_Data.snake.Get_Direction() == Snake::e_Direction::LEFT) {
			l_Data.snake.Set_Speed(3);
		}
	}
	else
	{
		l_Data.snake.Set_Speed(1);
	}

	// Move the snake
	if (l_Data.snake.Get_Direction() == Snake::e_Direction::UP)
		l_Data.snake.IncY();
	else if (l_Data.snake.Get_Direction() == Snake::e_Direction::DOWN)
		l_Data.snake.DecY();
	else if (l_Data.snake.Get_Direction() == Snake::e_Direction::RIGHT)
		l_Data.snake.IncX();
	else if (l_Data.snake.Get_Direction() == Snake::e_Direction::LEFT)
		l_Data.snake.DecX();

	return l_Data;
}
