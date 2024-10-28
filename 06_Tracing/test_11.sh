#!/bin/bash

printf '\n*** Test 11 ***'
printf "
cat move.c > a;
strace -e fault=close -e fault=close:error=EINTR:when=1 -P ./a ./move a b 2> /dev/null
"
cat move.c > a;
strace -e fault=close -e fault=close:error=EINTR:when=1 -P ./a ./move a b 2> /dev/null
return_value=$?
printf "Return value: %d\n" $return_value
test $return_value -eq 11 && test -f a && !(test -f b) && printf "   PASSED\n" || printf "   FAILED\n"
rm -f a b
