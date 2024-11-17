CC = cc
GENERATES = maze maze_v1 maze_v2 maze_v3
TRASH = *.o *~ o.* *.rej *.orig
CFLAGS = -Wall -Werror


all: $(GENERATES)

maze: maze_generator.c
	$(CC) $(CFLAGS) $^ -o $@

maze_v%: maze_generator.c
	patch maze_generator.c $@.patch -o $@.c
	$(CC) $(CFLAGS) $@.c -o $@
	rm -f $@.c

test: clean all
	# 0
	./maze
	# 1
	./maze_v1 8
	# 2
	./maze_v2 ' @' 5
	# 3
	./maze_v3 12 '.#' 4
	./maze_v3 11 '.#' 4
	./maze_v3 12 '.#' 4

clean: genclean
	rm -f $(TRASH)

genclean:
	rm -f $(GENERATES) 

gitclean:
	git clean -df
