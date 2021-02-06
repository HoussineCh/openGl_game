/*
    File: Input.cpp
    Author:	H.CHERGUI
    First version: 1.0
    First version date: 02/02/2021
    current version: 3.1
    current version date: 06/02/2021
*/

// Sys includes
/*NONE*/

// User includes
#include "Input.h"


// Definitions 

void Special_callback(int key, int, int) {
    static std::pair<long long, long long> prevXY = std::make_pair(-1, -1);
    
    if (key == GLUT_KEY_UP) {
        if (g_Snake.Get_Direction() != Snake::e_Direction::DOWN  && g_Snake.Get_Coordinates() != prevXY) {
            g_Snake.Set_Direction(Snake::e_Direction::UP);
        }
        else if (g_Snake.Get_Direction() == Snake::e_Direction::UP) {
            g_Snake.Set_Speed(3);
        }
    }
    else if (key == GLUT_KEY_DOWN) {
        if (g_Snake.Get_Direction() != Snake::e_Direction::UP && g_Snake.Get_Coordinates() != prevXY) {
            g_Snake.Set_Direction(Snake::e_Direction::DOWN);
        }
        else if (g_Snake.Get_Direction() == Snake::e_Direction::DOWN) {
            g_Snake.Set_Speed(3);
        }
    }
    else if (key == GLUT_KEY_RIGHT) {
        if (g_Snake.Get_Direction() != Snake::e_Direction::LEFT && g_Snake.Get_Coordinates() != prevXY) {
            g_Snake.Set_Direction(Snake::e_Direction::RIGHT);
        }
        else if (g_Snake.Get_Direction() == Snake::e_Direction::RIGHT) {
            g_Snake.Set_Speed(3);
        }
    }
    else if (key == GLUT_KEY_LEFT) {
        if (g_Snake.Get_Direction() != Snake::e_Direction::RIGHT && g_Snake.Get_Coordinates() != prevXY) {
            g_Snake.Set_Direction(Snake::e_Direction::LEFT);
        }
        else if (g_Snake.Get_Direction() == Snake::e_Direction::LEFT) {
            g_Snake.Set_Speed(3);
        }
    }
    prevXY = g_Snake.Get_Coordinates();
}

void keyboard_callback(unsigned char key, int, int) {
    g_Game_info.Set_input_key(key);
}