#include "Rect.h"
#include "Frame.h"

void Rect::paint(byte r, byte g, byte b) {
	// Convert to integer and constrain to frame.
	int x0 = x;
	int x1 = x + w;
	int y0 = y;
	int y1 = y + h;
	clamp(&x0, &y0);
	clamp(&x1, &y1);
	for (int y = y0; y < y1; ++y) {
		for (int x = x0; x < x1; ++x) {
			frame[y * W * 3 + x * 3 + 0] = r;
			frame[y * W * 3 + x * 3 + 1] = g;
			frame[y * W * 3 + x * 3 + 2] = b;
		}
	}
}

void Rect::addRandomPixels(double prob, int pixelWidth, int pixelHeight) {
	int x0 = x;
	int x1 = x + w;
	int y0 = y;
	int y1 = y + h;
	clamp(&x0, &y0);
	clamp(&x1, &y1);
	Rect pixel(0, 0, pixelWidth, pixelHeight);
	for (pixel.y = 0; pixel.y < y1; pixel.y += pixelHeight) {
		for (pixel.x = 0; pixel.x < x1; pixel.x += pixelWidth) {
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

