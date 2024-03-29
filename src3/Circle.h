#pragma once

#include "Wave.h"

class Circle : public Object {
public:
	Circle(  double x, 
	         double y,
	         double toneFrequency,
		 double waiverFrequency,
	         double longPeriod
	) :
	         x(x),
	         y(y),
	         wave(toneFrequency, waiverFrequency, longPeriod)
	{ }

	virtual void update(double dt);
	virtual void draw(double t);
	virtual void mix(double t);
	virtual void activate();
	virtual void deactivate();

private:
	Wave wave;
	double x;   // x position as a percentage of frameWidth
	double y;   // y position as a percentage of frameHeight
	//double tone;
	//double waiverFrequency;
	//double longPeriod;

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

