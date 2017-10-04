#include <cmath>
#include "Circle.h"
#include "Util.h"
#include "Audio.h"
#include "Loop.h"

extern Audio audio;
extern Loop loop;

void Circle::activate() {
	loop.addObject(this);
}

void Circle::deactivate() {
	loop.removeObject(this);
}

void Circle::mix(double t) {
	wave.mix(t);
}

void Circle::update(double dt) {
}

void Circle::draw(double t) {
}

/*

Circle::Circle(Wave * wave) 
: radius(0), x(0), y(0), r(255), g(255), b(255), dy(0), xPixel(0), yPixel(0), elapsedSeconds(0), repetitions(3), wave(wave) {
	setHue(30);
	p = 0.30;
}

void Circle::reset() {
	elapsedSeconds = 0;
	x = Util::randomDouble(0, 1);
	y = Util::randomDouble(0, 1);
	xPixel = x * frameWidth;
	yPixel = y * frameHeight;
	radius = 0;
	radiusPixel = 0;
	dRadius = Util::randomDouble(0.00005, 0.0005);
	setHue(Util::randomInt(0, 360));
	repetitions = Util::randomInt(3, 9);
}

bool Circle::draw(int i, int j) const {
	double distPixel = sqrt((xPixel - i) * (xPixel - i) + (yPixel - j) * (yPixel - j));
	// Convert distance from circle center to distance from circle edge.
	double dist = app.pixelToY(distPixel);
	if (dist < radius) {
		dist = radius - dist;
	} else {
		dist = dist - radius;
	}
	double prob = dist < 1 ? pow(1 - dist, 10) * p : 0;
	if (Util::randomBool(prob)) {
		app.draw(i, j, r, g, b);
		return true;
	} else {
		return false;
	}
}

void Circle::update(double dt) {
	//elapsedMillis += deltaMillis;
	elapsedSeconds += dt;
	radius += dRadius * dt;
	if (radius > 2) {
		if (--repetitions <= 0) {
			reset();
		} else {
			radius = 0;
		}
	} 
	radiusPixel = dPixels(radius);
}

void Circle::setHue(int hue) {
	double fr, fg, fb;
	Util::HSVtoRGB(&fr, &fg, &fb, hue, 1.0, 1.0);
	r = Util::doubleToChar(fr);
	g = Util::doubleToChar(fg);
	b = Util::doubleToChar(fb);
}

*/

