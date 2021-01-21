#!/bin/bash

cd bin
rm -rf ./*
cmake ..
make -j4
cd ..
