#!/bin/sh

[ $# -ne 1 ] && exit 1
[ ! -d "$1" ] && exit 1

result=""
for file in "$1"/*.[a-zA-Z][a-zA-Z]; do
    [ -f "$file" ] && result="$result$file "
done

echo "${result% }"
