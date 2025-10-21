#!/bin/bash
export CMAKE_POLICY_VERSION_MINIMUM=3.11

mkdir -p ./build/CMake
cd build/CMake
cmake -DWITH_OPENGL=ON -G Ninja ../../
ninja -j12
cd ../../

# cd vaneproj
# ./build.sh
# cp -R gamefolder/* build/
# cd ../
