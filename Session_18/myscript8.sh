#!/bin/bash

str="Hello, World!"

# num of char
echo ${#str}

# ${str:start}
echo ${str:6}

# ${str:start:length}
echo ${str:0:5}

# ${str/old/new}
echo ${str/World/Bash}

# ${str//old/new}   Replace all matches
echo ${str//l/L}

# Common conversions
echo ${str^^}
echo ${str,,}
