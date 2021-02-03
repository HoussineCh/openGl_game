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
e_Cmd check_event();