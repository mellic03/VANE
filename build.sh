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

usage_error()
{
    echo "Usage: build.sh [TARGET] [MODE]"
    echo "target"
    echo "  --vane      Engine only"
    echo "  --deps      Dependencies only"
    echo "  --all       Engine and Dependencies"
    echo "mode"
    echo "  Debug       Debug build"
    echo "  Release     Release build (implied)"
    exit 1
}

is_valid()
{
    local key=$1
    local items=$2
    for item in "${items[@]}"; do
        if [[ "$key" == "$item" ]]; then
            echo true
            break
        fi
    done
}

ValidTargets=("--vane" "--deps" "--all")
ValidModes=("Debug" "Release")
TgValid=true
MdValid=true
CurrTarget="--all"
CurrMode="Release"

if [ $# -eq 0 ]; then
    usage_error
fi

if [ $# -eq 1 ]; then
    TgValid=$(is_valid $1 $ValidTargets)
elif [ $# -eq 2 ]; then
    TgValid=$(is_valid $1 $ValidTargets)
    MdValid=$(is_valid $2 $ValidModes)
    CurrMode=$2
fi

if [ "$TgValid" = "false" ]; then
    usage_error
elif [ "$MdValid" = "false" ]; then
    usage_error
fi

CurrTarget=$1
CurrMode=$2

if [ "$CurrTarget" = "--all" ]; then
    echo "external/build.sh $CurrMode"
    echo "vanebuild $CurrMode"
    external/build.sh $CurrMode
    vanebuild $CurrMode
elif [ "$CurrTarget" = "--deps" ]; then
    echo "external/build.sh $CurrMode"
    external/build.sh $CurrMode
elif [ "$CurrTarget" = "--vane" ]; then
    echo "vanebuild $CurrMode"
    vanebuild $CurrMode
else
    usage_error
fi

