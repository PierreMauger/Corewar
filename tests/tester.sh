#!/bin/bash

RED='\e[31m'
GREEN='\e[32m'
YELLOW='\e[33m'
WHITE='\e[0m'

path="champion*"

echo -e "${GREEN}##############################   TESTS   ##############################${WHITE}"

for entry in $path/*
do
    filename=$(basename -- "$entry")
    extension="${filename##*.}"
    filename="${filename%.*}"

    if [ $extension != "s" ]
    then
        continue
    fi

    ./tests/binaries/asm $path/$filename.s
    mv $filename.cor res_$filename.cor
    ./asm/asm $path/$filename.s

    if [ $? -ne 0 ]
        then
            echo -e "$filename -> ${YELLOW}Couldn't find binaries${WHITE}"
            continue
    fi

    xxd -p res_$filename.cor > file1
    xxd -p $filename.cor > file2

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

    rm res_$filename.cor $filename.cor
    rm file1 file2
done
