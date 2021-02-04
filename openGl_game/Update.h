#pragma once

// System files includes
#include<iostream>
#include<GL/glut.h> 
#include<GL/gl.h> 

// User defined files includes
#include "Global_Variables.h"
#include "State_Engine.h"


// Signature of the function Update()
s_Game_info Update(s_Game_info, unsigned short);

// Sub-functions signatures
void ud_snake();
void check_fruit();
e_Cmd check_game_over();