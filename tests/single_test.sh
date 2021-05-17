#!/bin/bash

RED='\e[31m'
GREEN='\e[32m'
WHITE='\e[0m'

if [ $# -ne 1 ]
    then
        echo -e "${RED}Argument error${WHITE}"
        exit 1
fi

./asm/asm champion/$1.s
./tests/asm champion/$1.s

if [ $? -ne 0 ]
    then
        echo -e "${RED}Couldn't find binaries / champion${WHITE}"
        exit 1
fi

xxd -p $1.cor > file1
xxd -p champion/$1.cor > file2

diff file1 file2

if [ $? -eq 0 ]
    then
        echo -e $filename "-> ${GREEN}Success${WHITE}"
    else
        echo -e $filename "-> ${RED}Failure${WHITE}"
fi
