#include <cassert>
#include <iostream>
#include <climits>
#include "Loop.h"
#include "Audio.h"
#include "Video.h"
#include "PreVideo.h"
#include "Manager.h"
#include "globals.h"

using namespace std;

Loop loop;
Audio audio;
Video video;
PreVideo preVideo;
Manager manager;

int main(int argc, char * args[]) {
	assert(samplesPerSecond * videoDurationInSeconds < INT_MAX);

	audio.open();
	video.open();
	video.clearFrame();
	manager.activate();
	loop.run();
	video.close();
	audio.close();
	cout << "Done." << endl;
}

