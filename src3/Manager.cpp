#include <cassert>
#include "Manager.h"
#include "Util.h"
#include "Loop.h"
#include "PreVideo.h"
#include "globals.h"

void Manager::activate() {
	// Initialize frame to random hues.
	for (int x = 0; x < preVideo.getPreWidth(); ++x) {
		for (int y = 0; y < preVideo.getPreHeight(); ++y) {
			preVideo.setPixel(x, y, Util::randomInt(0, 360));
		}
	}

	// Architecture:
	//    The manager is the root object; it is created in main.
	//    Objects other than the manager have a crontrolling, parent object
	//    that activates and deactivates them.  Other than activation,
	//    parents have no control over their children.
	//    Typically, an object adds itself to the loop when activated
	//    but this is not required.

// doc generation Doxygen

	loop.addObject(this);
	circleScene.activate();
}

void Manager::deactivate() {
	circleScene.deactivate();
	loop.removeObject(this);
}

