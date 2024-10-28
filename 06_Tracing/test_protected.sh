#!/bin/bash

printf '\n*** Test PROTECT ***'
printf "
cat move.c > PROTECT_a;
LD_PRELOAD=./protected.so ./move PROTECT_a b 2> /dev/null
"
cat move.c > PROTECT_a;
LD_PRELOAD=./protected.so ./move PROTECT_a b 2> /dev/null
return_value=$?
printf "Return value: %d\n" $return_value
test $return_value -eq 0 && test -f PROTECT_a && test -f b && printf "   PASSED\n" || printf "   FAILED\n"
rm -f PROTECT_a b
