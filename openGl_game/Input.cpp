/*
    File: Input.cpp
    Author:	H.CHERGUI
    First version: 1.0
    First version date: 02/02/2021
    current version: 2.0
    current version date: 03/02/2021
*/

// Sys includes
/*NONE*/

// User includes
#include "Input.h"


// Definitions 
void Special_callback(int key, int, int) {
    static int prevx = -1;
    static int prevy = -1;
    
    if (key == GLUT_KEY_UP) {
        if (g_Direction != e_Direction::DOWN && (prevx != xx || prevy != yy)) {
            g_Direction = e_Direction::UP;
            prevx = xx; prevy = yy;
        }
        else if (g_Direction == e_Direction::UP) {
            supeedo_wagon_val = 3;
        }
    }
    else if (key == GLUT_KEY_DOWN) {
        if (g_Direction != e_Direction::UP && (prevx != xx || prevy != yy)) {
            g_Direction = e_Direction::DOWN;
            prevx = xx; prevy = yy;
        }
        else if (g_Direction == e_Direction::DOWN) {
            supeedo_wagon_val = 3;
        }
    }
    else if (key == GLUT_KEY_RIGHT) {
        if (g_Direction != e_Direction::LEFT && (prevx != xx || prevy != yy)) {
            g_Direction = e_Direction::RIGHT;
            prevx = xx; prevy = yy;
        }
        else if (g_Direction == e_Direction::RIGHT) {
            supeedo_wagon_val = 3;
        }
    }
    else if (key == GLUT_KEY_LEFT) {
        if (g_Direction != e_Direction::RIGHT && (prevx != xx || prevy != yy)) {
            g_Direction = e_Direction::LEFT;
            prevx = xx; prevy = yy;
        }
        else if (g_Direction == e_Direction::LEFT) {
            supeedo_wagon_val = 3;
        }
    }
}

void keyboard_callback(unsigned char key, int, int) {
    g_key = key;
}