#!/bin/bash
export CMAKE_POLICY_VERSION_MINIMUM=3.21
thisdir=$( cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)

vanebuild()
{
    echo "[vanebuild] buildtype=$1"

    local buildtype=$1 # lowercase
    local buildpath=$thisdir/build/cmake/${buildtype,,}
    local installpath=$thisdir/build/${buildtype,,}

    mkdir -p {$buildpath,$installpath}

    cmake -DCMAKE_BUILD_TYPE=$buildtype -DCMAKE_INSTALL_PREFIX=$installpath \
          -S $thisdir -B $buildpath
        #   -DCMAKE_TOOLCHAIN_FILE=x86_64-w64-mingw32.cmake

    cmake --build $buildpath -j8
    cmake --install $buildpath
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

else
    if [ "$bddbg" = "1" ]; then
        vanebuild Debug
    fi
    if [ "$bdrel" = "1" ]; then
        vanebuild Release
    fi
fi

