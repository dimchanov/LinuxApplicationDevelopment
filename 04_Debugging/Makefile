GENERATES = range
TRASH = *.o


all: clean test

range: range.c
	gcc -O0 -g -Wall $^ -o $@

clean:
	rm -f $(GENERATES) $(TRASH) 
