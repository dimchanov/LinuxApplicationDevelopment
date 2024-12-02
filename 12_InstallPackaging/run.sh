#!/bin/bash

autoreconf -fisv
./configure
make
# man doxygen-doc/man/man1/guess_number.1
