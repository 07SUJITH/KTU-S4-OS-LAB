
# using while loop to find the sum  of n numbers 

echo "SUM OF N NUMBERS "
echo 
echo
echo "enter the size "
read n 

i=1
sum=0

echo "Enter the numbers"
while [ $i -le $n ]
do
	read num  #get number
	sum=$((sum + num)) #sum+=sum
	i=$((i + 1))
done

echo " sum of the given  $n numbers is = $sum "
