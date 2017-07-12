#pragma once

#include <stdio.h>

#define W 720
#define H 480

typedef unsigned char byte;

class Kronos {
public:
	Kronos() : video_width(W), video_height(H), video_framerate(30) { 
		frame = new byte[H * W * 3];
	};

	~Kronos() {
		delete [] frame;
	}

	void clear_frame();
	void draw_frame(double t);
	void clamp(int * x, int * y);
	void draw_rect(int x, int y, int w, int h, byte r, byte g, byte b);

	int write(FILE * raw_audio_out, FILE * raw_video_out);

	const int video_width;
	const int video_height;
	const int video_framerate;

	byte * frame;
};

