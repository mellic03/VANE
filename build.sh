#!/bin/bash
export CMAKE_POLICY_VERSION_MINIMUM=3.5

mkdir -p build/CMake
rm -rf ./build/vaneproj
rm -rf ../vaneproj/{example,include}

cd build/CMake
cmake -G Ninja ../../
ninja -j6
cd ../../

# tar -czvf ./gamefolder.tgz -C vaneproj/gamefolder

cp -R ./build/vaneproj ../