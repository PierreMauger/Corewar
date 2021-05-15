/*
** EPITECH PROJECT, 2021
** asm
** File description:
** main
*/

#include "asm.h"

char *get_chmp_filename(char *filename)
{
    char *chmp = bcalloc(sizeof(char),  bstrlen(filename) + 4);
    size_t len = 0;

    if (!chmp)
        return NULL;
    for (; filename[len] && filename[len] != '.'; len++);
    bstrncpy(chmp, filename, len);
    bstrcat(chmp, ".cor");
    return chmp;
}

void write_asm(char *filename, char *buffer, list_t *list)
{
    int fd = 0;
    char *chmp_filename = get_chmp_filename(filename);

    if (!chmp_filename)
        return;
    fd = open(chmp_filename, O_CREAT | O_WRONLY, 0644);
    if (fd == -1)
        return;
    write_magic_number(fd);
    write_header(fd, buffer);
    write_instructions(fd, list);
    close(fd);
    free(chmp_filename);
}
