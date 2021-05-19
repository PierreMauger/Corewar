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
    for (; buffer[*adv] && buffer[*adv] != '"'; (*adv)++);
    (*adv)++;
    for (; buffer[*adv + len] && buffer[*adv + len] != '"'; len++);
    bstrncpy(name, buffer + *adv, len);
    *adv += len + 2;
    return name;
}

int get_total_size(list_t *list)
{
    list_node_t *temp = NULL;
    command_t *temp_com = NULL;
    int res = 0;

    foreach(list->head, temp) {
        temp_com = temp->data;
        res++;
        if (barray_len(temp_com->params) != 1 || get_id(temp_com->name) == 15)
            res++;
        for (size_t i = 0; i < barray_len(temp_com->params); i++)
            res += get_size(temp_com, i, list, get_id(temp_com->name));
    }
    return res;
}

void write_header(int fd, char *buffer, list_t *list)
{
    size_t adv = skip_head(buffer);
    header_t *header = bcalloc(1, sizeof(header_t));
    char *name = get_name(buffer, &adv, PROG_NAME_LENGTH + 1);
    char *comment = get_name(buffer, &adv, COMMENT_LENGTH + 1);

    if (!name || !comment || !header)
        return;
    header->magic = swap_endian_4(COREWAR_EXEC_MAGIC);
    bstrcpy(header->prog_name, name);
    header->prog_size = swap_endian_4(get_total_size(list));
    bstrcpy(header->comment, comment);
    write(fd, header, sizeof(header_t));
    free(name);
    free(comment);
    free(header);
}
