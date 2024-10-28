#!/bin/bash

printf '\n*** Test 3 ***'
printf "
cat move.c > a;
strace -e trace=openat -e fault=openat:error=ENOENT:when=4 ./move a b 2> /dev/null
"
cat move.c > a;
strace -e trace=openat -e fault=openat:error=ENOENT:when=4 ./move a b 2> /dev/null
return_value=$?
printf "Return value: %d\n" $return_value
test $return_value -eq 3 && printf "   PASSED\n" || printf "   FAILED\n"
rm -f a b
