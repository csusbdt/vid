#pragma once

#include <stdio.h>

typedef unsigned char byte;

class Video {
public:
//	const int width = 720;
//	const int height = 480;
//	const int framesPerSecond = 30;

	Video();
	~Video();
	void open();
	void close();
	void writeFrame();
	void clearFrame();
	void setPixel(int x, int y, byte r, byte g, byte b);

	byte * frame; // Make private.

private:
	void clamp(int * x, int * y);
	FILE * file;
};

