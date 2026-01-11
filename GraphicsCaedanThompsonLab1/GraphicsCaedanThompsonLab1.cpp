#include <iostream>
#include "tiles_12.h"
#include "XTime.h"
#include "teleporter_01.h"
#include "RasterSurface.h"
#include <vector>
#define RASTER_WIDTH 500
#define RASTER_HEIGHT 500
#define NUM_PIXELS (RASTER_WIDTH * RASTER_HEIGHT)
//borrowed from blockimagetransfer
#define C2C(c) (((c&65280u)<<0x8u)|((c&4278190080u)>>0x18u)|((c&255u)<<0x18u)|((c&16711680u)>>0x08u))   
unsigned SCREEN_ARRAY[NUM_PIXELS];
const char* _studentName = "CaedanThompson"; 


void drawPixel(int _x, int _y, unsigned int color) 
{
	if (_x <= RASTER_WIDTH && _y <= RASTER_WIDTH) 
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
void blit(int sourceRectX, int sourceRectY, int sourceRectHeight, int sourceRectWidth, const unsigned int* _textureArray, int _rasterX, int _rasterY, int textureWidth)
{
	for (int y = 0; y < sourceRectHeight;y++) 
	{
		for (int x = 0; x < sourceRectWidth;x++)
		{
			int index = (sourceRectY+y) *  textureWidth + (sourceRectX+x);
			unsigned int color = _textureArray[index];
			drawPixel(x+_rasterX, y+_rasterY, C2C(color));
		}
	}
}
int main()
{
	RS_Initialize(_studentName, RASTER_WIDTH, RASTER_HEIGHT);
	std::vector<int> animX;
	std::vector<int> animY;
	int vectorIncrimentor = 0;
	XTime XTimely;
	XTimely.Restart();
	float elapsed = 0.0f;
	float threshold = 1 / 30;
	int CurrentX =6;
	int startingX = 6;
	int CurrentY= 28;
	int CellWidth =90;
	int CellHeight =99;

	while (RS_Update(SCREEN_ARRAY, NUM_PIXELS))
	{
		clearRaster();
		XTimely.Signal();
		XTimely.Throttle(10);
		elapsed = XTimely.Delta();
		 //draw damn it
		blit(288, 129, 32, 32, tiles_12_pixels, 0, 0, 400);
		for (int x = 0; x < 16; x++) 
		{
			for (int y = 0; y < 16; y++) 
			{
				blit(288, 129, 32, 32, tiles_12_pixels, 32 *(x), 32 *(y), 400);
			}
		}
		blit(272,112,63,63, tiles_12_pixels, 250, 250, 400);
		blit(16, 16, 79, 95, tiles_12_pixels, 100, 100, 400);
		blit(128, 32, 66, 63, tiles_12_pixels, 200, 100, 400);
		blit(208, 32, 66, 95, tiles_12_pixels, 270, 100, 400);
		blit(272, 112, 63, 63, tiles_12_pixels, 7, 250, 400);
		blit(272, 112, 63, 63, tiles_12_pixels, 250, 50, 400);
		for (int i = 0; i < 36; i++) 
		{
			CurrentX += CellWidth;
			if (CurrentX >= RASTER_WIDTH)
			{
				CurrentX = 6;
				CurrentY += CellHeight;
				// perform additional check here to see if CurrentY has gone off the bottom of the page
				if (CurrentY <= RASTER_HEIGHT) {
					CurrentY = 28;
				}
			}
			animX.push_back(CurrentX);
			animY.push_back(CurrentY);
		}
		if (elapsed >= threshold)
		{
			vectorIncrimentor += 1;
			if (vectorIncrimentor >= 36) {
				vectorIncrimentor = 0;
			}
			elapsed = 0;
		}
		blit(animX[vectorIncrimentor], animX[vectorIncrimentor], 99, 90, teleporter_01_pixels, 300, 300, 1024);
		//blit(535, 414, 99, 90, teleporter_01_pixels, 300, 300, 1024);
		//create a vector of ints with the values of the 1st, 2nd, 3rd, and 4th paramater so that when signal is called it will incriment the vector and change the
		//image creating an animation
	}
	 RS_Shutdown();
}
