#pragma once
static float xp = -.55;
unsigned char* imgData = NULL;
unsigned int texture;
int width, height, nrChannels;

int static crspeed = 60;
float crmove = 4;

float static y11 = -3.3;
float static zp = 2;
float static tpx = .15;

int static carpos = 0;
int static carspeed = 45;

float view = 10.0;
int static score = 0;
int static totalMeter = 0;
char quote[6][80];
int numberOfQuotes = 0, i;
unsigned char* data1 = NULL;

//float static sky_red = 0;
//float static sky_green = .8;
//float static sky_blue = 1.0;

int roadlight = 50;
float myLightPosition[4] = { 3.0, 6.0, 5.0, 1.0 };

// Declare global variables to store mouse coordinates
int mouseX = 0;
int mouseY = 0;

GLfloat UpwardsScrollVelocity = -1.0;

float rtri = 0;
float _angle = 0.0;
float _cameraAngle = 0.0;
float _ang_tri = 0.0;