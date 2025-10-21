#!/bin/bash
export CMAKE_POLICY_VERSION_MINIMUM=3.11
mkdir -p ./{include,lib}
cd external

mkdir -p SDL2/build
cd SDL2/build
cmake -G Ninja ../
ninja -j12
cd ../../

cp -R SDL2/build/include/SDL2 ../include/
cp -R SDL2/build/include-config-/SDL2 ../include/
cp SDL2/build/libSDL2*.a ../lib/


cp -R GLEW/GL ../include/
g++ -c GLEW/glew.c -o  ../lib/libGLEW.a
