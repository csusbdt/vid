#include <cassert>
#include <iostream>
#include <climits>
#include "Loop.h"
#include "Audio.h"
#include "Video.h"
#include "PreVideo.h"
#include "Manager.h"

using namespace std;

double videoDurationInSeconds = 20;
double samplesPerSecond = 48000.0;
double framesPerSecond = 30;
int width = 720;
int height = 480;

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

