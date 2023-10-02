echo "Enter the size(N) "
read N

sum=0

echo "enter the numbers "
for((i=1;i<=N;i++))
do
	read num
	sum=$(($sum + $num))
done

echo " sum is $sum "
