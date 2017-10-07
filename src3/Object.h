#pragma once

class Object {
public:
	virtual void activate   ()          = 0;
	virtual void deactivate ()          = 0;
	virtual void update     (double dt) = 0;
	virtual void mix        (double t)  = 0;
	virtual void draw       (double t)  = 0;
};

