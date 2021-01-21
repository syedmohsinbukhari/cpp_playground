#!/bin/bash

cd bin
make -j4
cd ..
bin/src/$1
