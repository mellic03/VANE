#!/bin/bash
export CMAKE_POLICY_VERSION_MINIMUM=3.21
thisdir=$( cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)

# mkdir -p cmake/{build,install}
# cmake -G Ninja -B cmake/build -S ./
# cmake --build cmake/build
# cmake --install cmake/build --prefix $thisdir/cmake/install


# mkdir -p cmakewin/{build,install}
# cmake -G Ninja -B cmakewin/build -S ./ \
#       -DCMAKE_TOOLCHAIN_FILE=x86_64-w64-mingw32.cmake
# cmake --build cmakewin/build
# cmake --install cmakewin/build --prefix $thisdir/cmakewin/install

g++ ./main.cpp ./src/vvm.cpp -I./include \
    -O0 -g --std=c++20 -Wall -Wextra -o vmtest
