#!/bin/bash
export CMAKE_POLICY_VERSION_MINIMUM=3.5

mkdir -p build/CMake
cd build/CMake
cmake -G Ninja ../../
ninja -j6
