#!/bin/bash
echo -n "Enter a number :"
read number

duplicate=$number
reverse=0

while [ $number -ne 0 ]
do
	remainder=$(($number%10))
	reverse=$(echo "$reverse*10 + $remainder" | bc)
	number=$(( $number/10 ))
done

if [ $reverse -ne $duplicate ]
then
	echo "number  is not palindrome"
else
	echo "number is palindrome "
fi
<<com

Enter a number :121
number is palindrome 

Enter a number :125
number  is not palindrome

Enter a number :1551
number is palindrome 
com
