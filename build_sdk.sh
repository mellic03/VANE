#!/bin/bash
export CMAKE_POLICY_VERSION_MINIMUM=3.11
export VANE_BUILD_SDK=YES

mkdir -p ./build/CMake
cd build/CMake
cmake -G Ninja ../../
ninja -j6
cd ../../

# cd vaneproj
# ./build.sh
# cp -R gamefolder/* build/
# cd ../
