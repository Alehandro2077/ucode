#!/bin/zsh

ls  -lsh "$1" | awk '(NR>1){print $10,$6}'

