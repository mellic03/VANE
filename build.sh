#!/bin/bash
export CMAKE_POLICY_VERSION_MINIMUM=3.11
export VANE_OUTPUT_DIR=build/vproj

mkdir -p ./build/CMake
cd build/CMake
cmake -DCMAKE_BUILD_TYPE=RELEASE -G Ninja ../../
ninja -j12
