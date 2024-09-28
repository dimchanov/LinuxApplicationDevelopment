$(CC) = cc
GENERATES = prog README
TRASH = *.o *~ o.*
CFLAGS = -Wall

all: README

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

fun.o prog.o: outlib.h

prog: const.o fun.o prog.o
	$(CC) $^ -o $@

README: prog
	./$< 2> $@

clean:
	rm -f $(TRASH)

distclean: clean
	rm -f $(GENERATES) 





