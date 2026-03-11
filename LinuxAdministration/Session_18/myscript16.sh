#!/bin/bash

fileName=$1

if [ -f $fileName ]; then
	echo "File exists"
else
	echo "File does not exist"
	exit 1
fi 
if [ -s $fileName ]; then
	echo "File is not empty"
else
	echo "File is empty"
	exit 1
fi
if [ -r $fileName ]; then
	echo "File is readable"
else
	echo "File is not readable"
	exit 1
fi

