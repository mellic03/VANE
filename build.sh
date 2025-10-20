#!/bin/bash
export CMAKE_POLICY_VERSION_MINIMUM=3.5

mkdir -p ./build/CMake
rm -rf ./build/vaneproj
# rm -rf ../vaneproj/{src_example,include,lib}


cd build/CMake
cmake -G Ninja ../../
ninja -j6
cd ../../


cd vaneproj
./build.sh
cp -R gamefolder/* build/
cd ../
# tar -czvf ./gamefolder.tgz -C vaneproj/gamefolder
