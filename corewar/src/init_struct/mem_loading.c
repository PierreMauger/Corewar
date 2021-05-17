/*
** EPITECH PROJECT, 2021
** mem loading func
** File description:
** mem_loading
*/

#include "corewar.h"

static size_t set_y_axis(char **av, int i, float res)
{
    int temp = 0;
    int index = 0;
    index = get_champ_index(av, i + 1);
    if (index == 0)
        return RETURN_ERROR;
    if (barray_len(av) <= 3)
        return IDX_NBR * res;
    if (bstrcmp("-a", av[index - 2]) == 0) {
        temp = batoi(av[index - 1]);
        if (temp > (IDX_NBR * IDX_MOD))
            return RETURN_ERROR;
        else
            return temp / IDX_NBR;
    }
    else
        return IDX_NBR * res;
}

int init_champs_process(list_t *champs, char **av)
{
    int i = 0;
    float res = 0.f;
    list_node_t *temp = NULL;
    champion_t *champ_cast = NULL;
    process_t *first_process = NULL;

    foreach(champs->head, temp) {
        champ_cast = (champion_t *)temp->data;
        champ_cast->process_list = create_list();
        first_process = create_process(NULL);
        res = ((float)i / (float)champs->lenght);
        first_process->coord_pc.y = set_y_axis(av, i, res);
        if (first_process->coord_pc.y == RETURN_ERROR)
            return RETURN_ERROR;
        first_process->coord_pc.x = 0;
        add_node(champ_cast->process_list, create_node(first_process));
        first_process = NULL;
        i++;
    }
    return EXIT_SUCCESS;
}