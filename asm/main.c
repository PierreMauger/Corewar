/*
** EPITECH PROJECT, 2021
** asm
** File description:
** main
*/

#include "asm.h"

int main(int argc, char **argv)
{
    char *buffer = NULL;

    if (argc != 2)
        return 84;
    buffer = bread_file(argv[1], READ_SIZE);
    if (!buffer)
        return 84;
    return 0;
}
