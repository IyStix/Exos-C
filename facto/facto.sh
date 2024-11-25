#!/bin/sh

if [ $# -ne 1 ]; then
    exit 1
fi

n=$1

case $n in
    ''|*[!0-9]*) exit 1 ;;
esac

result=1
i=1
while [ $i -le $n ]; do
    result=$(( result * i ))
    i=$(( i + 1 ))
done

echo $result

exit 0
