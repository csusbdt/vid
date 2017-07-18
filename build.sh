cd src              &&\
c++ *.cpp           &&\
cd ..               &&\
mv src/a.out .      &&\
./a.out             &&\
ffmpeg           \
   -y            \
   -hide_banner  \
   -i audio.wav  \
   -i video.mp4  \
   kronos.mp4       &&\
open kronos.mp4

