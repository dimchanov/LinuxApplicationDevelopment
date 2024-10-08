CC = cc
GENERATES = prog README prog-a liboutput_static.a prog-so liboutput.so
TRASH = *.o *~ o.* test* *test
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

clean: genclean
	rm -f $(TRASH)

genclean:
	rm -f $(GENERATES) 

test: prog prog-a prog-so
	./prog 2> prog_empty_test
	@printf '\n*** Without arguments ***\n'
	bash -c "exec -a ./prog ./prog-a 2> prog-a_empty_test"
	LD_LIBRARY_PATH=`pwd` bash -c "exec -a ./prog ./prog-so 2> prog-so_empty_test"
	cmp prog_empty_test prog-a_empty_test; cmp prog_empty_test prog-so_empty_test;
	
	@printf '\n*** One argument ***\n'
	./prog A 1> prog_one_arg_test
	./prog-a A 1> prog-a_one_arg_test
	LD_LIBRARY_PATH=`pwd` ./prog-so A 1> prog-so_one_arg_test
	cmp prog_one_arg_test prog-a_one_arg_test; cmp prog_one_arg_test prog-so_one_arg_test;

	@printf '\n*** Multiple argument ***\n'
	./prog A B C 1> prog_mult_arg_test
	./prog-a A B C 1> prog-a_mult_arg_test
	LD_LIBRARY_PATH=`pwd` ./prog-so A B C 1> prog-so_mult_arg_test
	cmp prog_mult_arg_test prog-a_mult_arg_test; cmp prog_mult_arg_test prog-so_mult_arg_test;
