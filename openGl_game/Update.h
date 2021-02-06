#pragma once

// System files includes
#include<iostream>
#include<GL/glut.h> 
#include<GL/gl.h> 

// User defined files includes
#include "Types.h"
#include "Global_Variables.h"
#include "State_Engine.h"


// Signature of the function Update()
s_Data_Cluster Update(s_Data_Cluster);

// Sub-functions signatures
void ud_snake();
void check_fruit();
void check_game_over();