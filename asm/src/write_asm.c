/*
** EPITECH PROJECT, 2021
** asm
** File description:
** main
*/

#include "asm.h"

static int check_path(char *buffer)
{
    for (int i = 0; buffer[i]; i++)
        if (buffer[i] == '/')
            return 1;
    return 0;
}

char *get_chmp_filename(char *filename)
{
    char *chmp = NULL;
    size_t len = 0;
    size_t adv = 0;

    if (check_path(filename)) {
        for (; filename[adv] && filename[adv] != '/'; adv++);
        adv++;
    }
    chmp = bcalloc(sizeof(char),  bstrlen(filename + adv) + 4);
    if (!chmp)
        return NULL;
    for (; filename[len + adv] && filename[len + adv] != '.'; len++);
    bstrncpy(chmp, filename + adv, len);
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
    write_header(fd, buffer, list);
    write_instructions(fd, list);
    close(fd);
    free(chmp_filename);
}
