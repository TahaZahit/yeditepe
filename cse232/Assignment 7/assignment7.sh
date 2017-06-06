#!/bin/bash
file1="$1"
file2="$2"

readarray a < $file1
readarray b < $file2

lena=${#a[@]}
lenb=${#b[@]}

count=0
countmax=0
start=0
stop=0


for (( i=0; i<${lena}; i++ ));
do
        for (( j=0; j<${lenb}; j++ ))
        do
                if [ ${a[i]} == ${b[j]} ]
                then
                        count=0
                        for (( k=0; k<$(( $lena - i ))&&k<$(( $lenb - j )); k++ ))
                        do
                                if [ ${a[i+k]} -eq ${b[j+k]} ]
                                then
                                        count=$(($count+1))
                                        if [ "$count" -gt "$countmax" ]
                                        then
                                                countmax=$count
                                                start=$i
                                                stop=$(($i+$k+1))
                                        fi
                                else
                                        k=$lena
                                fi
                        done
                fi
        done
done


for (( i=$(($stop-$countmax)); i<$stop; i++))
do
        echo ${a[i]}
done