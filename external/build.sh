#!/bin/bash
export CMAKE_POLICY_VERSION_MINIMUM=3.11
thisdir=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)

buildmd()
{
    cd $thisdir

    local buildtype=$1
    local srcpath=submodule/$2
    local buildpath=build/$buildtype/$2
    local installpath=install
    shift
    shift

    local defines=$@

    mkdir -p $buildpath

    cmake -DCMAKE_BUILD_TYPE=$buildtype -DCMAKE_INSTALL_PREFIX=$installpath $defines \
          -S $srcpath -B $buildpath
    cmake --build $buildpath  -j8
    cmake --install $buildpath
}

# buildmd $1 assimp -DASSIMP_BUILD_TESTS=OFF -DASSIMP_INSTALL=ON -DASSIMP_BUILD_ZLIB=ON
# buildmd $1 glad
# buildmd $1 glm -DBUILD_SHARED_LIBS=OFF -DGLM_BUILD_TESTS=OFF -DGLM_FORCE_INTRINSICS=ON
buildmd $1 SDL3 -DSDL_SHARED=ON -DSDL_STATIC=ON

temp=$thisdir/install/.lib
actual=$thisdir/install/lib

mkdir -p $temp && cp $actual/*.{a,so}* $temp/
rm -rf $actual && mv $temp $actual
rm -rf $thisdir/install/share
