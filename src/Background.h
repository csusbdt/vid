#pragma once

#include "Object.h"

class Background : public Object {
public:
	Background() : randomPixelProbability(.002) {}
	virtual ~Background() {}
	virtual void mix(double t);
	virtual void draw(double t);
	void init();
	void setRandomPixelProbability(double p);

private:
	double randomPixelProbability;
};

