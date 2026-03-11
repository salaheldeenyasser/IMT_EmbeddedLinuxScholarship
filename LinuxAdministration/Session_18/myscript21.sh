#!/bin/bash

fruits=("apple" "banana" "mango")

colors[0]="red"
colors[1]="green"
colors[2]="blue"

echo ${fruits[0]}
echo ${fruits[@]}
echo ${#fruits[@]}

echo ${#colors[0]}
colors+=("yellow")
fruits+=("kiwi" "orange")

colors[1]="black"

unset colors[2]
echo ${colors[2]}

echo ${#colors[@]}

nums=(1 2 3 4 5 6 7)
echo ${nums[@]}
