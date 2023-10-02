#!/bin/bash
echo "Enter a number "
read num

case $num in
0)
  echo zero
   ;;
1)
  echo one
  ;;
2)
  echo two
  ;;  
3)
  echo three
   ;;
4)
  echo four
  ;;
5)
  echo  five
  ;;
*)
  echo "number is greater than 5"
  ;;
esac

