#include "Rect.h"
#include "Frame.h"
#include "Util.h"

void Rect::paint(byte r, byte g, byte b) {
	// Convert to integer and constrain to frame.
	int x0 = x;
	int x1 = x + w;
	int y0 = y;
	int y1 = y + h;
	frame.clamp(&x0, &y0);
	frame.clamp(&x1, &y1);
	for (int y = y0; y < y1; ++y) {
		for (int x = x0; x < x1; ++x) {
			frame.setPixel(x, y, r, g, b);
		}
	}
}

void Rect::addRandomPixels(double prob, int pixelWidth, int pixelHeight) {
	int x0 = x;
	int x1 = x + w;
	int y0 = y;
	int y1 = y + h;
	frame.clamp(&x0, &y0);
	frame.clamp(&x1, &y1);
	Rect pixel(0, 0, pixelWidth, pixelHeight);
	for (pixel.y = 0; pixel.y < y1; pixel.y += pixelHeight) {
		for (pixel.x = 0; pixel.x < x1; pixel.x += pixelWidth) {
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

