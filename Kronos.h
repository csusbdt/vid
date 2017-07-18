#pragma once

#include <stdio.h>
#include "globals.h"

class Kronos {
public:
	Kronos() {};

	~Kronos() {}

	void clear_frame();
	void draw_frame(double t);
	void clamp(int * x, int * y);

	int write();
};

