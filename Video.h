#pragma once

#include <stdio.h>
#include "Object.h"

class Video {
public:
	Video() {}
	void open();
	void close();
	void writeFrame();

private:
	FILE * file;
};

