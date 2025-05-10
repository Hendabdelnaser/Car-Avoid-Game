
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <gl/glut.h>
#include <gl/gl.h>

#include "Reshape.h"
#include "Controls.h"
#include "Variables.h"
#include "Drawing.h"
#include "Display.h"

using namespace std;

void update(int value) {
	crmove -= 0.1f;

	// Check if total meter reaches 4000
	if (totalMeter >= 4000) {
		win('a'); // End the game
		return;
	}

	glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(crspeed, update, 0);
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 500);
	glutInitWindowPosition(100, 100);
	load(1);
	glutCreateWindow("Car Game");
	initRendering();

	//Set handler functions

	glutDisplayFunc(drawScene);
	glutReshapeFunc(handleResize);
	glutTimerFunc(25, update, 0);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(keyboardspecial);
	glutMouseFunc(mouseClick);
	glutFullScreen();
	glutMainLoop();
	return 0;
}