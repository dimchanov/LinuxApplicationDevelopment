CC = cc
GENERATES = maze_v0 maze_v1 maze_v2
TRASH = *.o *~ o.* *.rej *.orig
CFLAGS = -Wall -Werror


all: maze_v0 maze_v1

maze_v0: maze_generator.c
	$(CC) $(CFLAGS) $^ -o $@

maze_v1: maze_generator.c
	patch maze_generator.c $@.patch -o $@.c
	$(CC) $(CFLAGS) $@.c -o $@
	# rm -f $@.c

clean: genclean
	rm -f $(TRASH)

genclean:
	rm -f $(GENERATES) 

gitclean:
	git clean -df
