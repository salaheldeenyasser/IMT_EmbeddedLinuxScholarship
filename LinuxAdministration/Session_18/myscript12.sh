#!/bin/bash


read -p "please enter the first Number: " x
read -p "please enter the second Number: " y


if [ $x -lt 0 ] || [ $y -lt 0 ]; then
    echo "Negative numbers are not allowed"
    exit 1
else
    echo "Multiplied= $((x*y))"

    echo "Summed= $((x+y))"

    echo "Subtracted= $((x-y))"

    echo "Divided= $((x/y))"

    echo "Powered= $((x**y)) "
fi




