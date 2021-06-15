#!/bin/bash

export LD_LIBRARY_PATH=/home/enjo/devel/lib/tree/lib\
:bin/Release-x64
TEST_FILE=../tests/EnjoLibUTest/bin/Release-x64/EnjoLibUTest
if [ -e $TEST_FILE ]; then
	echo "Executing $TEST_FILE"
	$TEST_FILE
else
	echo "Not found $TEST_FILE !"
fi

