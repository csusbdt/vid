#include <cassert>
#include <sstream>
#include <sys/stat.h>
#include "Video.h"

void Video::open() {
	stringstream video_cmd;
	video_cmd << "ffmpeg "              ;
	video_cmd << "-y "                  ;
	video_cmd << "-hide_banner "        ;
	video_cmd << "-f rawvideo "         ; // input to be raw video data
	video_cmd << "-pixel_format rgb24 " ;
	video_cmd << "-video_size "         ;
	video_cmd << frame.w                ;
	video_cmd << "x"                    ;
	video_cmd << frame.h                ;
	video_cmd << " "                    ;
	video_cmd << "-framerate  "         ; // frames per second
	video_cmd << frame.framerate        ;
	video_cmd << " "                    ;
	video_cmd << "-i - "                ; // read data from the standard input stream
	video_cmd << "-pix_fmt yuv420p "    ; // to render with Quicktime
	video_cmd << "-vcodec mpeg4 "       ;
	video_cmd << "-an "                 ; // no audio
	video_cmd << "-q:v 5 "              ; // quality level; 1 <= q <= 32
	video_cmd << "video.mp4 "           ;

	assert(errno == 0);
	file = popen(video_cmd.str().c_str(), "w");
	if (file == 0) {
		assert(errno != 0);
		cout << "ffmpeg failed in Video.cpp: ";
		cout << strerror(errno);
		cout << endl;
		exit(1);
	}
}

void Video::close() {
	fflush(file);
	pclose(file);
}

void Video::writeFrame() {
	frame.write(file);
}

