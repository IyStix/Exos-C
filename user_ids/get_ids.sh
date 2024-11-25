#!/bin/sh

cut -d':' -f3 /etc/passwd | sort -rnu
