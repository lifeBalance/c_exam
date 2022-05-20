#!/usr/bin/env bash

i=1
while IFS="," read -r prog output
do
    if [[ "$(eval "$prog")" -eq "$output" ]]
    then
        printf "%s Test %d: %s -> %s\n" ✅ "$i" "$prog" "$output"
    else
        printf "%s Test %d: %s -> %s\n" ❌ "$i" "$prog" "$output"
    fi
    ((i++))
done < tests.csv
