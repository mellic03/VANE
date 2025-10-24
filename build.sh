#!/bin/bash
export CMAKE_POLICY_VERSION_MINIMUM=3.11

mkdir -p build/cmake_{debug,release}

cd build/cmake_debug
# cmake -DCMAKE_BUILD_TYPE=Debug -G Ninja ../../
cmake -DCMAKE_TOOLCHAIN_FILE=toolchain.cmake -DCMAKE_BUILD_TYPE=Debug -G Ninja ../../
ninja
cd ../../

# cd build/cmake_release
# cmake -DCMAKE_BUILD_TYPE=Release -G Ninja ../../
# ninja
# cd ../../


