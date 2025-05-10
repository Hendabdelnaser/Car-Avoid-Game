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
#include "Lighting.h"
#include "Settings.h"
#include "Collision.h"
#define STB_IMAGE_IMPLEMENTATION
#define glGenerateMipmaps ;
#include <gl/stb_image.h>
#include <gl/GL.h>

using namespace std;
void check(unsigned char*);

void gamercar()
{
	glPushMatrix();
	glTranslatef(xp, -1.0, 3.5);

	glPushMatrix();
	glRotatef(-10, -1.0, 0.0, 0.0);
	glScalef(1.3, 0.8, 2.0);
	glColor3f(0, 0.5, 1);
	glutSolidCube(.3); // car's body
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, tpx, 0.0);
	glRotatef(-10, -1.0, 0.0, 0.0);
	glScalef(1.0, .5, .5);
	glColor3f(0, 0, 0); // car's roof
	glutSolidCube(.2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.21, -0.12, 0.10);
	glRotatef(80, 0.0, 1.2, 0.0);
	glScalef(.07, .14, .07);
	glColor3f(1, 0, 0);
	glutWireTorus(.2, .4, 20, 15); // lower right wheel
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.21, 0.0, -0.2);
	glRotatef(80, 0.0, 1.2, 0.0);
	glScalef(.07, .14, .07);
	glColor3f(1, 0, 0);
	glutWireTorus(.2, .4, 20, 15); // upper right wheel
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.21, -0.12, 0.10);
	glRotatef(80, 0.0, 1.2, 0.0);
	glScalef(.07, .14, .07);
	glColor3f(1, 0, 0);
	glutWireTorus(.2, .4, 20, 15); // lower left wheel
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.21, 0.0, -0.2);
	glRotatef(80, 0.0, 1.2, 0.0);
	glScalef(.07, .14, .07);
	glColor3f(1, 0, 0);
	glutWireTorus(.2, .4, 20, 15); // upper left wheel
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-0.10, -0.10, 0.30); // left backlight
	glRotatef(80, 0.0, 1.2, 0.0);
	glScalef(.07, .03, .07);
	glColor3f(1, .5, 0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.10, -0.10, 0.30); // right backlight
	glRotatef(80, 0.0, 1.2, 0.0);
	glScalef(.07, .03, .07);
	glColor3f(1, .5, 0);
	glutSolidCube(1);
	glPopMatrix();

	glPopMatrix();

}

void load(int imgnum) {
	if (imgnum == 1) {

		data1 = stbi_load("sky.jpg", &width, &height, &nrChannels, 0);
		check(data1);
	}
	else if (imgnum == 2) {

		data1 = stbi_load("roedside2.jpg", &width, &height, &nrChannels, 0);
		check(data1);
	}
}

void check(unsigned char* data) {
	if (data) {
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); // تغيير من LINEAR إلى NEAREST
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	}
	else {
		std::cerr << "Failed to load texture!" << std::endl;
	}
	stbi_image_free(data);
}

void sky()
{
	load(1);
	glDisable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);

	glPushMatrix();
	glRotatef(_cameraAngle, 0.0, 1.0, 0.0); // Rotate the sky to match the camera angle

	glBegin(GL_QUADS);
	glBindTexture(GL_TEXTURE_2D, texture);

	glColor3ub(255, 255, 255); // Set color to white for the texture
	glTexCoord2f(0.0, 2.0); glVertex3f(-12.0, 2.0, -8.0); // Bottom left (wider), raised
	glTexCoord2f(2.0, 2.0); glVertex3f(12.0, 2.0, -8.0); // Bottom right (wider), raised
	glTexCoord2f(2.0, 0.0); glVertex3f(10.0, 4.0, 8.0);  // Top right, raised
	glTexCoord2f(0.0, 0.0); glVertex3f(-10.0, 4.0, 8.0); // Top left, raised

	glEnd();

	glPopMatrix();
	glEnable(GL_LIGHTING);
}
void road() {
	for (float z = -10; z < 400; z += 1)
	{
		glPushMatrix();
		glColor3f(1, 1, 1);
		glBegin(GL_QUADS);

		glVertex3f(-.03, z, 0);
		glVertex3f(.03, z, 0);
		glVertex3f(.03, z + .5, 0);
		glVertex3f(-.03, z + .5, 0);
		glEnd();
		glPopMatrix();

	}

	glPushMatrix();

	glColor3ub(0, 0, 0);

	glTranslatef(0.0, 0.0, -.50);
	glBegin(GL_QUADS);
	glVertex3f(-1.3, -10, 0);
	glVertex3f(1.3, -10, 0);
	glVertex3f(1.3, 400, 0);
	glVertex3f(-1.3, 400, 0);
	glEnd();

	glPopMatrix();

}

