#!/bin/bash
echo -n "enter a number : "
read number

flag=1
if [ $number  -lt 2 ]
then 
	flag=0
else
for((i=2;i<=number/2;i++))
do
	if [ $((number%i)) -eq 0 ]
	then
		flag=0
		break
	fi
done
fi

if [ $flag -eq 1 ]
then
	echo " $number is prime "
else
	echo " $number is not prime "
fi
<<com 
enter a number : 5
 5 is prime 

enter a number : 1
 1 is not prime 

enter a number : 10
 10 is not prime 

enter a number : 2
 2 is prime 

com
