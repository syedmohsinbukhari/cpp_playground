#!/bin/bash

mkdir -p build
cd build
make -j4
cd ..
build/src/$1
