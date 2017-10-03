#include "Manager.h"
#include "Util.h"
#include "Loop.h"
#include "PreVideo.h"

extern Loop loop;
extern PreVideo preVideo;

void Manager::update(double dt) {
}

void Manager::mix(double t) {
}

void Manager::draw(double t) {
}

void Manager::activate() {
	for (int x = 0; x < preVideo.width; ++x) {
		for (int y = 0; y < preVideo.height; ++y) {
			preVideo.setPixel(x, y, Util::randomInt(0, 360));
		}
	}	
	loop.addObject(this);
	circleScene.activate();
}

void Manager::deactivate() {
	circleScene.deactivate();
	loop.removeObject(this);
}

