/*
** EPITECH PROJECT, 2021
** bread refacto to stop base on the \0
** File description:
** bread_file_len
*/

#include "blib.h"

static char *create_str(char *str, size_t size)
{
    char *result = bstrndup(str, size);

    if (result) {
        bmemset(result + bstrlen(str), '\0', size + 1 - bstrlen(str));
    }
    free(str);
    return result;
}

static file_t *bloop_read(int fd, char *temp, file_t *buffer, size_t size_read)
{
    int ret = 1;
    int iter = 0;
    int len = size_read;

    do {
        iter++;
        len = (iter * size_read);
        bmemset(temp, '\0', size_read + 1);
        ret = read(fd, temp, size_read);
        buffer->len += ret;
        buffer->file = bstrcat(create_str(buffer->file, len + ret), temp);
        if (!buffer)
            return NULL;
        if (ret == (int)size_read && !temp[ret - 1])
            break;
    } while (ret == (int)size_read);
    buffer->file = buffer;
    return buffer;
}

file_t *bread_file_len(char *path, size_t size_read)
{
    char *temp = malloc(sizeof(char) * (size_read + 1));
    file_t *buffer = create_file(0);
    int fd = open(path, O_RDONLY);

    if (fd == -1 || !temp || !buffer)
        return NULL;
    buffer = bloop_read(fd, temp, buffer, size_read);
    free(temp);
    close(fd);
    return buffer;
}
