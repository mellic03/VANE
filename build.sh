#!/bin/bash
export CMAKE_POLICY_VERSION_MINIMUM=3.11
thisdir=$( cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)

vanebuild()
{
    local BuildType=$1
    local cmake_flag=""
    local cmake_path="$thisdir/build/cmake_$BuildType/"
    local vane_path="$thisdir/build/vane_$BuildType/"

    mkdir -p {$cmake_path,$vane_path}

    cmake -DCMAKE_BUILD_TYPE=$bdtype -DCMAKE_INSTALL_PREFIX=$vane_path \
          -S $thisdir -B $cmake_path
        #   -DCMAKE_TOOLCHAIN_FILE=x86_64-w64-mingw32.cmake

    cmake --build $cmake_path -j8
    cmake --install $cmake_path
}

if [ "$#" = "0" ]; then
    exit 1
fi


bdext=0
bddbg=0
bdrel=0

if [ "$#" = 0 ]; then
    bddbg=1;
fi

for arg in "$@"; do
    if [ "$arg" = "--external" ]; then
        bdext=1
    fi
    if [ "$arg" = "--debug" ]; then
        bddbg=1
    fi
    if [ "$arg" = "--release" ]; then
        bdrel=1
    fi
    if [ "$arg" = "--full" ]; then
        bdext=1
        bddbg=1
        bdrel=1
    fi
done


if [ "$bdext" = "1" ]; then
    if [ "$bddbg" = "1" ]; then
        external/build.sh Debug
    fi
    if [ "$bdrel" = "1" ]; then
        external/build.sh Debug
    fi
fi

if [ "$bddbg" = "1" ]; then
    vanebuild Debug
    cd ./build/vane_Debug/
    ./bin/vpkg -i ./engine -o engine.pkg
    # rm -rf ./engine
fi

if [ "$bdrel" = "1" ]; then
    vanebuild Release
    cd ./build/vane_Release/
    ./bin/vpkg -i ./engine -o engine.pkg
    # rm -rf ./engine
fi
