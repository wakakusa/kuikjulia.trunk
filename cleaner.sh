#!/bin/bash

rm -r ./CMakeFiles
rm ./CMakeCache.txt
rm ./cmake_install.cmake
rm ./Makefile

rm ./src/cmake_install.cmake
rm -r ./src/CMakeFiles
rm ./src/Makefile
rm ./src/kuikjulia

rm -r ./lib/CMakeFiles
rm ./lib/cmake_install.cmake
rm ./lib/Makefile
rm ./lib/*.a
rm ./lib/*.so

rm -r ./lib/*/CMakeFiles
rm ./lib/*/cmake_install.cmake
rm ./lib/*/Makefile
rm ./lib/*/*.a
rm ./lib/*/*.so

rm -r ./include/CMakeFiles
rm ./include/cmake_install.cmake
rm ./include/Makefile
rm ./include/pallet_defines.h
rm ./include/UserInterfaceFile.h
