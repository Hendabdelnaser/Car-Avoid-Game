#pragma once
#define STB_IMAGE_IMPLEMENTATION
#define glGenerateMipmaps ;
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <gl/glut.h>
#include <gl/gl.h>
#include "Variables.h"

// Function to handle mouse click events
void mouseClick(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) { 
		// Left mouse click, decrease speed
		if (carspeed < 100) {
			crspeed -= 5;
			carspeed += 5;
		}
	}
	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) { 
		// Right mouse click, increase speed
		if (carspeed > 40) {
			crspeed += 5;
			carspeed -= 5;
		}
	}

	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
	if (key == 27)
	{
		exit(1);
	}
}

void keyboardspecial(int key, int x, int y)
{
	switch (key) {

	case GLUT_KEY_RIGHT:
		xp = .55;
		carpos = 1;
		break;

	case GLUT_KEY_LEFT:
		xp = -.55;
		carpos = 0;
		break;

	case GLUT_KEY_UP:
		if (crspeed > 5) {
			crspeed -= 5;
			carspeed += 5;
		}

		else
			crspeed = crspeed;
		break;

	case GLUT_KEY_DOWN:
		if (crspeed < 60) {
			crspeed += 5;
			carspeed -= 5;
		}

		else
			crspeed = crspeed;
		break;

	default:
		break;

	}
}
