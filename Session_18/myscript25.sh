#!/bin/bash

x=""

func1(){
	local name=$1
	local age=$2
	x=$(( $name + 6))
	echo "hello ${name} age : ${age}"
	return 0;
}

func1 "mohammed" 25
