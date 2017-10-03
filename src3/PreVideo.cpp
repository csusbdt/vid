#include <iostream>
#include <cassert>
#include <sstream>
#include "PreVideo.h"
#include "Video.h"
#include "Util.h"

using namespace std;

extern Video video;

PreVideo::PreVideo() : pixelWidth(4), pixelHeight(4) {
}

PreVideo::~PreVideo() { 
}

void PreVideo::setPixel(int x, int y, double hue) {
	x *= pixelWidth;
	y *= pixelHeight;
	double r;
	double g;
	double b;
	Util::HSVtoRGB(hue, 1, 1, &r, &g, &b);
	byte red = Util::doubleToByte(r);
	byte green = Util::doubleToByte(g);
	byte blue = Util::doubleToByte(b);
	for (int i = 0; i < pixelWidth; ++i) {
		for (int j = 0; j < pixelHeight; ++j) {
			video.setPixel(x + i, y + j, red, green, blue);
		}
	}
}

/*
void Video::setPixelDimensions(int pixelWidth, int pixelHeight) {
	this->pixelWidth = pixelWidth;
	this->pixelHeight = pixelHeight;
}

void Video::setRandomPixels(double prob, Rect region) {
	Rect pixel(0, 0, pixelWidth, pixelHeight);
	for (pixel.y = 0; pixel.y < frame_height; pixel.y += pixelHeight) {
		for (pixel.x = 0; pixel.x < frame_width; pixel.x += pixelWidth) {
			if (Util::randomBool(prob)) {
				int hue = Util::randomInt(0, 360);
				double fr, fg, fb;
				Util::HSVtoRGB(&fr, &fg, &fb, hue, 1.0, 1.0);
				byte r = Util::doubleToByte(fr);
				byte g = Util::doubleToByte(fg);
				byte b = Util::doubleToByte(fb);
				pixel.paint(r, g, b);
			}
		}
	}	
}
*/

