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
#include "string"


#include "Variables.h"
#include "Display.h"
#include "Time.h"
using namespace std;

bool GameScore()
{
	if (0 > (crmove - y11) && -1 < (crmove - y11) && carpos == 0)
	{
		score++;
	}

	else if (0 > (crmove - (y11 - 10)) && -1 < (crmove - (y11 - 10)) && carpos == 1)
	{
		score++;
	}

	else if (0 > (crmove - (y11 - 20)) && -1 < (crmove - (y11 - 20)) && carpos == 1)
	{

		score++;
	}

	else if (0 > (crmove - (y11 - 30)) && -1 < (crmove - (y11 - 30)) && carpos == 0)
	{
		score += 1;
	}

	else if (0 > (crmove - (y11 - 35)) && -1 < (crmove - (y11 - 35)) && carpos == 0)
	{
		score ++;
		return true;
	}


	else {
		totalMeter++;
		cout << "Total Meter: " << totalMeter << endl;
		return false;
	}
}

int winner(char a)
{

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 500);
	glutCreateWindow("GAME OVER");
	/*glClearColor(0.0, 0.0, 0.0, 1.0);*/
	glLineWidth(3);
	char c = char(score);
	strcpy_s(quote[1], "Game Over");
	numberOfQuotes = 5;
	glutDisplayFunc(myDisplayFunction);
	glutReshapeFunc(reshape);
	glutMainLoop();

	return 0;
}


int win(char a)
{

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 500);
	glutCreateWindow("YOU WIN");
	/*glClearColor(0.0, 0.0, 0.0, 1.0);*/
	glLineWidth(3);
	char c = char(score);
	strcpy_s(quote[1], "WINNER WINNER CHICKEN DINNER");
	numberOfQuotes = 5;
	glutDisplayFunc(myDisplayFunction);
	glutReshapeFunc(reshape);
	glutMainLoop();

	return 0;
}

void sprint(float x, float y, string st)
{
	int l, i;
	/*glColor3f(0.0, 0.0, 0.0);*/
	glRasterPos2f(x, y); // location to start printing text
	for (i = 0; i < st.length(); i++) // loop until i is greater then l
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]);
	}

}