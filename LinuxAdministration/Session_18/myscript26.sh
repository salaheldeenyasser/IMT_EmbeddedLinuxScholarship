#!/bin/bash

func1(){
	read -p "Enter a number: " x
	return $x;
}

if [ (($x % 2 == 0)) ]; then
	echo "Even"
else
	echo "Odd"
fi


