#!/bin/bash

RED='\e[31m'
GREEN='\e[32m'
WHITE='\e[0m'

path="*champion"

if [ $# -ne 1 ]
    then
        echo -e "${RED}Argument error${WHITE}"
        exit 1
fi

./tests/binaries/asm $path/$1.s
mv $1.cor res_$1.cor
./asm/asm $path/$1.s

if [ $? -ne 0 ]
    then
        echo -e "${RED}Couldn't find binaries / $1${WHITE}"
        exit 1
fi

xxd -p res_$1.cor > file1
xxd -p $1.cor > file2

diff file1 file2

if [ $? -eq 0 ]
    then
        echo -e $1 "-> ${GREEN}Success${WHITE}"
    else
        echo -e $1 "-> ${RED}Failure${WHITE}"
fi
