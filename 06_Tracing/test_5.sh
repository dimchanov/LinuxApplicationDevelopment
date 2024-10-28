#!/bin/bash

printf '\n*** Test 5 ***'
printf "
cat move.c > a;
strace -e fault=read -e fault=read:error=EFAULT:when=2 ./move a b 2> /dev/null
"
cat move.c > a;
strace -e fault=read -e fault=read:error=EFAULT:when=2 ./move a b 2> /dev/null
return_value=$?
printf "Return value: %d\n" $return_value
test $return_value -eq 5 && test -f a && !(test -f b) && printf "   PASSED\n" || printf "   FAILED\n"
rm -f a b
