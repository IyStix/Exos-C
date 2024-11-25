#!/bin/sh
while IFS= read -r line; do
    if echo $line | grep -q "^$"; then
        echo "it is empty"
    elif echo $line | grep -q "^[a-zA-Z]*$"; then
        echo "it is a word"
    elif echo $line | grep -q "^[0-9]$"; then
        echo "it is a digit"
    elif echo $line | grep -q "^[0-9][0-9]*$"; then
        echo "it is a number"
    elif echo $line | grep -q "^[a-zA-Z0-9]*$"; then
        echo "it is an alphanum"
    else
        echo "it is too complicated"
        exit 0
    fi
done
