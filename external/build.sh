#!/bin/bash
export CMAKE_POLICY_VERSION_MINIMUM=3.11
thisdir=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)

buildmd()
{
    cd $thisdir

    local srcpath=submodule/$1
    local buildpath=build/$1
    local installpath=install
    shift # Remove $1
    local defines=$@

    mkdir -p $buildpath

    cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=$installpath $defines \
          -G Ninja -S $srcpath -B $buildpath
    cmake --build $buildpath --parallel 4
    cmake --install $buildpath
}


buildmd assimp
buildmd glad
buildmd glm -DBUILD_SHARED_LIBS=OFF -DGLM_BUILD_TESTS=OFF -DGLM_FORCE_INLINE=ON -DGLM_FORCE_INTRINSICS=ON
buildmd SDL3 -DSDL_SHARED=ON -DSDL_STATIC=ON


temp=$thisdir/install/.lib
actual=$thisdir/install/lib

mkdir -p $temp && cp $actual/*.{a,so}* $temp/
rm -rf $actual && mv $temp $actual
rm -rf $thisdir/install/share
