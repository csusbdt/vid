#pragma once

#include <stdio.h>
#include "globals.h"

class Kronos {
public:
	Kronos() {
		//frame = new byte[videoWidth * videoHeight * 3];
	};

	~Kronos() {
		//delete [] frame;
	}

	void clear_frame();
	void draw_frame(double t);
	void clamp(int * x, int * y);
	void draw_rect(int x, int y, int w, int h, byte r, byte g, byte b);

	//int write(FILE * raw_audio_out, FILE * raw_video_out);
	int write();
};

