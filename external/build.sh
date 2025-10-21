#!/bin/bash

# export GLEW_PREFIX="/home/michael/Desktop/VANE/external/GLEW/zzz"
# export GLEW_DEST="/home/michael/Desktop/VANE/external/GLEW/zzz"
# mkdir -p GLEW/zzz
# cd GLEW
# make
# make install
# make clean
# cd ../../

export CMAKE_POLICY_VERSION_MINIMUM=3.11

mkdir -p SDL2/build
cd SDL2/build
cmake -G Ninja ../
ninja -j12
cd ../../


cp -R SDL2/build/include/SDL2 ../include/
cp SDL2/build/libSDL2*.a ../lib/
