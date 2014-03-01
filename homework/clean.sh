#!/bin/sh

# This script cleans up a specified directory by deleting all files but text files.

# one argument: the directory name that needs to clean up
find $1 -type f -exec file {} \; | grep -v text | cut -d: -f1 | xargs rm

echo "Clean done!"

exit 0