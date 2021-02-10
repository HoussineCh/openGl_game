#pragma once

// Sys includes
#include <iostream>

// User includes
#include "Global_Constants.h"


// Food class definition
class Food
{
	std::pair<long long, long long> Coordinates;

public:

	// Generate a fuit at a random position
	void Generate_cordinates();

	// Return the corordinates of the fruit
	std::pair<long long, long long> Get_Coordinates();
};
