#pragma once

#include <vector>
#include "Scene.h"
#include "Circle.h"
#include "Wave1.h"
#include "Wave2.h"
#include "Wave3.h"
#include "Wave4.h"
#include "Wave5.h"

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
	vector<Circle> circles;
	Wave1 wave1;
	Wave2 wave2;
	Wave3 wave3;
	Wave4 wave4;
	Wave5 wave5;
};

