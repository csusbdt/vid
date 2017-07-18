#pragma once

#include <stdio.h>
#include "globals.h"

class Frame {
public:
	Frame();
	~Frame();
	void setPixel(int x, int y, byte r, byte g, byte b);
	void write(FILE * outputStream);
	void addRandomPixels(double prob, int pixelWidth = 4, int pixelHeight = 4);
	void clear();
	void clamp(int * x, int * y);

	byte * data;
};

