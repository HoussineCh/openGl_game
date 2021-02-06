/*
    Class: Food
    Author:	H.CHERGUI
    First version: 3.0
    First version date: 05/02/2021
    current version: 3.0
    current version date: 05/02/2021
*/

// Sys includes
/*NONE*/

// User includes
#include "Food.h"

// Generate fuit at random position
void Food::Generate_cordinates() {
    srand(unsigned int(time(NULL)));
    Coordinates.first = rand() % (GC_COL - 6) + 3;
    Coordinates.second = rand() % (GC_ROW - 7) + 2;
}

// Return the corordinates of da fruit
std::pair<long long, long long> Food::Get_Coordinates() {
    return Coordinates;
}
