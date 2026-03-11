#!/bin/bash


currentDate=$(date)


echo "Date: ${currentDate}"

filesNum=$(ls | wc -l)

echo "Number of Files: ${filesNum}"
