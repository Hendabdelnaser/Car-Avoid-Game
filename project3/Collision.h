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
#include "Settings.h"
bool collision()
{

	if (0 > (crmove - y11) && -1 < (crmove - y11) && carpos == 1) // right collision
	{
		return true;
	}

	else if (0 > (crmove - (y11 - 10)) && -1 < (crmove - (y11 - 10)) && carpos == 0) // left collision
	{
		return true;
	}

	else if (0 > (crmove - (y11 - 20)) && -1 < (crmove - (y11 - 20)) && carpos == 0) // left collision
	{
		return true;
	}

	else if (0 > (crmove - (y11 - 30)) && -1 < (crmove - (y11 - 30)) && carpos == 1) // right collision
	{
		return true;
	}

	else if (0 > (crmove - (y11 - 30)) && -1 < (crmove - (y11 - 30)) && carpos == 0)
	{
		y11 -= 40;
		return false;
	}

	else
	{
		return false;
	}
}