#pragma

// System files includes
#include<GL/glut.h> 
#include<GL/gl.h> 

// User defined files includes
#include "Types.h"
#include "Global_Variables.h"


// Declaration of drawing function
void Draw(s_Data_Cluster);

// Declarations of drawing sub-functions
void Draw_Unit(double, double);
void Draw_Grid();
void Draw_Snake(Snake);
void Draw_Food(Food);

// Declarations of message drawing functions
void Draw_Start();
void Draw_Pause();
void Draw_Game_Over();
