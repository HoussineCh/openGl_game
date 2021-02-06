#pragma once

// Sys includes
#include <vector>

// User includes
#include "Global_Constants.h"

class Snake
{
public:
	enum class e_Direction {
		UP,
		DOWN,
		RIGHT,
		LEFT
	};

private:
	e_Direction Direction;
	std::pair<long long, long long> Coordinates;
	std::vector<std::pair<long long, long long>> Tail;
	long long Tail_len;
	long long Speed;

public:
	Snake();

	void Init();

	// Increment and decrement methods for snake's coordinates
	void IncX();
	void DecX();
	void IncY();
	void DecY();

	// Get snake's coordinates
	std::pair<long long, long long> Get_Coordinates();

	// Increment tail length
	void Grow_Tail();

	// Get tail length
	long long Get_Tail_length();

	// Access the direction of the snake
	void Set_Direction(e_Direction);
	e_Direction Get_Direction();

	// Access the speed of the snake
	void Set_Speed(long long);
	long long Get_Speed();

	// Access the tail coordinates
	void Set_Tail(std::pair<long long, long long>, long long);
	std::pair<long long, long long> Get_Tail(long long);
};
