# C++ Playground

This repository contains scripts I use to test and learn C++ features and functionality.

*Note: It is assumed that all commands are run from the root of this repository.*

## How to use

*Hint: Make a `build` directory in the root of this repository. However, BASH scripts will create it automatically.*

### To clean everything and build from scratch

- `cd <repository-root>`
- `scripts/clean_and_build.sh`

### To make all files and run a specific one (for Debugging on x86_64)

- `cd <repository-root>`
- `scripts/make_and_run_debug_x86_64.sh <name-of-executable-without-path>`

### To run valgrind (for debugging on x86_64)

- Download and install *Valgrind*
- `cd <repository-root>`
- `scripts/valgrind_run_debug_x86_64.sh <name-of-executable-without-path>`

## How to add new files

### C++ source file

- Add a new file to `src` directory
- Name your file with `.cc` extension

  For libraries,
  - Don't use *underscores*
  - Add `lib` to the beginning of the file name, for e.g. `libvector.cc`

- Add corresponding entry to `src/CMakeLists.txt`

  For executables,
  - The name of executable should be same as that of source file but without `.cc` extension
  - For example, a new entry would be `add_executable(new_file new_file.cc)`

  For libraries,
  - The name of library should be same as that of source file but without `.cc` extension and `lib` prefix
  - For example, a new entry would be `add_library(vector libvector.cc)`
