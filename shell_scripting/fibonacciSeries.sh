#!/bin/bash
echo "enter the number of terms(n) :"
read n
a=1
b=1
c=0
echo -n "fibonacci series :"
for((i=0;i<n;i++))
do
	echo -n "$c "
	a=$b
	b=$c
	c=$(($a+$b))
done
<<com
enter the number of terms(n) :
5
fibonacci series :0 1 1 2 3 

enter the number of terms(n) :
10
fibonacci series :0 1 1 2 3 5 8 13 21 34 
com

