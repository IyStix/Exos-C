#!/bin/sh

[ $# -eq 1 ] || { echo "Sorry, expected 1 argument but $# were passed"; exit 1; }

[ -f "$1" ] && cat "$1" && exit 0

echo "$1:"
echo "	is not a valid file"
exit 2
