#!/bin/sh

# write compile and execution output(or erros) to this file
outfile="test.out"

# remove old output file if existed
if [ -f "$outfile" ]
then
    rm "$outfile"
fi

# Compile and execute all the exercises
targets=$(cat Makefile | cut -d ":" -f 1 -s | grep -Ev "\.a|\.o")
set $targets
while [ "$1" != "" ]
do
    echo "******************$1**********************" >>"$outfile" 2>&1
    make "$1" >>"$outfile" 2>&1
    ./"$1" >>"$outfile" 2>&1

    shift
done

echo "Test done. Please check $outfile for the output."

exit 0
# echo "$targets"
# echo "test" 1>>"test.out"