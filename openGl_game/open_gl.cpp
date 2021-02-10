/*
    File: Open_gl.cpp
    Author:	H.CHERGUI
    First version: 1.0
    First version date: 02/02/2021
	Current version: 3.6
	Current version date: 10/02/2021
*/


// Sys includes
/*NONE*/

// User includes
#include "open_gl.h"


// OpneGl initializations
void open_GL(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(GC_W, GC_H);
    glutCreateWindow(GC_WIN_NAME);
    glutFullScreen();
    glutDisplayFunc(displayCallBack);
    glutReshapeFunc(reshap_callback);
    glutKeyboardFunc(keyboard_callback);
    glutSpecialFunc(Special_callback);
    glutTimerFunc(0, timer_callback, 0);
    glClearColor(0.15, 0.15, 0.3, 1.0);
    glutMainLoop();
}

// Main looped program
void displayCallBack() {
    Step();
}

// Called when reshaping the window
void reshap_callback(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, GC_COL, 0.0, GC_ROW, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

// Delay function
void timer_callback(int) {
    glutPostRedisplay();
    glutTimerFunc(1000 / (FPS_LIM * g_Data.snake.Get_Speed()), timer_callback, 0);
}

// Normal keys input function
void keyboard_callback(unsigned char key, int, int) {
    g_Data.game_info.Set_Input_key(key);
}

// Special keys input function
void Special_callback(int key, int, int) {
    g_Data.game_info.Set_Special_key(key);
}
