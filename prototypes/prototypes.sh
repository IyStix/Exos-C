#!/bin/sh
[ $# -ne 1 ] && exit 1 ||
{
    sed -rn '
        s/^[[:space:]]*//
        s/^([a-zA-Z_][a-zA-Z0-9_]+([ \t*]+|\*+))+[a-zA-Z_][a-zA-Z0-9_]*[ \t]*\([^{;]*\)[ \t]*;?$/&;/p
    ' "$1" | sed 's/[[:space:]]*$//'
}
