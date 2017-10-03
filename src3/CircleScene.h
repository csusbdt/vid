#pragma once

#include <vector>
#include "Scene.h"
#include "Circle.h"

using namespace std;

class CircleScene : public Scene {
public:
	CircleScene();
	virtual ~CircleScene();
	virtual void start();
	virtual void stop();
	virtual void update(double dt);

	virtual void mix(double t);
	virtual void draw(double t);
	virtual void activate();
	virtual void deactivate();

private:
	vector<Circle> circles;
};

