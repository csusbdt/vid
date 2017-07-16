#pragma once

#include <vector>
#include "Object.h"
#include "Kronos.h"
#include "Audio.h"
#include "Video.h"
#include "Frame.h"
#include "Background.h"

typedef  unsigned char     byte;
typedef  byte              color                [3];

const    double            duration_in_seconds  = 5;
const    double            PI                   = 3.14159265359;
const    double            samples_per_second   = 48000;
const    int               frame_width          = 720;
const    int               frame_height         = 480;
const    double            frames_per_second    = 30;

extern   Kronos            kronos;
extern   Audio             audio;
extern   Video             video;
extern   Frame             frame;
extern   Background        background;

extern   vector<Object *>  objects;

