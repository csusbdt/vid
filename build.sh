c++ *.cpp           &&\
./a.out             &&\
ffmpeg           \
   -y            \
   -hide_banner  \
   -i audio.wav  \
   -i video.mp4  \
   kronos.mp4       &&\
open kronos.mp4

