#pragma once

class Object {
public:
	Object() : active(true) {}
	virtual ~Object() {}
	virtual void mix(double t) = 0;
	virtual void draw(double t) = 0;
	bool active;
};

