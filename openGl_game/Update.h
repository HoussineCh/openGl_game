#pragma once

// System files includes
#include<iostream>
//#include<GL/glut.h> 
//#include<GL/gl.h> 

// User defined files includes
#include "Types.h"
#include "Global_Variables.h"
#include "State_Engine.h"


// Declaration of the update function 
s_Data_Cluster Update(s_Data_Cluster);

// Sub-functions Declarations
s_Data_Cluster check_fruit(s_Data_Cluster);
s_Data_Cluster ud_snake(s_Data_Cluster);
Game_info::e_Cmd check_game_over(Snake);