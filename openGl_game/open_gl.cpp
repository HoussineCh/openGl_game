/*
    File: Open_gl.cpp
    Author:	H.CHERGUI
    First version: 1.0
    First version date: 02/02/2021
    current version: 2.0
    current version date: 02/02/2021
*/

// Sys includes
/*NONE*/

// User includes
#include "open_gl.h"
#include "Init.h"
#include "Input.h"


// OpneGl initializations
void open_GL(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(GC_W, GC_H);
    glutCreateWindow("snake gaem");
    glutDisplayFunc(displayCallBack);
    glutReshapeFunc(reshap_callback);
    glutSpecialFunc(Special_callback);
    glutKeyboardFunc(keyboard_callback);
    glutTimerFunc(0, timer_callback, 0);
    Init();
    glutMainLoop();
}

// Main looped program
void displayCallBack() {
    glClear(GL_COLOR_BUFFER_BIT);
    Step();
    glutSwapBuffers();
}

void reshap_callback(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, GC_COL, 0.0, GC_ROW, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

// Delay function
void timer_callback(int p_time) {
    glutPostRedisplay();
    glutTimerFunc(1000 / (FPS_LIM * supeedo_wagon_val), timer_callback, 0);
    supeedo_wagon_val = 1;
}
