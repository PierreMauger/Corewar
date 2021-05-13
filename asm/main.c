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
    list_t *list = NULL;

    if (argc != 2) {
        bdprintf(2, "Usage: ./asm file_name[.s] ....\n");
        return 84;
    }
    buffer = bread_file(argv[1], READ_SIZE);
    list = check_asm(buffer);
    if (!list)
        return 84;
    write_asm(argv[1], buffer, list);
    free(buffer);
    destroy_list(list, destroy_command);
    return 0;
}
