#pragma once

#include <stdio.h>

class Audio {
public:
//	static const double  PI                 = 3.14159265359;
	static const int  samplesPerSecond   = 48000;
//	static const int  durationInSamples  = (int) durationInSeconds * samplesPerSecond;

Audio() : file(nullptr), sample(0) {}
	void open();
	void close();
	void mix(signed short sample);
	void writeSample();

private:
	FILE * file;
	signed short sample;
};

