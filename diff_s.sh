#!/bin/bash
if [ "$#" != 1 ] && [ "$#" != 2 ]; then
    echo "Error : Need filepath (less champion/ && less .s) and -d for delete files create"
    exit
fi
echo =================START=================
./binasm champion/"$1".s
mv "$1".cor file1.cor
./asm/asm champion/"$1".s
mv "$1".cor file2.cor
hexdump -C file1.cor > file1.txt
hexdump -C file2.cor > file2.txt
ret=$(diff file1.txt file2.txt)
if [ "$ret" == "" ]; then
    echo "No difference !"
    else
        echo $ret
fi
if [ "$#" == 2 ] && [ "$2" == "-d" ]; then
    rm file1.txt
    rm file2.txt
    rm file1.cor
    rm file2.cor
    echo "File deleted"
fi
echo =================END===================
exit