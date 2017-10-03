#pragma once

#include "Object.h"

class Circle : public Object {
public:
	Circle(double x, double y);
	virtual void update(double dt);
	virtual void draw(double t);
	virtual void mix(double t);
	virtual void activate();
	virtual void deactivate();
//	void reset();

private:
	double x; // x position as a percentage of frameWidth
	double y; // y position as a percentage of frameHeight
/*
	bool shouldDraw(int i, int j) const;
	void setHue(int hue);

	double elapsedMillis;
	double radius;
	double dRadius;
	double dy;
	unsigned char r;
	unsigned char g;
	unsigned char b;
	int xPixel; // position in pixels
	int yPixel;
	int radiusPixel;
	int repetitions;
*/
};

