#pragma once

// Sys includes
#include<iostream> 

// User includes
#include "freeglut.h"
#include "Global_Variables.h"
#include "Global_Constants.h"
#include "Step.h"

// Macros
#define FPS_LIM 5

// Declaration of OpenGl function
void open_GL(int, char**);

// Declaration of callback functions
void timer_callback(int);
void displayCallBack();
void reshap_callback(int, int);
void Special_callback(int, int, int);
void keyboard_callback(unsigned char, int, int);
