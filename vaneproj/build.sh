#!/bin/bash
export CMAKE_POLICY_VERSION_MINIMUM=3.5

mkdir -p {.build,build}
cd ./.build
cmake -G Ninja ../
ninja -j6

# cd ../
# cp -R gamefolder/* build/vaneproject/
# tar -xvf ./gamefolder.tar -C build/vaneproj/
# tar -cf ./gamefolder.tar -C build/vaneproj/ ./
