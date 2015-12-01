#!/bin/bash

# Use this script for UNIX systems only
# DO NOT CHANGE UNLESS YOU KNOW WHAT YOU ARE DOING
export CC=clang
rm -rf build
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=.. ..
make
make install
cd ..
