#pragma once

#include "Object.h"

class Background : public Object {
public:
	Background() : Object() {}
	virtual ~Background() {}
	virtual void mix(double t);
	virtual void draw(double t);
	void init();
private:
	void addRandomPixels(double prob, int pixelWidth = 4, int pixelHeight = 4);
};

