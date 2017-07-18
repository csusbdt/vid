#include <iostream>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <vector>
#include "Kronos.h"
#include "globals.h"
//#include "Disc.h"

//static Disc disc;
//	Disc disc(Frame::w / 2, Frame::h / 2, Frame::h / 5);

int Kronos::write() {
	// Convert to scenes.
	background.init();
	objects.push_back(&background);

	double t = 0;  // Time t is in seconds.
	double nextFrameTime = 0;
	frame.addRandomPixels(4, 4, 1.0);
	for (double t = 0; t < duration_in_seconds; t += 1.0 / samples_per_second) {
		for (int i = 0; i < objects.size(); ++i) {
			Object * object = objects[i];
			object->mix(t);
		}
		audio.writeSample();
		if (t >= nextFrameTime) {
			for (int i = 0; i < objects.size(); ++i) {
				Object * object = objects[i];
				object->draw(t);
			}
			video.writeFrame();
			nextFrameTime += 1.0 / frames_per_second;
		}
		// Remove inactive objects.
		int i = 0;
		int k = 0;
		while (i < objects.size()) {
			if (objects[i]->active) {
				objects[k++] = objects[i];
			}
			++i;
		}
	}

	return 0;
}

