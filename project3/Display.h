#pragma once
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

void RenderToDisplay()
{
	int l, lenghOfQuote, i;

	glTranslatef(0.0, 0.0, 0.0);
	glRotatef(-20, 1.0, 0.0, 0.0);
	glScalef(0.05, 0.05, 0.05);

	for (l = 0; l < numberOfQuotes; l++)
	{
		lenghOfQuote = (int)strlen(quote[l]);
		glPushMatrix();
		glTranslatef(-(lenghOfQuote * 37), (l * 200), 0.0);
		for (i = 0; i < lenghOfQuote; i++)
		{
			glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, quote[l][i]);  //Font
		}
		glPopMatrix();
	}
}

void myDisplayFunction(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0, 30.0, 100.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	RenderToDisplay();
	glutSwapBuffers();
}

