#!/bin/bash
export CMAKE_POLICY_VERSION_MINIMUM=3.21
thisdir=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)

buildmd()
{
    cd $thisdir

    local installpath=install
    if [ "$1" = "Debug" ]; then
        installpath+=d
    fi

    local buildtype=$1
    local srcpath=repo/$2
    local buildpath=build/${buildtype,,}/$2
    local buildpath=build/${buildtype,,}/$2

    shift 2
    local defines=$@

    mkdir -p $buildpath
    cmake -DCMAKE_BUILD_TYPE=$buildtype -DCMAKE_INSTALL_PREFIX=$installpath $defines \
          -S $srcpath -B $buildpath
    cmake --build $buildpath  -j8
    cmake --install $buildpath
}

# buildmd $1 assimp -DASSIMP_BUILD_TESTS=OFF -DASSIMP_INSTALL=ON -DASSIMP_BUILD_ZLIB=ON
buildmd $1 glad
buildmd $1 glm -DBUILD_SHARED_LIBS=OFF -DGLM_BUILD_TESTS=OFF
buildmd $1 SDL3 -DSDL_STATIC=ON -DSDL_SHARED=OFF \
                -DSDL_LIBC=ON -DSDL_TEST_LIBRARY=OFF -DSDL_TESTS=OFF

# temp=$thisdir/install/.lib
# actual=$thisdir/install/lib

# mkdir -p $temp && cp $actual/*.{a,so}* $temp/
# rm -rf $actual && mv $temp $actual
# rm -rf $thisdir/install/share



# #!/bin/bash
# export CMAKE_POLICY_VERSION_MINIMUM=3.21
# thisdir=$( cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)

# buildmd()
# {
#     cd $thisdir
#     local buildtype=$1
#     local srcpath=$2
#     local buildpath=$3
#     local installpath=$buildtype

#     mkdir -p $buildpath

#     shift 2
#     cmake $@ -DCMAKE_BUILD_TYPE=$buildtype -DCMAKE_INSTALL_PREFIX=$installpath \
#           $defines -S $srcpath -B $buildpath
#     cmake --build $buildpath -j8
#     cmake --install $buildpath


#     cd $thisdir
#     local buildtype=$1
#     local buildpath=$thisdir/build/cmake_$buildtype
#     local installpath=$thisdir/build/vane$buildtype

#     mkdir -p {$cmake_path,$vane_path}

#     cmake -DCMAKE_BUILD_TYPE=$buildtype -DCMAKE_INSTALL_PREFIX=$installpath \
#           -S $thisdir -B $cmake_path
#         #   -DCMAKE_TOOLCHAIN_FILE=x86_64-w64-mingw32.cmake

#     cmake --build $cmake_path -j8
#     cmake --install $cmake_path
# }

# buildmd Debug external/submodule/SDL3 external/build/SDL3

# if [ "$#" = "0" ]; then
#     exit 1
# fi


# bdext=0
# bddbg=0
# bdrel=0

# if [ "$#" = 0 ]; then
#     bddbg=1;
# fi

# for arg in "$@"; do
#     if [ "$arg" = "--external" ]; then
#         bdext=1
#     fi
#     if [ "$arg" = "--debug" ]; then
#         bddbg=1
#     fi
#     if [ "$arg" = "--release" ]; then
#         bdrel=1
#     fi
#     if [ "$arg" = "--full" ]; then
#         bdext=1
#         bddbg=1
#         bdrel=1
#     fi
# done


# if [ "$bdext" = "1" ]; then
#     if [ "$bddbg" = "1" ]; then
#         external/build.sh Debug
#     fi
#     if [ "$bdrel" = "1" ]; then
#         external/build.sh Debug
#     fi
# fi

# if [ "$bddbg" = "1" ]; then
#     vanebuild Debug
#     cd ./build/vane_Debug/
#     ./bin/vpkg -i ./engine -o engine.pkg
#     # rm -rf ./engine
# fi

# if [ "$bdrel" = "1" ]; then
#     vanebuild Release
#     cd ./build/vane_Release/
#     ./bin/vpkg -i ./engine -o engine.pkg
#     # rm -rf ./engine
# fi
