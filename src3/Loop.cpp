#include <climits>
#include <cassert>
#include "Loop.h"
#include "Audio.h"
#include "Video.h"
#include "Manager.h"
#include "globals.h"

using namespace std;

void Loop::run() {
	int durationInFrames = (int) (videoDurationInSeconds * framesPerSecond);
	double secondsPerFrame = 1.0 / framesPerSecond;
	int sampleNumber = 0;
	for (int frameNumber = 0; frameNumber < durationInFrames; ++frameNumber) {
		// Update objects.
		for (auto obj : objects) {
			if (frameNumber > 0) obj->update(secondsPerFrame);
		}

		// Generate and write the next video frame.
		double t = frameNumber / (double) framesPerSecond;
		for (auto obj : objects) {
			obj->draw(t);
		}
		video.writeFrame();

		// Generate audio samples to cover one frame of video.
		int sampleNumberTarget = 
			frameNumber / framesPerSecond * samplesPerSecond;
		while (sampleNumber < sampleNumberTarget) {
			double t = sampleNumber / (double) samplesPerSecond;
			for (auto obj : objects) {
				obj->mix(t);
			}
			audio.writeSample();
			++sampleNumber;
		}
	}
}

void Loop::addObject(Object * object) {
	for (auto o : objects) assert(o != object);
	objects.push_back(object);
}

int Loop::indexOf(const Object * object) const {
	for (int i = 0; i < objects.size(); ++i) {
		if (objects[i] == object) return i;
	}
	assert(false);
}

void Loop::removeObject(const Object * object) {
	assert(objects.size() > 0);
	int i = 0;
	while (objects[i] != object) { 
		++i;
	}
	assert(i < objects.size());
	int j = i + 1;
	while (j < objects.size()) {
		objects[i++] = objects[j++];
	}
	objects.pop_back();
}

