#!/usr/bin/env bash

if [ $# -eq 0 ]; then
    read -rp "Write the executable name: " prog
else
    prog=$1
fi

i=1
while IFS="," read -r arg1 arg2 output
do
    compare=$(eval ./"$prog" "$arg1" "$arg2")
    if [[ "$compare" = "$output" ]]
    then
        printf "%s Test %d: %s == %s\n" ✅ "$i" "'$compare'" "'$output'"
    else
        printf "%s Test %d: %s != %s\n" ❌ "$i" "'$compare'" "'$output'"
    fi
    ((i++))
done < tests.csv
