#!/bin/sh
clang -Wno-everything main.c -o app
chmod 777 ./app
./app