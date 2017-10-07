#pragma once

const double videoDurationInSeconds = 20;
const double samplesPerSecond = 48000.0;
const double framesPerSecond = 30;
const int width = 720;
const int height = 480;

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

