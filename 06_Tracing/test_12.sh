#!/bin/bash

printf '\n*** Test 12 ***'
printf "
cat move.c > a;
touch b;
strace -e fault=close -e fault=close:error=EINTR:when=1 -P ./b ./move a b 2> /dev/null
"
cat move.c > a;
touch b;
strace -e fault=close -e fault=close:error=EINTR:when=1 -P ./b ./move a b 2> /dev/null
return_value=$?
printf "Return value: %d\n" $return_value
test $return_value -eq 12 && printf "   PASSED\n" || printf "   FAILED\n"
rm -f a b
