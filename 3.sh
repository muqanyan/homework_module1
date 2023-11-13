#!/bin/bash

if [ $# -eq 0 ]; then
    echo "Ошибка."
    exit 1
fi
mkdir -p workDir
cd workDir || exit
echo "$1" > message.txt



