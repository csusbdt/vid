#include <climits>
#include <cassert>
#include "Loop.h"
#include "Audio.h"
#include "Video.h"
#include "Manager.h"

using namespace std;

extern Audio audio;
extern Video video;
extern Manager * manager;

void Loop::run() {
	audio.open();
	video.open();
	video.clearFrame();
	manager->activate();
	int durationInFrames = (int) (durationInSeconds * video.framesPerSecond);
	double secondsPerFrame = 1.0 / video.framesPerSecond;
	int sampleNumber = 0;
	for (int frameNumber = 0; frameNumber < durationInFrames; ++frameNumber) {
		// Update objects.
		for (auto obj : objects) {
			obj->update(secondsPerFrame);
		}

		// Generate next video frame.
		double t = frameNumber / (double) video.framesPerSecond;
		for (auto obj : objects) {
			obj->draw(t);
		}
		video.writeFrame();

		// Generate audio samples to cover one frame of video.
		int sampleNumberTarget = 
			frameNumber / video.framesPerSecond * audio.samplesPerSecond;
		while (sampleNumber < sampleNumberTarget) {
			double t = sampleNumber / (double) audio.samplesPerSecond;
			for (auto obj : objects) {
				obj->mix(t);
			}
			audio.writeSample();
			++sampleNumber;
		}
	}
	video.close();
	audio.close();
}

void Loop::addObject(Object * object) {
	for (auto o : objects) assert(o != object);
	objects.push_back(object);
}

void Loop::removeObject(Object * object) {
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

