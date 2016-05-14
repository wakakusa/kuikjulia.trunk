#!/bin/bash

./cleaner.sh

cmake .
make -j4
make
`echo $HOME`/kuikjulia.trunk/src/kuikjulia
