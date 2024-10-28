CC = cc
GENERATES = move protected.so
TRASH = *.o *~ o.* infile outfile a b
CFLAGS = -Wall


move: move.c
	$(CC) $(CFLAGS) $^ -o $@

protected.so: protected.c
	$(CC) $(CFLAGS) -fPIC -shared $^ -o $@

clean: genclean
	rm -f $(TRASH)

genclean:
	rm -f $(GENERATES)

test_move: clean move test_move_protected
	@./test_0.sh
	@./test_1.sh
	@./test_2.sh
	@./test_3.sh
	@./test_4.sh
	@./test_5.sh
	@./test_11.sh
	@./test_12.sh
	@./test_13.sh
	
test_move_protected: clean move protected.so
	@./test_protected.sh
