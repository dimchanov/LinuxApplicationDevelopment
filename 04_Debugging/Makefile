GENERATES = range
TRASH = *.o


all: clean test

range: range.c
	gcc -O0 -g -Wall $^ -o $@

test: clean range
	gdb --batch --quiet --command=gdb1 ./range | grep @@@ | cmp target1
	gdb --batch --quiet --command=gdb2 ./range | grep @@@ | cmp target2

clean:
	rm -f $(GENERATES) $(TRASH) 
