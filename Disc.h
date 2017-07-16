#pragma once

#include "Object.h"

class Disc : public Object{
public:
	Disc() : Object() {}
	virtual ~Disc() {}
	virtual void mix(double t);
	virtual void draw(double t);
};

