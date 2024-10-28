#!/bin/bash

printf '\n*** Test 0 ***'
printf "
cat move.c > a; ./move a b;
cmp move.c b && test -f a
"
cat move.c > a; ./move a b && cmp move.c b
return_value=$?
printf "Return value: %d\n" $return_value
test $return_value -eq 0 && !(test -f a) && test -f b && printf "   PASSED\n" || printf "   FAILED\n"
rm -f a b
