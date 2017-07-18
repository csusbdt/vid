#include <cstdlib>
#include <cstring>
#include "Frame.h"
#include "Rect.h"
#include "Util.h"

Frame::Frame() { 
	data = new byte[frame_width * frame_height * 3]; 
}

Frame::~Frame() { 
	delete [] data; 
}

void Frame::clear() {
	memset(data, 0, frame_height * frame_width * 3); 
}

void Frame::setPixel(int x, int y, byte r, byte g, byte b) {
	data[y * frame_width * 3 + x * 3 + 0] = r;
	data[y * frame_width * 3 + x * 3 + 1] = g;
	data[y * frame_width * 3 + x * 3 + 2] = b;
	//data[y * frame_width + x + 0][0] = r;
	//data[y * frame_width + x + 1][1] = g;
	//data[y * frame_width + x + 2][2] = b;
}

/*! Write frame data into output stream. */
void Frame::write(FILE * file) {
	fwrite(data, 3, frame_height * frame_width, file);
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
	for (pixel.y = 0; pixel.y < frame_height; pixel.y += pixelHeight) {
		for (pixel.x = 0; pixel.x < frame_width; pixel.x += pixelWidth) {
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

