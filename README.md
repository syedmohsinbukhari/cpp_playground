# C++ Playground

This repository contains scripts I use to test and learn C++ features and functionality.

*Note: It is assumed that all commands are run from the root of this repository.*

## How to use

*Hint: Make a `build` directory in the root of this repository. However, BASH scripts will create it automatically.*

### To clean everything and build from scratch

- `cd <repository-root>`
- `scripts/clean_and_build.sh`

### To make all files and run a specific one

- `cd <repository-root>`
- `scripts/make_and_run.sh <name-of-file-without-extension>`

## How to add new files

### C++ source file

- Add a new file to `src` directory
- Name your file with `.cc` extension
- Add corresponding entry to `src/CMakeLists.txt`
  - The Name of executable should be same as that of source file but without `.cc`
  - For example, a new entry would be `add_executable (new_file new_file.cc)`
