#!/bin/bash
export CMAKE_POLICY_VERSION_MINIMUM=3.11
thisdir=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
BuildType=$1

buildmd()
{
    cd $thisdir

    local srcpath=submodule/$1
    local buildpath=build/$1
    local installpath=install
    shift # Remove $1

    local defines=$@
    mkdir -p $buildpath

    cmake -DCMAKE_BUILD_TYPE=$BuildType -DCMAKE_INSTALL_PREFIX=$installpath $defines \
          -S $srcpath -B $buildpath
    cmake --build $buildpath  -j8
    cmake --install $buildpath
}

buildmd assimp -DASSIMP_BUILD_TESTS=OFF -DASSIMP_INSTALL=ON -DASSIMP_BUILD_ZLIB=ON
buildmd glad
buildmd glm -DBUILD_SHARED_LIBS=OFF -DGLM_BUILD_TESTS=OFF -DGLM_FORCE_INTRINSICS=ON
buildmd SDL3 -DSDL_SHARED=ON -DSDL_STATIC=ON

temp=$thisdir/install/.lib
actual=$thisdir/install/lib

mkdir -p $temp && cp $actual/*.{a,so}* $temp/
rm -rf $actual && mv $temp $actual
rm -rf $thisdir/install/share
