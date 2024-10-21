GENERATES = esub
TRASH = *.o *~ o.* o *.out

all: test

esub: esub.o
	gcc -O0 -g -Wall $^ -o $@

clean::
	rm -f $(GENERATES) $(TRASH) 
