#!/usr/bin/env bash

if [ $# -eq 0 ]; then
    read -rp "Write the executable name: " prog
else
    prog=$1
fi

i=1
while IFS="," read -r argument output
do
    compare=$(eval ./"$prog" "$argument")
    if [[ "$compare" = "$output" ]]
    then
        printf "%s Test %d: %s == %s\n" ✅ "$i" "'${compare:0:100}'" "'${output:0:100}'"
    else
        printf "%s Test %d: %s != %s\n" ❌ "$i" "'${compare:0:100}'" "'${output:0:100}'"
    fi
    ((i++))
done < tests.csv
