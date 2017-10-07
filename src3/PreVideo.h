#pragma once

#include <stdio.h>

typedef unsigned char byte;

class PreVideo {
public:
	//const int width = 720 / 4;
	//const int height = 480 / 4;
	//const int framesPerSecond = 30;

	PreVideo();
	~PreVideo();
	void open();
	void close();
	void writeFrame();
	void clearFrame();
	void clamp(int * x, int * y);
	void setPixel(int x, int y, double hue);
	//void fillRandom();
	int getPreWidth() const;
	int getPreHeight() const;

	byte * frame;

// Try to use in CircleScene setup:
//	void setRandomPixels(double prob = 1, Rect region = Rect());

//	void setPixelDimensions(int pixelWidth, int pixelHeight);
//	void setPixel(int x, int y, byte r, byte g, byte b);

private:
	FILE * file;
	int preWidth;
	int preHeight;
	int pixelWidth;
	int pixelHeight;
};

