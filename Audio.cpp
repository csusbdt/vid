#include <sys/stat.h>
include "Audio.h"

void Audio::open() {
	const char * audio_cmd = 
		"ffmpeg               "
		"-y                   "
		"-hide_banner         "
		"-f s16le             "
		"-ar 48000            "
		"-ac 1                "
		"-i -                 "
		"audio.wav            ";
	assert(errno == 0);
	file = popen(audio_cmd, "w");
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

