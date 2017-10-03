#include <iostream>
#include <climits>
#include <cassert>
#include "Loop.h"
#include "Audio.h"
#include "Video.h"
#include "PreVideo.h"
#include "Manager.h"

using namespace std;

Loop loop;
Audio audio;
Video video;
PreVideo preVideo;
Manager * manager;

int main(int argc, char * args[]) {
	assert(audio.samplesPerSecond * loop.durationInSeconds < INT_MAX);
	manager = new Manager();
	loop.run();
	cout << "Done." << endl;
}

