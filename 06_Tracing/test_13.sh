#!/bin/bash

printf '\n*** Test 13 ***'
printf "
cat move.c > a;
strace -e fault=unlink -e fault=unlink:error=EFAULT:when=1 ./move a b 2> /dev/null
"
cat move.c > a;
strace -e fault=unlink -e fault=unlink:error=EFAULT:when=1 ./move a b 2> /dev/null
return_value=$?
printf "Return value: %d\n" $return_value
test $return_value -eq 13 && test -f a && test -f b && printf "   PASSED\n" || printf "   FAILED\n"
rm -f a b
