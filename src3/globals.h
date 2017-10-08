#pragma once

typedef unsigned char byte;

const double PI                     = 3.141592653589793238462;
const double PHI                    = 1.61803398875;
const double E                      = 2.718281828459;
const double videoDurationInSeconds = 20;
const double samplesPerSecond       = 48000;
const double framesPerSecond        = 30;
const int    width                  = 720;
const int    height                 = 480;

class Loop;
class Audio;
class Video;
class PreVideo;
class Manager;

extern Loop loop;
extern Audio audio;
extern Video video;
extern PreVideo preVideo;
extern Manager manager;

