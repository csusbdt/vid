/*
This program generates an mpeg4 video file 
with pixel animations and wave music.
*/

#include <iostream>
#include <sstream>
#include <sys/stat.h>
#include <stdio.h>
#include <cassert>
#include <cerrno>

typedef unsigned char byte;

using namespace std;

#define W 720
#define H 480

const double frames_per_second = 30;
const int duration_in_seconds = 3;

unsigned char frame[H][W][3];

void clear_frame() { memset(frame, 0, sizeof(frame)); }
void draw_rect(int x, int y, int w, int h, byte r, byte g, byte b);

void draw_frame(double t) {
	clear_frame();
	const double pps = 120; // pixels per second
	draw_rect(0 + t * pps, 0 + t * pps, 20, 10, 0x00, 0xff, 0x00);
}

// Constrain point to frame.
void clamp(int * x, int * y) {
	if (*x < 0) *x = 0; else if (*x > W) *x = W;
	if (*y < 0) *y = 0; else if (*y > H) *y = H;
}

void draw_rect(int x, int y, int w, int h, byte r, byte g, byte b) {
	int x0 = x;
	int x1 = x + w;
	int y0 = y;
	int y1 = y + h;
	clamp(&x0, &y0);
	clamp(&x1, &y1);
	for (int y = y0; y < y1; ++y) {
		for (int x = x0; x < x1; ++x) {
			frame[y][x][0] = r;
			frame[y][x][1] = g;
			frame[y][x][2] = b;
		}
	}
}

int main(int argc, char * argv[]) {
	const char * cmd = 
		"ffmpeg               "
		"-y                   "
		"-hide_banner         "
		"-f rawvideo          " // input to be raw video data
		"-pixel_format rgb24  "
		"-video_size 720x480  "
		"-framerate 30        " // frames per second
		"-i -                 " // read data from the standard input stream
		"-pix_fmt yuv420p     " // to render with Quicktime
		"-vcodec mpeg4        "
		"-an                  " // no audio
		"-q:v 5               " // quality level; 1 <= q <= 32
		"kronos.mp4           ";
	assert(errno == 0);
	FILE * raw_video_in = popen(cmd, "w");
	if (raw_video_in == 0) {
		assert(errno != 0);
		cout << "Failed to get raw_video_in pointer: ";
		cout << strerror(errno);
		cout << endl;
		return 1;
	}

	int num_frames = duration_in_seconds * frames_per_second;

	for (int i = 0; i < num_frames; ++i) {
		double time_in_seconds = i / frames_per_second;
		draw_frame(time_in_seconds);
		fwrite(frame, 3, W * H, raw_video_in);
	}

	fflush(raw_video_in);
	pclose(raw_video_in);

	cout << "Done." << endl;

	return 0;
}
