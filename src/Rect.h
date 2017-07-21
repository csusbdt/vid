#pragma once

#include "globals.h"

class Rect {
public:
	Rect() : x(0), y(0), w(frame_width), h(frame_height) {}

	Rect(double x, double y, double w, double h) 
	: x(x), y(y), w(w), h(h) {}

	void paint(byte r, byte g, byte b);

	double x;
	double y;
	double w;
	double h;
 
private:
	void addRandomPixels(double prob = 1);
};

