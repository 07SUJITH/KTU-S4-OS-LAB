echo "enter the first number :"
read n1
echo "enter the second number :"
read n2
sum=$(expr $n1 + $n2)
echo sum is  $sum

echo "--------------------------"
echo  "addition of three numbers"
echo "enter n1 :"
read n1
echo "enter n2 :"
read n2
echo "enter n3"
read n3

sum3=$(($n1+$n2+$n3))

echo sum of three numbers is $sum3
