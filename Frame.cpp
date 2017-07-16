#include <cstdlib>
#include <cstring>
#include "Frame.h"
#include "Rect.h"
#include "Util.h"

void Frame::clear() {
	memset(data, 0, frameHeight * frameWidth * 3); 
}

/*! Write frame data into output stream. */
void Frame::write(FILE * file) {
	fwrite(data, 3, frameHeight * frameWidth, file);
}

/*! Constrain point to frame. */
void Frame::clamp(int * x, int * y) {
	if (*x < 0) *x = 0; else if (*x >= frame_width) *x = frame_width - 1;
	if (*y < 0) *y = 0; else if (*y >= frame_height) *y = frame_height - 1;
}

/*! Allows rectangular pixels of any size. 
    Use prob of 1 at startup to set every pixel in the frame.
*/
void Frame::addRandomPixels(double prob, int pixelWidth, int pixelHeight) {
	Rect pixel(0, 0, pixelWidth, pixelHeight);
	for (pixel.y = 0; pixel.y < h; pixel.y += pixelHeight) {
		for (pixel.x = 0; pixel.x < w; pixel.x += pixelWidth) {
			if (Util::randomBool(prob)) {
				int hue = Util::randomInt(0, 360);
				double fr, fg, fb;
				Util::HSVtoRGB(&fr, &fg, &fb, hue, 1.0, 1.0);
				char r = Util::doubleToChar(fr);
				char g = Util::doubleToChar(fg);
				char b = Util::doubleToChar(fb);
				pixel.paint(r, g, b);
			}
		}
	}	
}

