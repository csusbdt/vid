#pragma once

#include <stdio.h>

class Audio {
public:
	Audio() : file(nullptr), sample(0) {}
	void open();
	void close();
	void mix(signed short sample);
	void writeSample();

private:
	FILE * file;
	signed short sample;
};

