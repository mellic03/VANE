#!/bin/bash
export CMAKE_POLICY_VERSION_MINIMUM=3.11

thisdir=$( cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
cd $thisdir

mkdir -p ./SDL2_{build,install}

cmake -G Ninja -S ./SDL2 -B ./SDL2_build \
        -DCMAKE_BUILD_TYPE=Release \
        -DCMAKE_INSTALL_PREFIX="$thisdir/SDL2_install" \
        -DCMAKE_TOOLCHAIN_FILE="$thisdir/../x86_64-w64-mingw32.cmake"

cmake --build ./SDL2_build
cmake --install ./SDL2_build

