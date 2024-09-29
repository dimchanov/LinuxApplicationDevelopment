$(CC) = cc
GENERATES = prog README prog-a liboutput_static.a
TRASH = *.o *~ o.*
CFLAGS = -Wall

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

README: prog
	./$< 2> $@

clean:
	rm -f $(TRASH)

distclean: clean
	rm -f $(GENERATES) 
