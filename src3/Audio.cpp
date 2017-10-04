#include <cassert>
#include <iostream>
#include <sstream>
#include <sys/stat.h>
#include "Audio.h"

using namespace std;

void Audio::open() {
	stringstream cmd;
	cmd << "ffmpeg                ";
	cmd << "-y                    ";
	cmd << "-hide_banner          ";
	cmd << "-f s16le              ";
	cmd << "-ac 1                 ";
	cmd << "-ar                   ";
	cmd << samplesPerSecond  << " ";
	cmd << "-i -                  ";
	cmd << "-write_xing 0         ";
	cmd << "audio.mp3             ";

	assert(errno == 0);
	file = popen(cmd.str().c_str(), "w");
	if (file == 0) {
		assert(errno != 0);
		cout << "ffmpeg failed in Audio.cpp: ";
		cout << strerror(errno);
		cout << endl;
		exit(1);
	}
}

void Audio::close() {
	fflush(file);
	pclose(file);
}

void Audio::mix(signed short sample) { 
	this->sample += sample;
}

void Audio::writeSample() {
	fwrite(reinterpret_cast<unsigned char *>(&sample), 1, 2, file);
	sample = 0;
}

