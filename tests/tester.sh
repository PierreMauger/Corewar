#!/bin/bash

RED='\e[31m'
GREEN='\e[32m'
WHITE='\e[0m'

for entry in "champion"/*
do
    filename=$(basename -- "$entry")
    extension="${filename##*.}"
    filename="${filename%.*}"

    ./asm/asm champion/$filename.s
    ./tests/asm champion/$filename.s

    if [ $? -ne 0 ]
        then
            echo -e "${RED}Couldn't find binaries${WHITE}"
            exit 1
    fi

    xxd -p $filename.cor > file1
    xxd -p champion/$filename.cor > file2

    if [ $# -eq 1 ]
    then
        if [ $1 == "-a" ]
        then
            diff file1 file2
        else
            diff file1 file2 >/dev/null
        fi
    else
        diff file1 file2 >/dev/null
    fi

    if [ $? -eq 0 ]
        then
            echo -e $filename "-> ${GREEN}Success${WHITE}"
        else
            echo -e $filename "-> ${RED}Failure${WHITE}"
    fi

    rm $filename.cor champion/$filename.cor
    rm file1 file2
done
