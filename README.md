Merge the following:

0) Kronos

1) ExpandingCirclesScene in viz project
	https://github.com/csusbdt/viz/blob/master/ExpandingCircleScene.cpp

2) video-gen in 201-2017-fall project
	https://github.com/csusbdt/201-2017-fall/tree/master/video-gen

3) vgs3 in 202-2018-winter project
	https://github.com/csusbdt/202-2018-winter/tree/master/vgs4

Design:

Give up using standard input/output and return to file writing.
From a single program, write images into a video frame folder
and samples into a raw audio file.  Then use ffmpeg to combine 
into an mp4 file.

Iteration 1:

Write program to render a tone into a file of raw audio samples and 
a folder with raw video frames.  Write Makefile to compile, run and
clean.  (Make self cleaning after running.)


