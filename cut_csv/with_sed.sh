#!/bin/sh
[ $# -eq 2 ] && [ -f "$1" ] && [ "$2" -eq "$2" ] 2>/dev/null &&
{
    lines=$(wc -l < "$1")
    [ "$2" -gt 0 ] && [ "$2" -le "$lines" ] &&
    {
        sed "${2}q;d" "$1" | sed -E 's/[^;]*;([^;]*);([^;]*).*/\1 is \2/'
        exit 0
    }
}
exit 1
