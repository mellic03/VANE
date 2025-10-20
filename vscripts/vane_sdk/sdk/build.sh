#!/bin/bash
export CMAKE_POLICY_VERSION_MINIMUM=3.5

mkdir -p build/CMake
cd build/CMake
cmake -G Ninja ../../
ninja -j6

cd ../../
cp -R gamefolder/* build/vaneproject/
# tar -xvf gamefolder.tar -C build/vaneproj/