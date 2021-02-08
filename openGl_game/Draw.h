#pragma once

// System files includes
#include<GL/glut.h> 
#include<GL/gl.h> 

// User defined files includes
#include "Types.h"
#include "Global_Variables.h"


// Declarations of drawing functions
void Draw(s_Data_Cluster);

void Draw_Unit(double, double);
void Draw_Grid();
void Draw_Snake(Snake);
void Draw_Fewd(Food);

void Draw_Start();
void Draw_Pause();
void Draw_Game_Over();


