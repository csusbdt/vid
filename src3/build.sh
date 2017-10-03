c++                                \
    -std=c++11                     \
    *.cpp                          \
    ../../ambient-music/api/*.cpp  \
    -I.                            \
    -I../../ambient-music/api      \
&&                                 \
./a.out                            \
&&                                 \
open video.mp4

