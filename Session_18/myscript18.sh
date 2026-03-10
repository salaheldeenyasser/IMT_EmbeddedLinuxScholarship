#!/bin/bash

for i in 1 2 3 4;do
	echo "$i"
done

for str in Ahmed Mohammed Ali;do
	echo "$str"
done

for file in /temp/*.txt; do
	echo "$file"
done

for user in $(cat /etc/passwd | cut -d : -f1);do
	echo $user
done
