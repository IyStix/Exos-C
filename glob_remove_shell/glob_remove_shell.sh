#!/bin/sh

ext=txt
[ $# -ge 1 ] && ext=$1

for file in *."$ext"; do
    if [ -e "$file" ]; then
        rm -- "$file"
    else
        exit 1
    fi
done
