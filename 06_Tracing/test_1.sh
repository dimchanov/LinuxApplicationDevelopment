#!/bin/bash

printf '\n*** Test 1 ***'
printf "
cat move.c > a; ./move 2> /dev/null;
"
cat move.c > a; ./move 2> /dev/null;
return_value=$?
printf "Return value: %d\n" $return_value
test $return_value -eq 1 && printf "   PASSED\n" || printf "   FAILED\n"
rm -f a b
