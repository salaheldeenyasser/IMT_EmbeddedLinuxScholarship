#!/bin/bash

read -p "choose a number between 1-3" choice

case $choice in
	1)
		echo "Choice 1";;
	2)
		echo "Choice 2";;
	2|3)
		echo "choice 2 or 3";;
	*)
		echo "Wrong choice";;
esac
