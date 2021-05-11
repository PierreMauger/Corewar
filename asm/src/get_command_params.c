/*
** EPITECH PROJECT, 2021
** asm
** File description:
** main
*/

#include "asm.h"

size_t get_param_len(char *buffer, size_t *adv)
{
    size_t compt = 0;
    size_t len = 0;
    size_t count_vir = 0;

    if (buffer[*adv] == ',') {
        (*adv)++;
        count_vir++;
    }
    for (; buffer[*adv] == ' '; (*adv)++);
    if (buffer[*adv] == ',' && count_vir >= 1)
        return (0);
    compt = *adv;
    while (buffer[compt] && buffer[compt] != ' ' && buffer[compt] != '\n') {
        compt++;
        len++;
    }
    return len;
}

char *get_one_param(char *buffer, size_t *adv)
{
    size_t len = get_param_len(buffer, adv);
    size_t fill_tab = 0;
    char *param = NULL;

    if (len == 0)
        return (NULL);
    param = malloc(sizeof(char) * (len + 1));
    if (param == NULL)
        return (NULL);
    for (; buffer[*adv] && buffer[*adv] != ' ' && buffer[*adv] != '\n';
    (*adv)++, fill_tab++) {
        if (buffer[*adv] == ',')
            break;
        param[fill_tab] = buffer[*adv];
    }
    for (; buffer[*adv] == ' '; (*adv)++);
    param[fill_tab] = '\0';
    return param;
}

char **get_command_params(char *buffer, size_t adv)
{
    char **params_tab = malloc(sizeof(char *) * MAX_ARGS_NUMBER);
    int i = 0;

    for (; buffer[adv] && buffer[adv] != '\n'; i++) {
        params_tab[i] = get_one_param(buffer, &adv);
        if (params_tab[i] == NULL)
            return (NULL);
        if (buffer[adv] == '\n') {
            i++;
            break;
        }
    }
    params_tab[i] = NULL;
    return params_tab;
}
