#pragma once

#include "Object.h"

class Scene : public Object {
public:
	virtual void start() = 0;
	virtual void stop() = 0;
	virtual void update(double dt) = 0;

	virtual void mix(double t) = 0;
	virtual void draw(double t) = 0;
	virtual void activate() = 0;
	virtual void deactivate() = 0;

protected:
	virtual ~Scene() {}
};

