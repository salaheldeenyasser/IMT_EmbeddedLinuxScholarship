#!/bin/bash

read -p "Enter file or directory path" path 

if [ -f $path ];then
	echo "File exists"
elif [ -d $path ];then
	echo "Directory exists"
fi
