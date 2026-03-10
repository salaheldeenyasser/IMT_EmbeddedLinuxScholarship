#!/bin/bash


echo "Script Name: $0"
echo "First arg: $1"

echo "Number of Args: $#"
echo "All Args: $@"

ls /tmp

echo "ls Command: $?"

ls /file

echo "ls Command: $?"
