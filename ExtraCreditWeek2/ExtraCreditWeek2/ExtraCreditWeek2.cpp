// ExtraCreditWeek2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "RasterSurface.h"
#include "XTime.h"
#include "RasterFunctions.h"

int main()
{
	Vertex a;
	a.Position.x = 250;
	a.Position.y = 100;
	Vertex b;
	b.Position.x = 150;
	b.Position.y = 350;
	Vertex c;
	c.Position.x = 350;
	c.Position.y = 350;

	RS_Initialize(_studentName, RASTER_WIDTH, RASTER_HEIGHT);
	while (RS_Update(SCREEN_ARRAY, NUM_PIXELS))
	{
		clearRaster();
		drawTriangle(a,b,c);
	}
	RS_Shutdown();
}