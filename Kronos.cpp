#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include "Kronos.h"

const double PI = 3.14159265359;

extern Kronos kronos;

void Kronos::clear_frame() { memset(frame, 0, video_height * video_width * 3); }

void Kronos::draw_frame(double t) {
	clear_frame();
	const double pps = 120; // pixels per second
	draw_rect(0 + t * pps, 0 + t * pps, 20, 10, 0x00, 0xff, 0x00);
}

// Constrain point to frame.
void Kronos::clamp(int * x, int * y) {
	if (*x < 0) *x = 0; else if (*x >= kronos.video_width) *x = kronos.video_width - 1;
	if (*y < 0) *y = 0; else if (*y >= kronos.video_height) *y = kronos.video_height - 1;
}

void Kronos::draw_rect(int x, int y, int w, int h, byte r, byte g, byte b) {
	int x0 = x;
	int x1 = x + w;
	int y0 = y;
	int y1 = y + h;
	clamp(&x0, &y0);
	clamp(&x1, &y1);
	for (int y = y0; y < y1; ++y) {
		for (int x = x0; x < x1; ++x) {
			frame[y * W * 3 + x * 3 + 0] = r;
			frame[y * W * 3 + x * 3 + 1] = g;
			frame[y * W * 3 + x * 3 + 2] = b;
		}
	}
}

int Kronos::write(FILE * raw_audio_out, FILE * raw_video_out) {
	const double duration_in_seconds = 5;

	const double samples_per_second = 48000;
	int num_samples = duration_in_seconds * samples_per_second;
	for (int i = 0; i < num_samples; ++i) {
		short sample = sin(2 * PI * i / 180.0) * SHRT_MAX;
		fwrite(reinterpret_cast<unsigned char *>(&sample), 1, 2, raw_audio_out);
	}

	const double frames_per_second = 30;
	int num_frames = duration_in_seconds * frames_per_second;
	for (int i = 0; i < num_frames; ++i) {
		double time_in_seconds = i / frames_per_second;
		draw_frame(time_in_seconds);
//		fwrite(frame, 3, video_width * video_height, raw_video_out);
	}
	return 0;
}

