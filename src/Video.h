#pragma once

#include <stdio.h>
#include "globals.h"
#include "Rect.h"

class Video {
public:
	static Rect rect;

	Video();
	~Video();
	void open();
	void close();
	void writeFrame();
	void setPixelDimensions(int pixelWidth, int pixelHeight);
	void setPixel(int x, int y, byte r, byte g, byte b);
	void setRandomPixels(double prob = 1, Rect region = Rect());
	void clearFrame();
	void clamp(int * x, int * y);

	byte * frame;

private:
	FILE * file;
	int pixelWidth;
	int pixelHeight;
};

