#include <climits>
#include <cmath>
#include "globals.h"
#include "Disc.h"

void Disc::mix(double t) {
	short sample = sin(t * 2 * PI / 180.0) * SHRT_MAX;
	audio.mix(sample);
}

void Disc::draw(double t) {
}

