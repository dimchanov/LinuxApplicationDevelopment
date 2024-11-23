autoreconf -fisv && ./configure --enable-gcov && make
make gcov
make checklog
