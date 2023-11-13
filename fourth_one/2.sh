#!/bin/bash


read -p "Enter an integer N: " N
read -p "Enter a text: " Text


for ((i=1; i<=$N; i++)); do
    echo "$Text $i" > "file_$i.txt"
done

