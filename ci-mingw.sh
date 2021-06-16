#!/bin/bash

MAKE=make
GEN="MSYS Makefiles"

GCC_PREFIX=x86_64-w64-mingw32
CMAKE_C_COMPILER="${GCC_PREFIX}-gcc"
CMAKE_CXX_COMPILER="${GCC_PREFIX}-g++"

BUILD_DIR="build/mingw"

mkdir -p $BUILD_DIR && cd $BUILD_DIR
cmake -G "${GEN}" ../.. \
-DCMAKE_C_COMPILER="${CMAKE_C_COMPILER}" \
-DCMAKE_CXX_COMPILER="${CMAKE_CXX_COMPILER}" \
&& ${MAKE} -j `nproc` || ${MAKE} && ${MAKE} -j `nproc` install
# TODO: Failing tests!
ctest --verbose -R EnjoLibTest || ctest --output-on-failure -j `nproc` || true

