#pragma once

class Object {
public:
	Object() : alive(true) {}
	virtual ~Object() {}
	virtual void mix(double t) = 0;
	virtual void draw(double t) = 0;
	bool alive;
};

