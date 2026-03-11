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


# Java and C style 
for (( i=0; i<10 ; i++ ));do
	echo "$i"
done

# Touch file{1..5}
for i in {1..10};do
	echo $i
done

# Sequence
for i in $(seq 0 2 20 );do
	echo $i
done

counter=1
while [ $counter -le 5 ];do
	echo "$counter"
	((counter++))
done

# Infinite loop
# while true ;do
#         echo "$counter"
#         ((counter++))
# done

while $(line={read -r l}); do
	echo "$line"
done < "/etc/passwd"

