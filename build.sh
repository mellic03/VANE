#!/bin/bash
export CMAKE_POLICY_VERSION_MINIMUM=3.11

mkdir -p build/cmake_{debug,release}

cd build/cmake_debug
# cmake -DCMAKE_BUILD_TYPE=Debug -G Ninja ../../
cmake -DCMAKE_TOOLCHAIN_FILE=toolchain.cmake -DCMAKE_BUILD_TYPE=Debug -G Ninja ../../
ninja
cp external/{SDL2,GLEW}/*.so* ../vane_debug/bin/thirdparty/
cd ../../

# cd build/cmake_release
# cmake -DCMAKE_BUILD_TYPE=Release -G Ninja ../../
# ninja
# cp external/{SDL2,GLEW}/*.so* ../vane_release/bin/thirdparty/
# cd ../../

