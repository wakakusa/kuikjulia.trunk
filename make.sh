#!/bin/bash

./cleaner.sh

cmake .
make -j4
make
/home/wakakusa/kuikjulia.trunk/src/kuikjulia
