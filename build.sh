#!/bin/bash
export CMAKE_POLICY_VERSION_MINIMUM=3.11

mkdir -p build/cmake_{debug,release}

cmake -G Ninja -S ./ -B ./build/cmake_debug \
      -DCMAKE_BUILD_TYPE=Debug \
      -DCMAKE_INSTALL_PREFIX=$(pwd)/output/ \
      -DCMAKE_TOOLCHAIN_FILE=toolchain.cmake

cmake --build ./build/cmake_debug

# cmake -G Ninja ../../ -DCMAKE_BUILD_TYPE=Debug \
#       -DCMAKE_INSTALL_PREFIX=$(pwd)/output/ \
#       -DCMAKE_TOOLCHAIN_FILE=toolchain.cmake
# ninja
# cd ../../



# cd build/cmake_release
# cmake -G Ninja ../../ -DCMAKE_BUILD_TYPE=Release \
#       -DCMAKE_INSTALL_PREFIX=$(pwd)/output/ \
#       -DCMAKE_TOOLCHAIN_FILE=toolchain.cmake
# ninja
# cd ../../


