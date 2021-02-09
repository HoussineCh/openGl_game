#pragma once

// Sys includes
#include<iostream> 
#include<GL/glut.h> 
#include<GL/gl.h> 

// User includes
#include "Global_Variables.h"
#include "Global_Constants.h"
#include "Global_Init.h"
#include "Step.h"

// Macros
#define FPS_LIM 5

// Declarations
void open_GL(int, char**);

void timer_callback(int);
void displayCallBack();
void reshap_callback(int, int);
void Special_callback(int, int, int);
void keyboard_callback(unsigned char, int, int);