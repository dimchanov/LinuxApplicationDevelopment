GENERATES = esub
TRASH = *.o *~ o.* o *.out tmp temp

all: test

esub: esub.o
	gcc -O0 -g -Wall $^ -o $@

test: clean esub
	@printf '\n*** Test 1 ***\n'
	echo 'Error: No match' > tmp
	./esub 1234 qwer asdf | tail -n 1 | cmp tmp

	@printf '\n*** Test 2 ***\n'
	echo zxcqwerasd | sed -E "s/qw(er)/Q\1Q/" > tmp
	./esub 'qw(er)' 'Q\1Q' zxcqwerasd  | tail -n 1 | cmp tmp

	@printf '\n*** Test 3 ***\n'
	printf '123\\321\n' > tmp
	./esub 'qw(er)' '123\\321' 'qwer'  | tail -n 1 | cmp tmp

	@printf '\n*** Test 4 ***\n'
	echo 'There is no group with number 3' > tmp
	./esub 'qw(er)' '123\\\\\321' 'qwer'  | tail -n 1 | cmp tmp

	@printf '\n*** Test 5 ***\n'
	echo 'Sun Oct 20 18:42:15 MSK 2024' | sed -E 's/([0-9][0-9]*)/<\1>/' > tmp
	./esub '([0-9][0-9]*)' '<\1>' 'Sun Oct 20 18:42:15 MSK 2024' | tail -n 1 | cmp tmp

	@printf '\n*** Test 6 ***\n'
	echo 'Sun Oct 20 18:42:15 MSK 2024' | sed -E "s/([[:digit:]]+)(.*)([[:digit:]]+)/<1=\1><2=\2><3=\3>/" > tmp
	./esub '([[:digit:]]+)(.*)([[:digit:]]+)' '<1=\1><2=\2><3=\3>' 'Sun Oct 20 18:42:15 MSK 2024' | tail -n 1 | cmp tmp

	@printf '\n*** Test 7 ***\n'
	echo 'Sun Oct 20 18:42:15 MSK 2024' | sed -E "s/(([[:digit:]]+).*)([[:digit:]]+)/<1=\1><2=\2><3=\3>/" > tmp
	./esub '(([[:digit:]]+).*)([[:digit:]]+)' '<1=\1><2=\2><3=\3>' 'Sun Oct 20 18:42:15 MSK 2024' | tail -n 1 | cmp tmp

clean::
	rm -f $(GENERATES) $(TRASH) 
