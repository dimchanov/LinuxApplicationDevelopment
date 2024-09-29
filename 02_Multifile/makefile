$(CC) = cc
GENERATES = prog README prog-a liboutput_static.a prog-so liboutput.so
TRASH = *.o *~ o.*
CFLAGS = -Wall -fPIC

all: README

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

fun.o prog.o: outlib.h

prog: const.o fun.o prog.o
	$(CC) $(CFLAGS) $^ -o $@

liboutput_static.a: fun.o const.o
	ar -rv $@ $^

prog-a: prog.o liboutput_static.a
	$(CC) $(CFLAGS) $^ -o $@

liboutput.so: fun.o const.o
	$(CC) $(CFLAGS) -shared $^ -o $@

prog-so: prog.o liboutput.so
	$(CC) $(CFLAGS) -L. $^ -o $@

README: prog
	./$< 2> $@

clean:
	rm -f $(TRASH)

distclean: clean
	rm -f $(GENERATES) 
