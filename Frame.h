#pragma once

#include <stdio.h>
#include "globals.h"

class Frame {
public:
	Frame() {}
	void write(FILE * outputStream);
	void addRandomPixels(double prob, int pixelWidth = 4, int pixelHeight = 4);
	void clear();
	void clamp(int * x, int * y);

	pixel * frame;
};

