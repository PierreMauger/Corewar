/*
** EPITECH PROJECT, 2021
** asm
** File description:
** main
*/

#include "asm.h"

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

char *get_chmp_filename(char *filename)
{
    char *chmp = malloc(sizeof(char) * bstrlen(filename) + 2);
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
    //write_magic_number
    write_header(fd, buffer);
    //write_code
    close(fd);
}
