/*
** EPITECH PROJECT, 2021
** mem loading func
** File description:
** mem_loading
*/

#include "corewar.h"

void init_champs_process(list_t *champs, char **av)
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
        first_process->coord_pc.x = (IDX_NBR * IDX_MOD) * res;
        first_process->coord_pc.y = 0;
        bprintf("LOAD_ADRESS:%d\n", first_process->coord_pc.x);
        add_node(champ_cast->process_list, create_node(first_process));
        first_process = NULL;
        i++;
    }
}