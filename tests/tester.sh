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

    ./tests/binaries/asm $path/$filename.s 2> /dev/null
    err1=$?
    if [ $err1 != 84 ]
    then
        mv $filename.cor res_$filename.cor
    fi
    ./asm/asm $path/$filename.s
    err2=$?

    if [ $err1 == 84 ]
    then
        if [ $err1 == $err2 ]
        then
            echo -e $filename "-> ${GREEN}Success${WHITE}"
        else
            echo -e $filename "-> ${RED}Failure${WHITE}"
        fi
        continue
    fi


    if [ $err2 -ne 0 ]
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
