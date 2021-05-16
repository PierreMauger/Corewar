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

    for (; buffer[*adv] == ' ' || buffer[*adv] == ','; (*adv)++);
    compt = *adv;
    while (buffer[compt] && buffer[compt] != ' '
        && buffer[compt] != ',' && buffer[compt] != '\n') {
        compt++;
        len++;
    }
    return len;
}

char *get_one_param(char *buffer, size_t *adv, bool *err)
{
    size_t len = get_param_len(buffer, adv);
    size_t fill_tab = 0;
    char *param = NULL;

    if (len == 0)
        *err = true;
    param = malloc(sizeof(char) * (len + 1));
    if (!param)
        return (NULL);
    for (; buffer[*adv] && buffer[*adv] != ' ' && buffer[*adv] != ','
        && buffer[*adv] != '\n'; (*adv)++, fill_tab++) {
        param[fill_tab] = buffer[*adv];
    }
    for (; buffer[*adv] == ' ' && buffer[*adv] == ','; (*adv)++);
    param[fill_tab] = '\0';
    return param;
}

static void check_bool_err(bool *err, char **params_tab, int *i)
{
    if (*err == true) {
        free(params_tab[*i]);
        (*i)--;
        *err = false;
    }
}

char **get_command_params(char *buffer, size_t adv)
{
    char **params_tab = malloc(sizeof(char *) * MAX_ARGS_NUMBER);
    int i = 0;
    bool err = false;

    if (!params_tab)
        return (NULL);
    for (; buffer[adv] && buffer[adv] != '\n'; i++, adv++) {
        params_tab[i] = get_one_param(buffer, &adv, &err);
        if (params_tab[i] == NULL)
            return (NULL);
        check_bool_err(&err, params_tab, &i);
        if (buffer[adv] == '\n') {
            i++;
            break;
        }
    }
    params_tab[i] = NULL;
    return params_tab;
}
