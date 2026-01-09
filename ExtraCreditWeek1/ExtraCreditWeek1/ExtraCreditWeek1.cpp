// ExtraCreditWeek1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <vector>
#include "RasterSurface.h"
#include "RasterFunctions.h"


int main()
{
	//STARS
	srand(time(NULL));
	bool starry = true;
	bool line1 = false;
	bool line2 = false;
	bool line3 = false;
	std::vector<int> randomX;
	std::vector<int> randomY;
	for (int i = 0; i < 2000; i++) 
	{
		randomX.push_back(rand() % 500);
		randomY.push_back(rand() % 500);
	}
	//PARAMETRIC RANDOM
	int paraRandX1 = rand() % 500;
	int paraRandY1 = rand() % 500;
	int paraRandX2 = rand() % 500;
	int paraRandY2 = rand() % 500;

	//BRESENHAM RANDOM
	int bresRandX1 = rand() % 500;
	int bresRandY1 = rand() % 500;
	int bresRandX2 = rand() % 500;
	int bresRandY2 = rand() % 500;

	//MIDPOINT RANDOM
	int midRandX1 = rand() % 500;
	int midRandY1 = rand() % 500;
	int midRandX2 = rand() % 500;
	int midRandY2 = rand() % 500;

	RS_Initialize(_studentName, RASTER_WIDTH, RASTER_HEIGHT);
	while (RS_Update(SCREEN_ARRAY, NUM_PIXELS))
	{
		clearRaster();
		//STARS
		if (starry == true) 
		{
			for (int i = 0; i < 2000; i++) 
			{
				drawPixel(randomX[i], randomY[i], 0xffffffff);
			}
		}
		//NORMAL LINES
		Bresenham1(0, 100, 499, 400, 0xffff0000);
		//MidPoint(0, 110, 499, 410, 0xffff00ff);
		MidPoint(0, 110, 499, 410, 0xffff00ff);
		parametric(0, 120, 499, 420, 0xff00ff00);
		
		//RANDOMIZED LINES
		if (GetAsyncKeyState('1') & 0x01) 
		{
			if (line1 == true) 
			{
				paraRandX1 = rand() % 500;
				paraRandY1 = rand() % 500;
				paraRandX2 = rand() % 500;
				paraRandY2 = rand() % 500;
			}
			line1 = true;
			
			starry = false;
		}
		if (line1 == true) 
		{
			parametric(paraRandX1, paraRandY1, paraRandX2, paraRandY2, 0xffffff00);
		}

		if (GetAsyncKeyState('2') & 0x01)
		{
			if (line2 == true)
			{
				 bresRandX1 = rand() % 500;
				 bresRandY1 = rand() % 500;
				 bresRandX2 = rand() % 500;
				 bresRandY2 = rand() % 500;
			}
			line2 = true;
			starry = false;
		}
		if (line2 == true)
		{
			Bresenham1(bresRandX1, bresRandY1, bresRandX2, bresRandY2, 0xff00ffff);
		}

		if (GetAsyncKeyState('3') & 0x01)
		{
			if (line3 == true)
			{
				midRandX1 = rand() % 500;
				midRandY1 = rand() % 500;
				midRandX2 = rand() % 500;
				midRandY2 = rand() % 500;
			}
			line3 = true;
			starry = false;
		}
		if (line3 == true)
		{
			MidPoint(midRandX1, midRandY1, midRandX2, midRandY2, 0xffff00ff);
		}

		if (GetKeyState('4') & 0x8000 && starry == false) 
		{
			starry = true;
			line1 = false;
			line2 = false;
			line3 = false;
		}
	}
	RS_Shutdown();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
