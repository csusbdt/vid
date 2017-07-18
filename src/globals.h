#pragma once

typedef  unsigned char     byte;
typedef  byte              color                [3];

#include <vector>

using namespace std;

#include "Object.h"
#include "Kronos.h"
#include "Audio.h"
#include "Video.h"
#include "Frame.h"
#include "Background.h"

const    double            duration_in_seconds  = 5;
const    double            PI                   = 3.14159265359;
const    int               samples_per_second   = 48000;
const    int               frame_width          = 720;
const    int               frame_height         = 480;
const    int               frames_per_second    = 30;

class Kronos;
class Audio;
class Video;
class Frame;
class Background;

extern   Kronos            kronos;
extern   Audio             audio;
extern   Video             video;
extern   Frame             frame;
extern   Background        background;

extern   vector<Object *>  objects;

