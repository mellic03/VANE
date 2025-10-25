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

    cmake -DCMAKE_INSTALL_PREFIX=$installpath -DCMAKE_BUILD_TYPE=Release $defines \
          -G Ninja -S $srcpath -B $buildpath
    cmake --build $buildpath --parallel 4
    cmake --install $buildpath
}


buildmd assimp
buildmd glad
buildmd glm -DBUILD_SHARED_LIBS=OFF -DGLM_BUILD_TESTS=OFF \
            -DGLM_FORCE_INLINE -DGLM_FORCE_INTRINSICS
buildmd SDL3 -DSDL_SHARED=OFF -DSDL_STATIC=ON

