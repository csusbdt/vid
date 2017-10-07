#pragma once

#include "Object.h"
#include "CircleScene.h"

class Manager : public Object {
public:
	Manager()                      {}
	virtual ~Manager()             {}
	virtual void update(double dt) {}
	virtual void mix(double t)     {}
	virtual void draw(double t)    {}

	virtual void activate();
	virtual void deactivate();

private:
	vector<Scene *> scenes;
	CircleScene circleScene;
};

