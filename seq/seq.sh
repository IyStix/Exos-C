#!/bin/sh

if [ $# -ne 3 ]; then
    echo "Usage: ./seq.sh FIRST INCREMENT LAST" >&2
    exit 1
fi

FIRST=$1
INCREMENT=$2
LAST=$3

if [ "$INCREMENT" -eq 0 ]; then
    exit 1
fi

if [ "$FIRST" -eq "$LAST" ]; then
    echo "$FIRST"
    exit 0
fi

if [ "$FIRST" -lt "$LAST" ]; then
    if [ "$INCREMENT" -le 0 ]; then
        exit 1
    fi
    i=$FIRST
    while [ $i -le $LAST ]; do
        echo $i
        i=$((i + INCREMENT))
    done
elif [ "$FIRST" -gt "$LAST" ]; then
    if [ "$INCREMENT" -ge 0 ]; then
        exit 1
    fi
    i=$FIRST
    while [ $i -ge $LAST ]; do
        echo $i
        i=$((i + INCREMENT))
    done
fi

exit 0
