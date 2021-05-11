/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** main
*/

#include "corewar.h"

champion_t *create_champion(size_t id, char *name)
{
    champion_t *result = bcalloc(sizeof(champion_t), 1);

    result->id = id;
    result->name = name;
    return result;
}

static int get_champ_id(list_t *champs, char **av, int curr)
{
    
}

int create_all_champs(list_t *champs, char **av, int champ_count)
{
    champion_t *tempchamp = NULL;
    size_t curr = 1;
    int temp = 0;

    for (int i = 0; i != champ_count; i++) {
        if ((temp = get_arguments_index(av, "-n", i + 1)) != 0) // WORK HERE
            temp = batoi(av[temp + 1]);
        else {
            temp = curr;
            curr++;
        }
        if (is_id_valid(champs, curr) == false) {
            destroy_list(champs, destroy_champion);
            return 84;
        }
        tempchamp = create_champion(temp, NULL);
        add_node(champs, create_node(tempchamp));
        tempchamp = NULL;
    }
    return 0;
}