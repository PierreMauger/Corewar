/*
** EPITECH PROJECT, 2021
** asm
** File description:
** main
*/

#include "asm.h"

void write_magic_number(int fd)
{
    char a = 234;
    char b = 131;
    char c = 243;
    char d = 0;

    write(fd, &d, 1);
    write(fd, &a, 1);
    write(fd, &b, 1);
    write(fd, &c, 1);
}

char *get_name(char *buffer, size_t *adv, size_t size)
{
    char *name = bcalloc(sizeof(char), size);
    size_t len = 0;

    if (!name)
        return NULL;
    for (; buffer[*adv - 1] && buffer[*adv - 1] != '"'; (*adv)++);
    for (; buffer[*adv + len] && buffer[*adv + len] != '"'; len++);
    bstrncpy(name, buffer + *adv, len);
    *adv += len + 2;
    return name;
}

void write_header(int fd, char *buffer)
{
    size_t adv = skip_head(buffer);
    char *name = get_name(buffer, &adv, PROG_NAME_LENGTH);
    char *comment = get_name(buffer, &adv, COMMENT_LENGTH);

    if (!name || !comment)
        return;
    write(fd, name, PROG_NAME_LENGTH);
    write(fd, comment, COMMENT_LENGTH);
    free(name);
    free(comment);
}
