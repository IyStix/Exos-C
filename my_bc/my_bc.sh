#!/bin/sh

evaluate_expression() {
    echo $(($1))
}

if [ $# -eq 0 ]; then
    while read -r input; do
        [ -z "$input" ] && exit 0
        evaluate_expression "$input"
    done
else
    evaluate_expression "$1"
fi
