#!/bin/bash

cd build
make -j4
cd ..
build/src/$1
