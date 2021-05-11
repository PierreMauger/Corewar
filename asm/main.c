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
    size_t adv = 0;

    if (argc != 2) {
        bdprintf(2, "Usage: ./asm file_name[.s] ....\n");
        return 84;
    }
    buffer = bread_file(argv[1], READ_SIZE);
    adv = check_asm(buffer);
    if (!adv)
        return 84;
    // write in file
    free(buffer);
    return 0;
}
