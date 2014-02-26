#!/bin/sh

for file in *
do
    if [ -d "$file" ]
    then 
	rm $file/*.o
	rm $file/*.a
	continue
    fi

    case "$file" in
	*.sh | *.c | *.h | *.txt | *Makefile | *makefile ) continue;;
	* ) rm "$file";;
    esac
done

exit 0