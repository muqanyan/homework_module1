#!/bin/bash

if [ $# -eq 0 ]; then
    echo "Ошибка: Необходимо передать аргумент."
    exit 1
fi
mkdir -p workDir
cd workDir || exit
echo "$1" > message.txt

echo "Скрипт успешно выполнен. Файл 'message.txt' в директории 'workDir' создан и содержит переданный аргумент."

