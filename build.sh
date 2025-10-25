#!/bin/bash
export CMAKE_POLICY_VERSION_MINIMUM=3.11
thisdir=$( cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)

vanebuild()
{
    local suffix=$1
    local cmake_flag=""
    local cmake_path="$thisdir/build/cmake_$suffix/"
    local vane_path="$thisdir/build/vane_$suffix/"

    if [ "$suffix" = "debug" ]; then
        cmake_flag="Debug"
    elif [ "$suffix" = "release" ]; then
        cmake_flag="Release"
    else
        echo "Usage: ./build.sh [debug|release]"
        exit 1
    fi

    mkdir -p {$cmake_path,$vane_path}

    cmake -G Ninja -S $thisdir -B $cmake_path \
          -DCMAKE_BUILD_TYPE=$cmake_flag \
          -DCMAKE_INSTALL_PREFIX=$vane_path \
          -DCMAKE_TOOLCHAIN_FILE=x86_64-w64-mingw32.cmake

    cmake --build $cmake_path
    cmake --install $cmake_path
}


vanebuild "debug"

