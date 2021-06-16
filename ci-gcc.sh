#!/bin/bash

MAKE=make
GEN="CodeBlocks - Unix Makefiles"
BUILD_DIR="build/gcc"

mkdir -p $BUILD_DIR && cd $BUILD_DIR

cmake -G "${GEN}" ../.. \
&& ${MAKE} -j `nproc` || ${MAKE} && ctest --verbose -R EnjoLibTest 
ctest --output-on-failure -j `nproc` && ${MAKE} -j `nproc` install

