#pragma once
#include "Defines.h"

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
int implicitLineEq(int x1, int y1, int x2, int y2, int tx1, int tx2)
{
	//(Y1 – Y2)x + (X2 – X1)y + X1Y2 – Y1X2
	int ansReturn = (y1 - y2) * tx1 + (x2 - x1) * tx2 + x1 * y2 - y1 * x2;
	return ansReturn;
}

void Bresenham1(float _x1, float _y1, float _x2, float _y2, unsigned int colorToBePassed)
{
	float chX = _x2 - _x1;
	float chY = _y2 - _y1;
	//  CurrY = StartY
	int CurrY = _y1;
	int currX = _x1;
	//	Slope = changeofY / changeofX
	float sloperino = (_y2 - _y1) / (_x2 - _x1);
	int sloperinoY = (_x2 - _x1) / (_y2 - _y1);
	//	Error = 0
	float errorX = 0;
	int errorY = 0;
	//	FOR StartX to EndX
	//if (sloperino > 0)
	//{
		//if (abs(chX) > abs(chY))
		//{
	if (_x1 < _x2) 
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
				else 
				{
					CurrY -= 1;
					errorX += 1;
				}
				if (errorY > .5) {
					currX += 1;
					errorY -= 1;
				}
			}
	}
	else 
	{
		for (int i = _x1; i > _x2; i--) {

			//	PlotPixel(CurrX, CurrY)
			drawPixel(i, CurrY, colorToBePassed);
			//	Error += Slope
			errorX += sloperino;
			errorY += sloperinoY;
			//	IF  Error > 0.5
			if (errorX < .5) {
				//CurrY += 1, Error -= 1;
				CurrY += 1;
				errorX -= 1;
			}
			if (errorY < .5) {
				currX += 1;
				errorY -= 1;
			}
		}
	}
		//}
	//	else 
	//	{
	//		for (int i = _y1; i < _y2; i++) {
	//
	//			//	PlotPixel(CurrX, CurrY)
	//			drawPixel(currX, i, colorToBePassed);
	//			//	Error += Slope
	//			errorX += sloperino;
	//			errorY += sloperinoY;
	//			//	IF  Error > 0.5
	//			if (errorX > .5) {
	//				//CurrY += 1, Error -= 1;
	//				CurrY += 1;
	//				errorX -= 1;
	//			}
	//			if (errorY > .5) {
	//				currX += 1;
	//				errorY -= 1;
	//			}
	//		}
	//	}
	//	
	//
	//}
	//else 
	//{
	//	if (abs(chX) > abs(chY))
	//	{
	//		for (int i = _x1; i > _x2; i--) {
	//		
	//			//	PlotPixel(CurrX, CurrY)
	//			drawPixel(i, CurrY, colorToBePassed);
	//			//	Error += Slope
	//			errorX += sloperino;
	//			//	IF  Error > 0.5
	//			if (errorX < .5) {
	//				CurrY += 1;
	//				errorX += 1;
	//			}
	//			//	CurrY += 1, Error -= 1
	//		}
	//	}
	//	else 
	//	{
	//		for (int i = _y1; i > _y2; i--) {
	//
	//			//	PlotPixel(CurrX, CurrY)
	//			drawPixel(currX, i, colorToBePassed);
	//			//	Error += Slope
	//			errorY += sloperino;
	//			//	IF  Error > 0.5
	//			if (errorY > .5) {
	//				currX += 1;
	//				errorY += 1;
	//			}
	//			//	CurrY += 1, Error -= 1
	//		}
	//	}
	//}
}
	void parametric(int _x1, int _y1, int _x2, int _y2, unsigned int colorToBePassed)
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
		if (largest > 0) 
		{
			for (int i = 0; i < largest; i++) {
				float ratio = (float)i / largest;
				//P(R) = P1 + R(P2 – P1) 
				int currX = _x1 + ratio * (_x2 - _x1);
				int currY = _y1 + ratio * (_y2 - _y1);
				drawPixel(currX, currY, colorToBePassed);
			}
		}
		else 
		{
			for (int i = 0; i > largest; i--) {
				float ratio = (float)i / largest;
				//P(R) = P1 + R(P2 – P1) 
				int currX = _x1 + ratio * (_x2 - _x1);
				int currY = _y1 + ratio * (_y2 - _y1);
				drawPixel(currX, currY, colorToBePassed);
			}
		}

	}
	void MidPoint(int _x1, int _y1, int _x2, int _y2, unsigned int colorToBePassed)
	{
		int CurrY = _y1;
		int CurrX = _x1;
		//	Slope = changeofY / changeofX
		int chX = (_x2 - _x1);
		int chY = (_y2 - _y1);
		//	Error = 0
		float errorX = 0;
		int errorY = 0;
		//	FOR StartX to EndX
		if (abs(chX) > abs(chY))
		{
			if (chX > 0)
			{
				for (int i = _x1; i < _x2; i++)
				{
					//PlotPixel(CurrX, CurrY)
					drawPixel(i, CurrY, colorToBePassed);
					//Midpoint = CurrX + 1, CurrY + 0.5
					std::vector<float> MidPoint;
					MidPoint.push_back(i + 1);
					MidPoint.push_back(CurrY + .05);
					//IF  ImplicitLineEquation(Midpoint) < 0
					if (implicitLineEq(_x1, _y1, _x2, _y2, MidPoint[0], MidPoint[1]) < 0)
					{
						//CurrY += 1
						CurrY += 1;
					}
					else {
						CurrY -= 1;
					}

				}
			}
			else 
			{
				for (int i = _x1; i > _x2; i--)
				{
					//PlotPixel(CurrX, CurrY)
					drawPixel(i, CurrY, colorToBePassed);
					//Midpoint = CurrX + 1, CurrY + 0.5
					std::vector<float> MidPoint;
					MidPoint.push_back(i - 1);
					MidPoint.push_back(CurrY + .05);
					//IF  ImplicitLineEquation(Midpoint) < 0
					if (implicitLineEq(_x1, _y1, _x2, _y2, MidPoint[0], MidPoint[1]) < 0)
					{
						//CurrY += 1
						CurrY += 1;
					}
					else if (implicitLineEq(_x1, _y1, _x2, _y2, MidPoint[0], MidPoint[1]) > 0) {
						CurrY -= 1;
					}

				}
			}
		}
		else 
		{
			if (chY > 0) 
			{

				for (int i = _y1; i < _y2; i++)
				{
					//PlotPixel(CurrX, CurrY)
					drawPixel(CurrX, i, colorToBePassed);
					//Midpoint = CurrX + 1, CurrY + 0.5
					std::vector<float> MidPoint;
					MidPoint.push_back(CurrX + 1);
					MidPoint.push_back(i + .05);
					//IF  ImplicitLineEquation(Midpoint) < 0
					if (implicitLineEq(_x1, _y1, _x2, _y2, MidPoint[0], MidPoint[1]) > 0)
					{
						//CurrY += 1
						CurrX += 1;
					}
					else {
						CurrX -= 1;
					}

				}
			}
			else 
			{
				for (int i = _y1; i > _y2; i--)
				{
					//PlotPixel(CurrX, CurrY)
					drawPixel(CurrX, i, colorToBePassed);
					//Midpoint = CurrX + 1, CurrY + 0.5
					std::vector<float> MidPoint;
					MidPoint.push_back(CurrX + 1);
					MidPoint.push_back(i - .05);
					//IF  ImplicitLineEquation(Midpoint) < 0
					if (implicitLineEq(_x1, _y1, _x2, _y2, MidPoint[0], MidPoint[1]) > 0)
					{
						//CurrY += 1
						CurrX += 1;
					}

				}
			}
		}
	}