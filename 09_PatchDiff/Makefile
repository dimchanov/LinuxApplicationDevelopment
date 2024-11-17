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
	

clean: genclean
	rm -f $(TRASH)

genclean:
	rm -f $(GENERATES) 

gitclean:
	git clean -df
