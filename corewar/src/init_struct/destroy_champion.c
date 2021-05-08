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

    free(champion_cast->name);
}