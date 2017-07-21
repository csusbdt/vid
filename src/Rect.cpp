#include "Rect.h"
#include "Video.h"
#include "Util.h"

extern Video video;

void Rect::paint(byte r, byte g, byte b) {
	// Convert to integer and constrain to frame.
	int x0 = x;
	int x1 = x + w;
	int y0 = y;
	int y1 = y + h;
	video.clamp(&x0, &y0);
	video.clamp(&x1, &y1);
	for (int y = y0; y < y1; ++y) {
		for (int x = x0; x < x1; ++x) {
			video.setPixel(x, y, r, g, b);
		}
	}
}

