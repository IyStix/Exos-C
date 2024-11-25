#!/bin/sh
[ $# -ne 2 ] && exit 1 ||
{
    if [ -f "$1" ] && [ "$2" -eq "$2" ] 2>/dev/null; then
        N=$(wc -l < "$1")
        if [ "$2" -le "$N" ] && [ "$2" -gt 0 ]; then
            head -n "$2" "$1" | tail -1 | cut -f2-3 -d ';' --output-delimiter=" is "
            exit 0
        else
            exit 1
        fi
    fi
    exit 1
}
