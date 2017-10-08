#pragma once

#include <stdio.h>
#include "globals.h"

class Video {
public:
	Video            ();
	~Video           ();
	void open        ();
	void close       ();
	void writeFrame  ();
	void clearFrame  ();
	void setPixel    (int x, int y, byte r, byte g, byte b);

private:
	FILE * file;
	byte * frame;

	void clamp(int * x, int * y);
};

