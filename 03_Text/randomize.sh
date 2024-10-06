#!/bin/bash

delay=0
if [ $# != 0 ]
then
    delay=$1
fi

IFS="\n"
lines_count=0
char_coords=()

while read line
do
    for (( i=0; $i < ${#line}; i++ ))
    do  
        c=${line:i:1}
        if [ $c != " " ]
        then
            char_coords+=("$lines_count,$i,$c")
            ((chars_count++))
        fi

    done

    ((lines_count++))
done






