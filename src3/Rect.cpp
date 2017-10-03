#include "Rect.h"
#include "Video.h"

extern Video video;

void Rect::fill(byte r, byte g, byte b) {
	// Convert to integer.
	int x0 = x;
	int x1 = x + w;
	int y0 = y;
	int y1 = y + h;
	for (int y = y0; y < y1; ++y) {
		for (int x = x0; x < x1; ++x) {
			video.setPixel(x, y, r, g, b);
		}
	}
}

//void Rect::drawRandomPixels(double prob = 1) {
//}

