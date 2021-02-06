#pragma once

// Sys includes
#include <iostream>

// User includes
#include "Global_Constants.h"

class Food
{
	std::pair<long long, long long> Coordinates;

public:
	void Generate_cordinates();
	std::pair<long long, long long> Get_Coordinates();
};

