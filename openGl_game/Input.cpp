/*
    File: Input.cpp
    Author:	H.CHERGUI
    First version: 1.0
    First version date: 02/02/2021
    current version: 1.0
    current version date: 02/02/2021
*/

// Sys includes
/*NONE*/

// User includes
#include "Input.h"

// Definitions 
void keyboard_callback(int key, int, int) {
    static int prevx = -1;
    static int prevy = -1;
    if (key == GLUT_KEY_UP) {
        if (sDirection != DOWN && (prevx != xx || prevy != yy)) {
            sDirection = UP;
            prevx = xx; prevy = yy;
        }
        else if (sDirection == UP) {
            supeedo_wagon_val = 3;
        }
    }
    else if (key == GLUT_KEY_DOWN) {
        if (sDirection != UP && (prevx != xx || prevy != yy)) {
            sDirection = DOWN;
            prevx = xx; prevy = yy;
        }
        else if (sDirection == DOWN) {
            supeedo_wagon_val = 3;
        }
    }
    else if (key == GLUT_KEY_RIGHT) {
        if (sDirection != LEFT && (prevx != xx || prevy != yy)) {
            sDirection = RIGHT;
            prevx = xx; prevy = yy;
        }
        else if (sDirection == RIGHT) {
            supeedo_wagon_val = 3;
        }
    }
    else if (key == GLUT_KEY_LEFT) {
        if (sDirection != RIGHT && (prevx != xx || prevy != yy)) {
            sDirection = LEFT;
            prevx = xx; prevy = yy;
        }
        else if (sDirection == LEFT) {
            supeedo_wagon_val = 3;
        }
    }
}