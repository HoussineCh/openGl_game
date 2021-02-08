/*
	File: Update.cpp
	Author: H.CHERGUI
	First version: 2.0
	First version date: 03/02/2021
	Current version: 3.3
	Current version date: 08/02/2021
*/

// System files includes
/*NONE*/

// User defined files includes
#include "Update.h"


// Definition of the update function
s_Data_Cluster Update(s_Data_Cluster p_data) {

	// Local variables
	s_Data_Cluster l_Data = p_data;

	// Determining the current state
	l_Data = State_Engine(p_data);

	if (l_Data.game_info.Get_state() == Game_info::e_State::RUNNING) {

		// Check if snaek ate the fruit
		l_Data = check_fruit(l_Data);

		// Updating the snake
		l_Data.snake = ud_snake(l_Data.game_info, l_Data.snake);

		// Check if a game over occured
		l_Data.game_info.Set_code(check_game_over(l_Data.snake));
	}

	// Return Updated data
	return l_Data;
}

// Check if the snaek ate the fruit
s_Data_Cluster check_fruit(s_Data_Cluster p_Data) {

	// Local variable
	s_Data_Cluster l_Data = p_Data;

	if (p_Data.snake.Get_Coordinates() == p_Data.food.Get_Coordinates()) {
		l_Data.game_info.Determine_Score();
		l_Data.snake.Grow_Tail();
		l_Data.food.Generate_cordinates();
	}

	return l_Data;
}

Snake ud_snake(Game_info p_game_info, Snake p_snake) {

	// Local variables
	Snake l_snake = p_snake;
	std::pair<int, int> l_prev;
	static std::pair<long long, long long> l_prevXY = std::make_pair(-1, -1);

	// Update da tael!
	for (int i = 1; i < p_snake.Get_Tail_length(); i++) {
		l_prev = l_snake.Get_Tail(i);
		l_snake.Set_Tail(l_snake.Get_Tail(0), i);
		l_snake.Set_Tail(l_prev, 0);
	}
	l_snake.Set_Tail(l_snake.Get_Coordinates(), 0);
	
	if (p_game_info.Get_Special_key() == GLUT_KEY_UP) {
		if (p_snake.Get_Direction() != Snake::e_Direction::DOWN && p_snake.Get_Coordinates() != l_prevXY) {
			l_snake.Set_Direction(Snake::e_Direction::UP);
		}
		else if (p_snake.Get_Direction() == Snake::e_Direction::UP) {
			l_snake.Set_Speed(3);
		}
	}
	else if (p_game_info.Get_Special_key() == GLUT_KEY_DOWN) {
		if (p_snake.Get_Direction() != Snake::e_Direction::UP && p_snake.Get_Coordinates() != l_prevXY) {
			l_snake.Set_Direction(Snake::e_Direction::DOWN);
		}
		else if (p_snake.Get_Direction() == Snake::e_Direction::DOWN) {
			l_snake.Set_Speed(3);
		}
	}
	else if (p_game_info.Get_Special_key() == GLUT_KEY_RIGHT) {
		if (p_snake.Get_Direction() != Snake::e_Direction::LEFT && p_snake.Get_Coordinates() != l_prevXY) {
			l_snake.Set_Direction(Snake::e_Direction::RIGHT);
		}
		else if (p_snake.Get_Direction() == Snake::e_Direction::RIGHT) {
			l_snake.Set_Speed(3);
		}
	}
	else if (p_game_info.Get_Special_key() == GLUT_KEY_LEFT) {
		if (p_snake.Get_Direction() != Snake::e_Direction::RIGHT && p_snake.Get_Coordinates() != l_prevXY) {
			l_snake.Set_Direction(Snake::e_Direction::LEFT);
		}
		else if (p_snake.Get_Direction() == Snake::e_Direction::LEFT) {
			l_snake.Set_Speed(3);
		}
	}
	l_prevXY = p_snake.Get_Coordinates();
	p_game_info.Clear_Special_key();	/////////////////

	// Move the snake
	if (p_snake.Get_Direction() == Snake::e_Direction::UP)
		l_snake.IncY();
	else if (p_snake.Get_Direction() == Snake::e_Direction::DOWN)
		l_snake.DecY();
	else if (p_snake.Get_Direction() == Snake::e_Direction::RIGHT)
		l_snake.IncX();
	else if (p_snake.Get_Direction() == Snake::e_Direction::LEFT)
		l_snake.DecX();

	return l_snake;
}

// Check for a game over
Game_info::e_Cmd check_game_over(Snake p_snake) {

	// Local variable
	Game_info::e_Cmd l_cmd = Game_info::e_Cmd::RUN_CMD;

	// Check if a collision happened
	for (int i = 0; i < p_snake.Get_Tail_length(); i++) {
		if (p_snake.Get_Coordinates() == p_snake.Get_Tail(i)) {
			l_cmd = Game_info::e_Cmd::COLLISION_CMD;
			break;
		}
	}

	// Check if snaek hit a wall
	if (p_snake.Get_Coordinates().first == 0		  || \
		p_snake.Get_Coordinates().first == GC_COL - 1 || \
		p_snake.Get_Coordinates().second == 0		  || \
		p_snake.Get_Coordinates().second == GC_ROW - 3) 
	{
		l_cmd = Game_info::e_Cmd::WALL_HIT_CMD;
	}

	// Return execution code
	return l_cmd;
}
