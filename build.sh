#!/bin/bash

mkdir -p build/CMake
cd build/CMake
CMAKE_POLICY_VERSION_MINIMUM=3.5 cmake ../../
make -j6

# cd ../
# cp ./CMake/libvane.a ./lib/
# cp -R ../include ./
