#pragma once

// System files includes
#include <iostream>
#include<GL/glut.h> 
#include<GL/gl.h> 

// User defined files includes
#include "Global_Variables.h"


// Signature of the function Draw()
void Draw(s_Game_info);

void unit(float, float);
void drawgrid();
void draw_snake();
void draw_fewd();

