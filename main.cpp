/*
This program generates an mpeg4 video file with 
coordinated pixel animations and wave music.

Approach:

1) Write audio samples into audio.raw and write
   video frames into video.mp4.

2) Run ffmpeg to merge audio.raw and video.mp4 
   into kronos.mp4.
*/

#include <iostream>
#include <sstream>
#include <sys/stat.h>
#include <stdio.h>
#include <cassert>
#include <cerrno>
#include "Kronos.h"

using namespace std;

typedef unsigned char byte;

Kronos kronos;

int main(int argc, char * argv[]) {
	const char * audio_cmd = 
		"ffmpeg               "
		"-y                   "
		"-hide_banner         "
		"-f s16le             "
		"-ar 48000            "
		"-ac 1                "
		"-i -                 "
		"audio.wav            ";
	assert(errno == 0);
	FILE * raw_audio_out = popen(audio_cmd, "w");
	if (raw_audio_out == 0) {
		assert(errno != 0);
		cout << "Failed to get raw_audio_out pointer: ";
		cout << strerror(errno);
		cout << endl;
		return 1;
	}

	stringstream video_cmd;
	video_cmd << "ffmpeg "              ;
	video_cmd << "-y "                  ;
	video_cmd << "-hide_banner "        ;
	video_cmd << "-f rawvideo "         ; // input to be raw video data
	video_cmd << "-pixel_format rgb24 " ;
	video_cmd << "-video_size "         ;
	video_cmd << kronos.video_width     ;
	video_cmd << " "                    ;
	video_cmd << kronos.video_height    ;
	video_cmd << " "                    ;
	video_cmd << "-framerate  "         ; // frames per second
	video_cmd << kronos.video_framerate ;
	video_cmd << " "                    ;
	video_cmd << "-i - "                ; // read data from the standard input stream
	video_cmd << "-pix_fmt yuv420p "    ; // to render with Quicktime
	video_cmd << "-vcodec mpeg4 "       ;
	video_cmd << "-an "                 ; // no audio
	video_cmd << "-q:v 5 "              ; // quality level; 1 <= q <= 32
	video_cmd << "video.mp4 "           ;

	assert(errno == 0);
	FILE * raw_video_out = popen(video_cmd.str().c_str(), "w");
	if (raw_video_out == 0) {
		assert(errno != 0);
		cout << "Failed to get raw_video_out pointer: ";
		cout << strerror(errno);
		cout << endl;
		return 1;
	}

	int return_value = kronos.write(raw_audio_out, raw_video_out);
	if (return_value != 0) return return_value;

	fflush(raw_audio_out);
	pclose(raw_audio_out);

	fflush(raw_video_out);
	pclose(raw_video_out);

	cout << "Done." << endl;

	return 0;
}
