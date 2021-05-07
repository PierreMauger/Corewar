/*
** EPITECH PROJECT, 2021
** parsing funcs
** File description:
** parsing
*/

#include "corewar.h"

bool my_str_isnum(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return false;
    }
    return true;
}

static bool check_arg_validity(char **av, int arg_index, char **flags)
{
    bool does_exist = false;

    if (av[arg_index + 1] == NULL)
        return false;
    if (my_str_isnum(av[arg_index + 1]) == false)
        return false;
    for (int i = 0; flags[i] != NULL; i++) {
        if (bstrcmp(av[arg_index], flags[i]) == 0)
            does_exist = true;
    }
    if (does_exist == false)
        return false;
    else
        return true;
}

int parse_args(char **av)
{
    int champ_count = 0;
    bool is_valid = true;
    char **flags = init_checking_flags();

    for (int i = 1; av[i] != NULL; i++) {
        if (av[i][0] == '-')
            is_valid = check_arg_validity(av, i, flags);
        else if (av[i - 1][0] != '-') {
            is_valid = check_read_accessibility(av[i]);
            champ_count++;
        }
        if (is_valid == false)
            return 84;
    }
    bfree_array(flags);
    if (champ_count == 0)
        return 84;
    return 0;
}

int get_arguments_index(char **av, char *str, int iterations)
{
    int count = 0;

    for (int i = 1; av[i] != NULL; i++) {
        if (bstrcmp(av[i], str) == 0)
            count++;
        if (count == iterations)
            return i;
    }
    return 0;
}

list_t *store_champ_arguments(char **av, vm_t *vm)
{
    list_t *champs = create_list();
    champion_t *tempchamp = NULL;
    int temp = 0;

    if ((temp = get_arguments_index(av, "-dump", 1)) != 0)
        vm->dump = batoi(av[temp + 1]);
    
    return champs;
}