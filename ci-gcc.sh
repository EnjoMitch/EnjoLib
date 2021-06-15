#!/bin/bash

MAKE=make
GEN="CodeBlocks - Unix Makefiles"

mkdir -p build && cd build
cmake -G "${GEN}" ..\
&& ${MAKE} -j `nproc` || ${MAKE} && ctest --verbose -R EnjoLibTest 
ctest --output-on-failure -j `nproc` && ${MAKE} -j `nproc` install

