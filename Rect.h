#pragma once

#include "globals.h"
#include "Rect.h"

class Rect {
public:
	Rect(double x, double y, double w, double h) 
	: x(x), y(y), w(w), h(h) {}

	void paint(byte r, byte g, byte b);

	double x;	
	double y;	
	double w;	
	double h;	
private:
	void addRandomPixels(double prob, int pixelWidth = 4, int pixelHeight = 4);
};

