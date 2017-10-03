c++                                \
    -std=c++11                     \
    *.cpp                          \
&&                                 \
./a.out                            \
&&                                 \
ffmpeg                             \
    -y                             \
    -hide_banner                   \
    -i video.mp4                   \
    -i audio.mp3                   \
    -c:v copy                      \
    -map 0:v:0                     \
    -map 1:a:0                     \
    kronos.mp4                     \
&&                                 \
open kronos.mp4

#    ../../ambient-music/api/*.cpp  \
#    -I .                           \
#    -I ../../ambient-music/api     \
