/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** main
*/

#include "corewar.h"

void destroy_champion(void *champion)
{
    champion_t *champion_cast = (champion_t *)champion;

    if (champion_cast->process_list)
        destroy_list(champion_cast->process_list, NULL);
    free(champion_cast->name);
}