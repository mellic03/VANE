#!/bin/bash
export CMAKE_POLICY_VERSION_MINIMUM=3.21
thisdir=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)

buildtype=$1
installpath=$thisdir/build/${1,,}
libpath=$thisdir/install/${1,,}

buildmd()
{
    cd $thisdir
    local projectname=$1
    local srcpath=$thisdir/submodule/$projectname
    local cmakepath=$thisdir/build/$projectname
    shift 1
    local defines=$@

    mkdir -p $cmakepath
    cmake -S $srcpath -B $cmakepath -DCMAKE_BUILD_TYPE=$buildtype $defines
    cmake --build $cmakepath -j8
    cmake --install $cmakepath --prefix $installpath
}


buildmd assimp -DBUILD_SHARED_LIBS=ON -DASSIMP_BUILD_ZLIB=OFF
# buildmd glad -DBUILD_SHARED_LIBS=OFF
# buildmd glm -DBUILD_SHARED_LIBS=OFF -DGLM_BUILD_TESTS=OFF
# buildmd SDL -DSDL_STATIC=OFF -DSDL_SHARED=ON -DSDL_LIBC=ON
# buildmd vanelang

# if [ ! -d "$installpath/bin/tcc" ]; then
#     cd ./submodule/tinycc && ./configure --prefix=$installpath --ext-prefix=$installpath
#     make && make install
# fi



# shaderc_dir=$thisdir/repo/shaderc/
# cd $shaderc_dir
# ./util/git-sync-deps
# mkdir -p build && cd build
# cmake -G Ninja -DCMAKE_BUILD_TYPE=$1 -DCMAKE_INSTALL_PREFIX=$thisdir/install_shaderc ../
