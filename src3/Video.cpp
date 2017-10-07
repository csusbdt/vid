#include <iostream>
#include <cassert>
#include <sstream>
#include "Video.h"
#include "Util.h"
#include "globals.h"

using namespace std;

extern const double framesPerSecond;
extern const int width;
extern const int height;

Video::Video() : file(nullptr) {
	frame = new byte[width * height * 3]; 
}

Video::~Video() { 
	delete [] frame; 
}

void Video::clearFrame() {
	memset(frame, 0, width * height * 3); 
}

void Video::writeFrame() {
	fwrite(frame, 3, height * width, file);
}

/*! Constrain point to frame. */
void Video::clamp(int * x, int * y) {
	if (*x < 0) *x = 0; else if (*x >= width) *x = width - 1;
	if (*y < 0) *y = 0; else if (*y >= height) *y = height - 1;
}

void Video::setPixel(int x, int y, byte r, byte g, byte b) {
	clamp(&x, &y);
	frame[y * width * 3 + x * 3 + 0] = r;
	frame[y * width * 3 + x * 3 + 1] = g;
	frame[y * width * 3 + x * 3 + 2] = b;
}

void Video::open() {
	stringstream video_cmd;
	video_cmd << "ffmpeg               ";
	video_cmd << "-y                   ";
	video_cmd << "-hide_banner         ";
	video_cmd << "-f rawvideo          ";
	video_cmd << "-pixel_format rgb24  ";
	video_cmd << "-video_size          ";
	video_cmd << width                  ;
	video_cmd << "x";
	video_cmd << height                 ;
	video_cmd << "                     ";
	video_cmd << "-framerate           "; 
	video_cmd << (int) framesPerSecond  ;
	video_cmd << "                     ";
	video_cmd << "-i -                 "; // read data from standard input stream
	video_cmd << "-pix_fmt yuv420p     "; // to render with Quicktime
	video_cmd << "-vcodec mpeg4        ";
	video_cmd << "-an                  "; // no audio
	video_cmd << "-q:v 5               "; // quality level; 1 <= q <= 32
	video_cmd << "video.mp4            ";

	assert(errno == 0);
	file = popen(video_cmd.str().c_str(), "w");
	if (file == 0) {
		assert(errno != 0);
		cout << "ffmpeg failed in Video.cpp: ";
		cout << strerror(errno);
		cout << endl;
		exit(1);
	}
}

void Video::close() {
	fflush(file);
	pclose(file);
}

