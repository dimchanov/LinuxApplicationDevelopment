CC = cc
GENERATES = move
TRASH = *.o *~ o.* test* *test infile outfile a b
CFLAGS = -Wall


move: move.c
	$(CC) $(CFLAGS) $^ -o $@

clean: genclean
	rm -f $(TRASH)

genclean:
	rm -f $(GENERATES) 



