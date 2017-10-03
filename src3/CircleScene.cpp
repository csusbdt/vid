#include <iostream>
#include "CircleScene.h"
#include "Loop.h"
#include "PreVideo.h"
#include "Util.h"

using namespace std;

extern Loop loop;
extern PreVideo preVideo;

CircleScene::CircleScene() : firstFrame(true) { 
	circles.push_back(Circle(&wave1));
	circles.push_back(Circle(&wave2));
	circles.push_back(Circle(&wave3));
	circles.push_back(Circle(&wave4));
	circles.push_back(Circle(&wave5));
}

CircleScene::~CircleScene() {
	deactivate();
}

void CircleScene::update(double dt) {
}

void CircleScene::mix(double t) {
}

/*
void CircleScene::drawFirstFrame() {
	for (int x = 0; x < preVideo.width; ++x) {
		for (int y = 0; y < preVideo.height; ++y) {
			preVideo.setPixel(x, y, Util::randomInt(0, 360));
		}
	}	
}
*/

void CircleScene::draw(double t) {
	if (firstFrame) { // Only fill
		preVideo.fillRandom();
		firstFrame = false;
	}
	for (int x = 0; x < preVideo.width; ++x) {
		for (int y = 0; y < preVideo.height; ++y) {
			if (Util::randomBool(.01)) {
				preVideo.setPixel(x, y, Util::randomInt(0, 360));
			}
		}
	}	
}

void CircleScene::activate() {
	loop.addObject(this);
	for (int i = 0; i < circles.size(); ++i) {
		circles[i].activate();
	}
}

void CircleScene::deactivate() {
	for (int i = 0; i < circles.size(); ++i) {
		circles[i].deactivate();
	}
	loop.removeObject(this);
}

