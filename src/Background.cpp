#include <cmath>
#include "globals.h"
#include "Background.h"
#include "Rect.h"
#include "Util.h"
#include "Video.h"

extern Video video;

void Background::setRandomPixelProbability(double p) {
	randomPixelProbability = p;
}

void Background::init() {
	video.setRandomPixels();
}

void Background::draw(double t) {
	video.setRandomPixels(randomPixelProbability);
}

void Background::mix(double t) {
//	short sample = sin(t * 2 * PI * 180) * (SHRT_MAX >> 1);
//	audio.mix(sample);
}

