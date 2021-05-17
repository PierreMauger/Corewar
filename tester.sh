#!/bin/bash

./asm/asm champion/$1.s
./tests/asm champion/$1.s

xxd -p $1.cor > file1
xxd -p champion/$1.cor > file2

diff file1 file2

if [ $? -eq 0 ]
    then
        echo "Success"
    else
        echo "Failure"
fi

rm $1.cor champion/$1.cor
rm file1 file2
