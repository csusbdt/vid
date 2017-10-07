#include <iostream>
#include <cassert>
#include <sstream>
#include "PreVideo.h"
#include "Video.h"
#include "Util.h"
#include "globals.h"

using namespace std;

PreVideo::PreVideo() : pixelWidth(4), pixelHeight(4) {
	preWidth  = 720 / 4;
	preHeight = 480 / 4;
}

PreVideo::~PreVideo() { 
}

int PreVideo::getPreWidth() const {
	return preWidth;
}

int PreVideo::getPreHeight() const {
	return preHeight;
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

//void PreVideo::fillRandom() {
//	for (int x = 0; x < width; ++x) {
//		for (int y = 0; y < height; ++y) {
//			setPixel(x, y, Util::randomInt(0, 360));
//		}
//	}	
//}

/*
void PreVideo::setPixelDimensions(int pixelWidth, int pixelHeight) {
	this->pixelWidth = pixelWidth;
	this->pixelHeight = pixelHeight;
}
*/

