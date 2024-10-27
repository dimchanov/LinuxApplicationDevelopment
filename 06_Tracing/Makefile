CC = cc
GENERATES = move protected.so
TRASH = *.o *~ o.* test* *test infile outfile a b
CFLAGS = -Wall


move: move.c
	$(CC) $(CFLAGS) $^ -o $@

protected.so: protected.c
	$(CC) $(CFLAGS) -fPIC -shared $^ -o $@

clean: genclean
	rm -f $(TRASH)

genclean:
	rm -f $(GENERATES)
