CC = cc
GENERATES = maze_v0
TRASH = *.o *~ o.*
CFLAGS = -Wall -Werror


all: maze_v0

maze_v0: maze_generator.C
	$(CC) $(CFLAGS) $^ -o $@

test: all
	./maze_v0

clean: genclean
	rm -f $(TRASH)

genclean:
	rm -f $(GENERATES) 
