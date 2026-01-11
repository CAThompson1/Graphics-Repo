// GraphicsCaedanThompsonLab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "RasterSurface.h"
#define RASTER_WIDTH 500
#define RASTER_HEIGHT 500
#define NUM_PIXELS (RASTER_WIDTH * RASTER_HEIGHT)

unsigned SCREEN_ARRAY[NUM_PIXELS];
const char* _studentName = "CaedanThompson";

void drawPixel(int _x, int _y, unsigned int color)
{
	if (_x <= RASTER_WIDTH && _y <= RASTER_WIDTH && _x >= 0 && _y >= 0)
	{
		int index = _y * RASTER_WIDTH + _x;
		SCREEN_ARRAY[index] = color;
	}

}
void upToDown(int _x, int _y1, int _y2, unsigned int colorToBePassed)
{
	
	for (int i = _y1; i < _y2; i++) 
	{
		drawPixel(_x, i, colorToBePassed);
	}
}
void leftToRight(int _y, int _x1, int _x2, unsigned int colorToBePassed)
{

	for (int i = _x1; i < _x2; i++)
	{
		drawPixel(i, _y, colorToBePassed);
	}
}
//responable for lines that go top left to bottom right or bottom right ot top left
void SlopedLineCalculator1(int _x1, int _y1, int _x2, int _y2, unsigned int colorToBePassed) 
{
	//  CurrY = StartY
	int CurrY = _y1;
	int currX = _x1;
	//	Slope = changeofY / changeofX
	int sloperino = (_y2 - _y1) / (_x2 - _x1);
	int sloperinoY = (_x2 - _x1) / (_y2 - _y1);
	//	Error = 0
	int errorX = 0;
	int errorY = 0;
	//	FOR StartX to EndX
	if (sloperino > 0) 
	{

		for (int i = _x1; i < _x2; i++) {

			//	PlotPixel(CurrX, CurrY)
			drawPixel(i, CurrY, colorToBePassed);
			//	Error += Slope
			errorX += sloperino;
			errorY += sloperinoY;
			//	IF  Error > 0.5
			if (errorX > .5) {
			//CurrY += 1, Error -= 1;
				CurrY += 1;
				errorX -= 1;
			}
			if (errorY > .5) {
				currX += 1;
				errorY -= 1;
			}
		}
		
	}
	else if(sloperino <= 0) 
	{
		for (int i = _y1; i < _y2; i++) {
	
			//	PlotPixel(CurrX, CurrY)
			drawPixel(currX, i, colorToBePassed);
			//	Error += Slope
			errorY += sloperinoY;
			//	IF  Error > 0.5
			if (errorY > .5) {
				currX += 1;
				errorY -= 1;
			}
			//	CurrY += 1, Error -= 1
		}
	}

}
void SlopedLineCalculator2(int _x1, int _y1, int _x2, int _y2, unsigned int colorToBePassed)
{
	//  CurrY = StartY
	int CurrY = _y1;
	//	Slope = changeofY / changeofX
	int sloperino = (_y2 - _y1) / (_x2 - _x1);
	//	Error = 0
	int error = 0;
	//	FOR StartX to EndX
	for (int i = _x1; i > _x2; i--) {

		//	PlotPixel(CurrX, CurrY)
		drawPixel(i, CurrY, colorToBePassed);
		//	Error += Slope
		error += sloperino;
		//	IF  Error > 0.5
		if (error < .5) {
			CurrY += 1;
			error += 1;
		}
		//	CurrY += 1, Error -= 1
	}

}
void SlopedLineCalculatorPara1(int _x1, int _y1, int _x2, int _y2, unsigned int colorToBePassed)
{
	float chX = _x2 - _x1;
	float chY = _y2 - _y1;
	float largest = 0;
	if (abs(chX) > abs(chY)) 
	{
		largest = chX;
	}
	else 
	{
		largest = chY;
	}
	for (int i = 0; i < largest; i++) {
		float ratio = (float)i / largest;
		//P(R) = P1 + R(P2 – P1) 
		int currX = _x1 + ratio * (_x2 - _x1);
		int currY = _y1 + ratio * (_y2 - _y1);
		drawPixel(currX, currY, colorToBePassed);
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
int main()
{
	RS_Initialize(_studentName, RASTER_WIDTH, RASTER_HEIGHT);
	while (RS_Update(SCREEN_ARRAY, NUM_PIXELS))
	{
		clearRaster();
		//SlopedLineCalculator1(10, 10, 490, 490, 0xffff0000);
		leftToRight(50, 150, 300, 0xff00ffff);
		SlopedLineCalculator1(300, 50, 400, 250, 0xffff0000);
		SlopedLineCalculator2(150, 50, 50, 250, 0xffffff00);
		upToDown(50, 150, 250, 0xff00ff00);
		upToDown(400, 150, 250, 0xff00ff00);
		SlopedLineCalculator1(50, 250, 150, 490, 0xffff0000);
		SlopedLineCalculator2(400, 250, 300, 490, 0xffffff00);
		leftToRight(350, 150, 300, 0xff00ffff);
		SlopedLineCalculatorPara1(50, 150, 400, 250, 0xffff0000);
		SlopedLineCalculatorPara1(50, 250, 400, 150, 0xffffff00);
		SlopedLineCalculatorPara1(150, 50, 300, 350, 0xffff0000);
		SlopedLineCalculatorPara1(300, 50, 150, 350, 0xffffff00);

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
