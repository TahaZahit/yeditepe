#!/bin/bash
if [ $1 = 0 ]; then
	echo "0: Invalid input for number of folders"
else 
for a in `seq 1 $1`; do
	mkdir $a
	pwd > ./$a/myPathFile.txt
done
fi 
