#pragma once
#include "myMath.h"

void drawPixel(int _x, int _y, unsigned int color)
{
	if (_x <= RASTER_WIDTH && _y <= RASTER_WIDTH && _x >= 0 && _y >= 0)
	{
		int index = _y * RASTER_WIDTH + _x;
		SCREEN_ARRAY[index] = color;
	}

}

void clearRaster()
{
	for (int x = 0; x < 500; x++) {
		for (int y = 0; y < 500; y++) {
			drawPixel(x, y, 0x00000000);
		}
	}

}

void drawTriangle(Vertex v1, Vertex v2, Vertex v3)
{
	//better brute Triangle
	unsigned int colorA = 0xffff0000;
	unsigned int colorB = 0xff00ff00;
	unsigned int colorC = 0xff0000ff;
	Vertex a = v1;
	Vertex b = v2;
	Vertex c = v3;

	//StartX = MIN ( X1, X2, X3 )
	float startX = min(min(a.Position.x, b.Position.x), c.Position.x);
	//StartY = MIN(Y1, Y2, Y3
	float startY = min(min(a.Position.y, b.Position.y), c.Position.y);
	//	EndX = MAX(X1, X2, X3)
	float endX = max(max(a.Position.x, b.Position.x), c.Position.x);
	//	EndY = MAX(Y1, Y2, Y3)
	float endY = max(max(a.Position.y, b.Position.y), c.Position.y);
	//	FOR StartY to EndY
	for (int i = startY; i < endY; i++)
	{
		//	FOR StartX to EndX
		for (int j = startX; j < endX; j++) {
			Vertex temp;
			temp.Position.x = j;
			temp.Position.y = i;
			//	bya = FindBarycentric(start, end, testpoint)
			Vertex bya = FindBarycentric(a, b, c, temp);
			//	IF 	b >= 0 && b <= 1 &&
			//	y >= 0 && y <= 1 &&
			//	a >= 0 && a <= 1
			if (bya.Position.x >= 0 && bya.Position.x <= 1 && bya.Position.y >= 0 && bya.Position.y <= 1 && bya.Position.z >= 0 && bya.Position.z <= 1)
			{
				//	THEN
				//	PlotPixel(CurrX, CurrY)
				if (bya.Position.x > bya.Position.y && bya.Position.x > bya.Position.z) 
				{
					drawPixel(j, i, colorA);
				}
				if (bya.Position.y > bya.Position.x && bya.Position.y > bya.Position.z)
				{
					drawPixel(j, i, colorB);
				}
				if (bya.Position.z > bya.Position.y && bya.Position.z > bya.Position.x)
				{
					drawPixel(j, i, colorC);
				}

			}
		}
	}

}