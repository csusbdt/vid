#include "Manager.h"
#include "Util.h"
#include "Loop.h"
#include "PreVideo.h"

extern Loop loop;

PreVideo preVideo;

void Manager::update(double dt) {
}

void Manager::mix(double t) {
}

void Manager::draw(double t) {
	for (int x = 0; x < preVideo.width; ++x) {
		for (int y = 0; y < preVideo.height; ++y) {
			if (Util::randomBool(.01)) {
				preVideo.setPixel(x, y, Util::randomInt(0, 360));
			}
		}
	}	
}

void Manager::activate() {
	for (int x = 0; x < preVideo.width; ++x) {
		for (int y = 0; y < preVideo.height; ++y) {
			preVideo.setPixel(x, y, Util::randomInt(0, 360));
		}
	}	
	loop.addObject(this);
	scenes.push_back(&circleScene);
	loop.addObject(scenes[0]);
	circleScene.start();
}

void Manager::deactivate() {
}

