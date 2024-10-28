#!/bin/bash

printf '\n*** Test 4 ***'
printf "
cat move.c > a;
strace -e fault=write -e fault=write:error=EBADF:when=1 ./move a b 2> /dev/null
"
cat move.c > a;
strace -e fault=write -e fault=write:error=EBADF:when=1 ./move a b 2> /dev/null
return_value=$?
printf "Return value: %d\n" $return_value
test $return_value -eq 4 && printf "   PASSED\n" || printf "   FAILED\n"
rm -f a b
