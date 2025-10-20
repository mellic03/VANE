#!/bin/bash
export CMAKE_POLICY_VERSION_MINIMUM=3.5

mkdir -p ./build/CMake
rm -rf ./build/vaneproj

rm -rf ./vaneproj/{src_example,include,lib}
rm -rf ../vaneproj/{src_example,include,lib}


cd build/CMake
cmake -G Ninja ../../
ninja -j6
cd ../../

# tar -czvf ./gamefolder.tgz -C vaneproj/gamefolder

cp -R ./build/vaneproj/* ./vaneproj
rm -rf ./vaneproj/src_example