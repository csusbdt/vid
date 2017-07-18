#include <cmath>
#include "globals.h"
#include "Background.h"
#include "Rect.h"
#include "Util.h"

void Background::init() {
	addRandomPixels(1.0);
}

void Background::draw(double t) {
	addRandomPixels(.002);
}

void Background::mix(double t) {
	short sample = sin(t * 2 * PI * 180) * (SHRT_MAX >> 1);
	audio.mix(sample);
}

/*! Allows rectangular pixels of any size. 
    Use prob of 1 at startup to set every pixel in the frame.
*/
void Background::addRandomPixels(double prob, int pixelWidth, int pixelHeight) {
	Rect pixel(0, 0, pixelWidth, pixelHeight);
	for (pixel.y = 0; pixel.y < frame_height; pixel.y += pixelHeight) {
		for (pixel.x = 0; pixel.x < frame_width; pixel.x += pixelWidth) {
			if (Util::randomBool(prob)) {
				int hue = Util::randomInt(0, 360);
				double fr, fg, fb;
				Util::HSVtoRGB(&fr, &fg, &fb, hue, 1.0, 1.0);
				byte r = Util::doubleToByte(fr);
				byte g = Util::doubleToByte(fg);
				byte b = Util::doubleToByte(fb);
				pixel.paint(r, g, b);
			}
		}
	}	
}

