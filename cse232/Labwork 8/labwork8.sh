#!/bin/bash



count=0
while read line           
do        
    a1[$count]=$line
    count=$(($count + 1))          
done <$1

count=0
while read line           
do        
    a2[$count]=$line
    count=$(($count + 1))          
done <$2



for i in `seq 1 $count`
	do
		echo $((${a1[`expr $i-1`]}*${a2[`expr $i-1`]}))
	done 	


