/*
This program generates an mpeg4 video file with 
coordinated pixel animations and wave music.

Approach:

1) Write audio samples into audio.wav and write
   video frames into video.mp4.

2) Run ffmpeg to merge audio.wav and video.mp4 
   into kronos.mp4.
*/

#include <iostream>
#include <cassert>
#include <cerrno>
#include <vector>
#include "Kronos.h"
#include "Audio.h"
#include "Video.h"
#include "Object.h"

using namespace std;

// Define all global variables.
Kronos kronos;
Audio audio;
Video video;
vector<Object *> objects;

int main(int argc, char * argv[]) {
	video.clearFrame();
	audio.open();
	video.open();
	kronos.write();
	video.close();
	audio.close();
	cout << "Done." << endl;
	return 0;
}
