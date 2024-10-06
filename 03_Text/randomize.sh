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

tput clear

coords_perm=$(shuf -e ${char_coords[@]})
while read line
do
    IFS=',' read row col c <<< $line
    sleep $delay
    tput cup $row $col
    printf "$c"
done <<< $coords_perm

tput cup $lines_count 0
