#pragma once


// Sys includes
#include<iostream> 
#include<GL/glut.h> 
#include<GL/gl.h> 

// User includes
#include "Globale_Variables.h"
#include "Globale_Constants.h"
#include "Update.h"

// Macros
#define FPS_LIM 5

// Declarations
void open_GL(int, char**);


void timer_callback(int);
void displayCallBack();
void reshap_callback(int, int);
void keyboard_callback(int, int, int);
