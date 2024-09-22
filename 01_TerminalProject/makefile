CC=cc
LDLIBS=-lncursesw
CFLAGS=-Wall

%: %.c
	$(CC) $(CFLAGS) $< -o $@ $(LDLIBS)

all: Show

clean:
	rm -f *.o
