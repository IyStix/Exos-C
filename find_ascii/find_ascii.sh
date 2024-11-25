#!/bin/sh

if [ ! -d "$1" ]; then
    echo "Error: $1 is not a valid directory"
    exit 1
fi

ls -1 "$1" | while read -r file; do
    full_path="$1/$file"
    if [ -f "$full_path" ]; then
        file_info=$(file -b "$full_path")
        if echo "$file_info" | grep -q "ASCII text"; then
            echo "$full_path: $file_info"
        fi
    fi
done
