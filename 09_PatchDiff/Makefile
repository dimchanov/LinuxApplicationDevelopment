CC = cc
GENERATES = maze_v0
TRASH = *.o *~ o.*
CFLAGS = -Wall -Werror


maze_v0: maze_generator.C
	$(CC) $(CFLAGS) $^ -o $@

clean: genclean
	rm -f $(TRASH)

genclean:
	rm -f $(GENERATES) 
