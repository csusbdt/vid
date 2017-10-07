#include <iostream>
#include "CircleScene.h"
#include "Loop.h"
#include "PreVideo.h"
#include "Util.h"
#include "globals.h"

using namespace std;

CircleScene::CircleScene() : firstFrame(true), circle(.5, .5, 180, 16, 8) { 
}

CircleScene::~CircleScene() {
	deactivate();
}

void CircleScene::activate() {
	loop.addObject(this);
	circle.activate();
}

void CircleScene::deactivate() {
	circle.deactivate();
	loop.removeObject(this);
}

void CircleScene::update(double dt) {
}

void CircleScene::mix(double t) {
}

void CircleScene::draw(double t) {
	for (int x = 0; x < preVideo.getPreWidth(); ++x) {
		for (int y = 0; y < preVideo.getPreHeight(); ++y) {
			if (Util::randomBool(.01)) {
				preVideo.setPixel(x, y, Util::randomInt(0, 360));
			}
		}
	}	
}