void roadside()
{
	// light pool
	for (float z = -38; z < 400; z += 4)
	{
		glPushMatrix();
		glColor3ub(200, 200, 200);
		glTranslatef(-1.20, z, .40);
		glScalef(.2, .2, 3);
		glutSolidCube(.4); // horizontal shape
		glPopMatrix();

		glPushMatrix();
		glColor3ub(200, 200, 200);
		glTranslatef(-.84, z, 1.0);
		glScalef(2, .2, .2);
		glutSolidCube(.4); // vertical shape
		glPopMatrix();

		glPushMatrix();
		glColor3ub(255, 255, 255);
		glTranslatef(-.44, z, 0.70);
		glutSolidCone(.2, .3, 15, 20); // light cone
		glPopMatrix();
	}

	// ✅ تحميل صورة الجوانب
	load(2);
	glEnable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING); 

	// ✅ الجانب الأيسر
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1); 
	glTexCoord2f(0.0, 0.0); glVertex3f(-100.0, -10, 0);
	glTexCoord2f(1.0, 0.0); glVertex3f(-1.0, -10, 0);    
	glTexCoord2f(1.0, 1.0); glVertex3f(-1.0, 400, 0);   
	glTexCoord2f(0.0, 1.0); glVertex3f(-100.0, 400, 0);  
	glEnd();

	// ✅ الجانب الأيمن
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1); 
	glTexCoord2f(0.0, 0.0); glVertex3f(1.0, -10, 0);    
	glTexCoord2f(1.0, 0.0); glVertex3f(100.0, -10, 0);  
	glTexCoord2f(1.0, 1.0); glVertex3f(100.0, 400, 0);   
	glTexCoord2f(0.0, 1.0); glVertex3f(1.0, 400, 0);     
	glEnd();

	glDisable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING); 
}


void objectcube()
{
	// draw cubes with pattern -> R L L R
	for (float zp = -20; zp < 400; zp += 40)
	{
		glPushMatrix();
		glColor3f(0, 0.5, 0);
		glTranslatef(-.50, zp, -.1);
		glutSolidCube(.4);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0, 0.5, 0);
		glTranslatef(.50, zp + 10, -.1);
		glutSolidCube(.4);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0, 0.5, 0);
		glTranslatef(.50, zp + 20, -.1);
		glutSolidCube(.4);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0, 0.5, 0);
		glTranslatef(-.50, zp + 30, -.1);
		glutSolidCube(.4);
		glPopMatrix();

	}
}



void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(-_cameraAngle, 0.0, 1.0, 0.0);
	glTranslatef(0.0, 0.0, -7.0);

	glColor3f(0.0, 0.0, 0.3);
	// Render the sky first
	sky();
	
	gamercar(); // draw the car

	setupLighting();

	glPushMatrix(); //Save the current state of transformations
	glTranslatef(0.0, 0.0, 0.0); //Move to the center of the triangle
	glRotatef(80, -1.0, 0.0, 0.0);

	glPushMatrix();
	glTranslatef(0.0, crmove, 0.0);

	/*glClearColor(0.0, 0.0, 0.0, 1.0);*/

	road();
	
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0, crmove, 0.0);


	roadside();

	objectcube();

	GameScore();

	glPopMatrix();

	glPushMatrix();
	/*glColor3ub(0, 0, 0);*/
	glTranslatef(5.52, 0.0, 2.0);

	ostringstream cnvrt;
	cnvrt << score; // Total Score
	sprint(-4, -2.3, "Score: " + cnvrt.str());
	glPopMatrix();

	glPushMatrix();
	/*glColor3ub(0, 0, 0);*/
	glTranslatef(5.5, 0.0, 1.8);

	ostringstream cnvrt2;
	cnvrt2 << totalMeter; // Total distance traveled
	sprint(-4, -2.4, "Distance Travel: " + cnvrt2.str());
	glPopMatrix();

	glPushMatrix();
	/*glColor3ub(0, 0, 0);*/
	glTranslatef(5.5, 0.0, 1.6);
	ostringstream cnvrt3;
	cnvrt3 << carspeed; // Car Speed
	sprint(-4, -2.4, "Speed: " + cnvrt3.str());
	glPopMatrix();

	glPopMatrix();
	/*glClearColor(sky_red, sky_green, sky_blue, 1.0);*/

	if (collision())
	{
		winner('a');
	}

	glutSwapBuffers();
}
