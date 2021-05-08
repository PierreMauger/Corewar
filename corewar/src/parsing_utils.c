/*
** EPITECH PROJECT, 2021
** utils for args parsing
** File description:
** parsing_utils
*/

#include "corewar.h"

bool check_read_accessibility(char *str)
{
    char *temp = NULL;

    if ((temp = bread_file(str, 20)) == NULL)
        return false;
    else {
        free(temp);
        return true;
    }
}

char **init_checking_flags(void)
{
    char **flags = binit_array_light(4);

    flags[0] = bstrdup("-dump");
    flags[1] = bstrdup("-n");
    flags[2] = bstrdup("-a");
    flags[3] = NULL;
    return flags;
}

bool is_id_valid(list_t *champs, int curr)
{
    list_node_t *temp = NULL;
    champion_t *data = NULL;

    foreach(champs, temp) {
        data = (champion_t *)temp->data;
        if (data->id == curr)
            return false;
    }
    return true;
}

int get_champ_index(char **av, int iterations)
{
    int count = 0;

    for (int i = 1; av[i] != NULL; i++) {
        if (av[i][0] != '-')
            count++;
        if (count == iterations)
            return i;
    }
    return 0;
}