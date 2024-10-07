#!/bin/bash

delay=0
if [ $# != 0 ]
then
    delay=$1
fi

IFS="\n"
lines_count=0
char_coords=()
max_line_width=0
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

    if [ $max_line_width -lt ${#line} ]
    then
        max_line_width=${#line}
    fi

    ((lines_count++))
    lines+=$line
done

tput clear

X0=$(( ($(tput lines) - $lines_count) / 2))
Y0=$(( ($(tput cols) - $max_line_width) / 2))

coords_perm=$(shuf -e ${char_coords[@]})
while read line
do
    IFS=',' read row col c <<< $line
    sleep $delay
    tput cup $(($row + $X0)) $(($col + $Y0));
    printf "$c"
done <<< $coords_perm

tput cup $(tput lines) 0
