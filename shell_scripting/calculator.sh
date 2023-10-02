#!/bin/bash
echo "CALCULATOR"
flag=1
echo -e "\n1 for addition\n2 for subtraction\n3 for multiplication\n4 for division\n5 for exit"
while [ $flag -eq "1" ]
do
	echo "Enter your choice: "
	read choice
	if [ $choice -ge 5 ]
	then
		break
		
	else
		echo "enter the number1 :"
		read num1
		echo "enter the number2 :"
		read num2
	fi
			
	case $choice in
	1) 
	 echo "sum is $(($num1 +$num2))"
	 ;;
	2)
	 echo "difference is $(($num1 - $num2))"
	 ;;
	3) 
	 echo "product  is $(($num1 * $num2))"
	 ;;
	4)
	 echo "quotient is $(($num1 / $num2))"
	 ;;
	*)
	 echo "invalid choice !"
	 ;;
	 
	esac
	
done
<<com
	CALCULATOR

1 for addition
2 for subtraction
3 for multiplication
4 for division
5 for exit
Enter your choice: 
1
enter the number1 :
15
enter the number2 :
5
sum is 20
Enter your choice: 
2
enter the number1 :
5
enter the number2 :
4
difference is 1
Enter your choice: 
3
enter the number1 :
5
enter the number2 :
1
product  is 5
Enter your choice: 
4
enter the number1 :
10
enter the number2 :
5
quotient is 2
Enter your choice: 
5

com
