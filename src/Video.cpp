#include <iostream>
#include <cassert>
#include <sstream>
#include "globals.h"
#include "Video.h"
#include "Util.h"

using namespace std;

Rect Video::rect(0, 0, frame_width, frame_height);

Video::Video() : pixelWidth(4), pixelHeight(4), file(nullptr) {
	frame = new byte[frame_width * frame_height * 3]; 
}

Video::~Video() { 
	delete [] frame; 
}

void Video::clearFrame() {
	memset(frame, 0, frame_height * frame_width * 3); 
}

void Video::writeFrame() {
	fwrite(frame, 3, frame_height * frame_width, file);
}

/*! Constrain point to frame. */
void Video::clamp(int * x, int * y) {
	if (*x < 0) *x = 0; else if (*x >= frame_width) *x = frame_width - 1;
	if (*y < 0) *y = 0; else if (*y >= frame_height) *y = frame_height - 1;
}

void Video::setPixel(int x, int y, byte r, byte g, byte b) {
	clamp(&x, &y);
	frame[y * frame_width * 3 + x * 3 + 0] = r;
	frame[y * frame_width * 3 + x * 3 + 1] = g;
	frame[y * frame_width * 3 + x * 3 + 2] = b;
}

void Video::setPixelDimensions(int pixelWidth, int pixelHeight) {
	this->pixelWidth = pixelWidth;
	this->pixelHeight = pixelHeight;
}

void Video::setRandomPixels(double prob, Rect region) {
	Rect pixel(0, 0, pixelWidth, pixelHeight);
	for (pixel.y = 0; pixel.y < frame_height; pixel.y += pixelHeight) {
		for (pixel.x = 0; pixel.x < frame_width; pixel.x += pixelWidth) {
			if (Util::randomBool(prob)) {
				int hue = Util::randomInt(0, 360);
				double fr, fg, fb;
				Util::HSVtoRGB(&fr, &fg, &fb, hue, 1.0, 1.0);
				byte r = Util::doubleToByte(fr);
				byte g = Util::doubleToByte(fg);
				byte b = Util::doubleToByte(fb);
				pixel.paint(r, g, b);
			}
		}
	}	
}

void Video::open() {
	stringstream video_cmd;
	video_cmd << "ffmpeg               ";
	video_cmd << "-y                   ";
	video_cmd << "-hide_banner         ";
	video_cmd << "-f rawvideo          ";
	video_cmd << "-pixel_format rgb24  ";
	video_cmd << "-video_size          ";
	video_cmd << frame_width            ;
	video_cmd << "x";
	video_cmd << frame_height           ;
	video_cmd << "                     ";
	video_cmd << "-framerate           "; 
	video_cmd << frames_per_second      ;
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

