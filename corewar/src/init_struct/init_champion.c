/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** main
*/

#include "corewar.h"

static int return_err_check(list_t *champs, int id)
{
    if (is_id_valid(champs, id))
        return id;
    else
        return -1;
}

static int get_champ_id(list_t *champs, char **av, int curr)
{
    int id = 0;
    int index = 0;
    int tempid = 0;

    index = get_champ_index(av, curr);
    for (int i = 0; i < index; i++) {
        tempid = get_arguments_index(av, "-n", i);
        if (tempid != 0 && tempid == index - 2) {
            id = batoi(av[index - 1]);
            return return_err_check(champs, id);
        }
        if (tempid != 0 && tempid == index - 4) {
            id = batoi(av[index - 3]);
            return return_err_check(champs, id);
        }
    }
    id = 1;
    while (!is_id_valid(champs, id))
        id++;
    return id;
}

int create_all_champs(list_t *champs, char **av, int champ_count)
{
    champion_t *tempchamp = NULL;
    int temp = 0;

    for (int i = 1; i <= champ_count; i++) {
        temp = get_champ_id(champs, av, i);
        if (temp == -1) {
            bdprintf(STDERR_FILENO, "ID error, Aborted.\n");
            return 84;
        }
        tempchamp = create_champion(temp, NULL);
        if (!tempchamp)
            return 84;
        add_node(champs, create_node(tempchamp));
        tempchamp = NULL;
    }
    champs->lenght = champ_count;
    init_champs_process(champs, av);
    return 0;
}