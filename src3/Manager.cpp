#include <cassert>
#include "Manager.h"
#include "Util.h"
#include "Loop.h"
#include "PreVideo.h"
#include "globals.h"

void Manager::activate() {
	for (int x = 0; x < preVideo.getPreWidth(); ++x) {
		for (int y = 0; y < preVideo.getPreHeight(); ++y) {
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

