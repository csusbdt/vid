#pragma once

#include "Object.h"
#include "Wave.h"

class Circle : public Object {
public:
	Circle(Wave * wave);
	virtual void update(double dt);
	virtual void draw(double t) {}
	virtual void mix(double t);
	virtual void activate();
	virtual void deactivate();
//	void reset();

private:
	Wave * wave;
/*
	bool shouldDraw(int i, int j) const;
	void setHue(int hue);

	double elapsedMillis;
	double radius;
	double dRadius;
	double x; // x position as a percentage of frameWidth
	double y; // y position as a percentage of frameHeight
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

