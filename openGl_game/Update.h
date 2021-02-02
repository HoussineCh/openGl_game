#pragma once

// Sys includes
#include<iostream>
#include<vector>
#include<GL/glut.h> 
#include<GL/gl.h> 

// User includes
#include "Globale_Variables.h"
#include "Globale_Constants.h"

//
void Update();

void unit(float, float);
void drawgrid();
void draw_snake();
void check_collision();
void draw_fewd();
void draw_txt();