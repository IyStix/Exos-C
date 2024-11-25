#!/bin/sh

FILENAME="default"
NUMBER=1
EXTENSION="txt"
temp=0

for args in "$@"; do
    case $temp in
        0)
            case $args in
                -f|--filename)
                    temp=1
                    ;;
                -n|--number)
                    temp=2
                    ;;
                -e|--extension)
                    temp=3
                    ;;
                *)
                    exit 1
                    ;;
            esac
            ;;
        1)
            FILENAME=$args
            temp=0
            ;;
        2)
            NUMBER=$args
            temp=0
            ;;
        3)
            EXTENSION=$args
            temp=0
            ;;
    esac
done

for i in $(seq $NUMBER); do
    touch -- "$FILENAME-$i.$EXTENSION"
done
