#pragma once

#include <stdio.h>

typedef unsigned char byte;

class Video {
public:
	const int width = 720;
	const int height = 480;
	const int framesPerSecond = 30;

	Video();
	~Video();
	void open();
	void close();
	void writeFrame();
	void clearFrame();
	void clamp(int * x, int * y);
	void setPixel(int x, int y, byte r, byte g, byte b);
	void onSample(signed short sample);

	byte * frame;

//	void setPixelDimensions(int pixelWidth, int pixelHeight);
//	void setPixel(int x, int y, byte r, byte g, byte b);
//	void setRandomPixels(double prob = 1, Rect region = Rect());

private:
	FILE * file;
//	int pixelWidth;
//	int pixelHeight;
};

