/*
** EPITECH PROJECT, 2021
** asm
** File description:
** main
*/

#include "asm.h"

void display_name_and_arg(char **stock_name, char ***stock_arg)
{
    size_t i = 0;
    size_t z = 0;

    while (stock_arg[i] != NULL) {
        bprintf("%s : ", stock_name[i]);
        while (stock_arg[i][z] != NULL) {
            bprintf("[%s]", stock_arg[i][z]);
            z++;
        }
        bprintf("\n");
        z = 0;
        i++;
    }
}

void display_tr_tab(char ***tab)
{
    size_t i = 0;
    size_t z = 0;

    while (tab[i] != NULL) {
        while (tab[i][z] != NULL) {
            bprintf("[%s]", tab[i][z]);
            z++;
        }
        bprintf("\n");
        z = 0;
        i++;
    }
}

void display_db_tab(char **tab)
{
    size_t i = 0;

    while (tab[i] != NULL) {
        bprintf("%s\n", tab[i]);
        i++;
    }
}

size_t count_line_buff(char *buffer, size_t adv)
{
    size_t count_line = 0;

    while (buffer[adv]) {
        if (buffer[adv] == '\n')
            count_line++;
        adv++;
    }
    return (count_line + 1);
}

int recup_all(char *buffer, size_t adv)
{
    int nb_line = count_line_buff(buffer, adv);
    char **stock_name = malloc(sizeof(char *) * nb_line + 1);
    char ***stock_arg = malloc(sizeof(char **) * nb_line + 1);

    if (check_name_fonc(buffer, adv, stock_name) == -1)
        return (1);
    get_arg(buffer, adv, stock_name, stock_arg);
    display_db_tab(stock_name);
    display_tr_tab(stock_arg);
    display_name_and_arg(stock_name, stock_arg);
    free_double_tab(stock_name);
    free_triple_tab(stock_arg);
    return (0);
}