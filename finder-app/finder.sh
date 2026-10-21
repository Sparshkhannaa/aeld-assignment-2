#!/bin/bash

if [[ -z "$1" || -z "$2" ]]; then
    echo "ERROR: One of the arguments not specified"
    exit 1
fi

if [[ ! -d "$1" ]]; then
    echo "ERROR: Not a valid working directory"
    exit 1
fi

numberOffiles=$(find "$1" -type f | wc -l)
numberOfMatchingLines=$(grep -r -F "$2" "$1" | wc -l)

echo "The number of files are $numberOffiles and the number of matching lines are $numberOfMatchingLines"
