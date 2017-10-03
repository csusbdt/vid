#pragma once

#include <vector>
#include "Scene.h"
#include "Circle.h"

using namespace std;

class CircleScene : public Scene {
public:
	CircleScene();
	virtual ~CircleScene();
	virtual void activate();
	virtual void deactivate();
	virtual void update(double dt);
	virtual void draw(double t);
	virtual void mix(double t);

private:
	bool firstFrame;
	Circle circle;
};

