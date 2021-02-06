#pragma once

// System files includes
#include<GL/glut.h> 
#include<GL/gl.h> 

// User defined files includes
#include "Types.h"
#include "Global_Variables.h"


// Declarations of drawing functions
void Draw(s_Data_Cluster);

void unit(double, double);
void drawgrid();
void draw_snake();
void draw_fewd();

void draw_start();
void draw_pause();
void draw_game_over();


