/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** main
*/

#include "corewar.h"

int main(int argc, char **argv)
{
    int status = 0;
    int champ_count = 0;
    vm_t *vm = NULL;

    if (argc == 1)
        return 84;
    if ((champ_count = parse_champ_args(argv)) == 84) {
        bdprintf(2, "Bad arguments.\nUSAGE\n");
        bprintf("./corewar [-dump nbr_cycle] [[-n prog_number] ");
        bprintf("[-a load_address] prog_name] ...\n");
        return 84;
    }
    vm = create_vm();
    vm->champion_list = store_champ_arguments(argv, vm, champ_count);
    if (vm->champion_list == NULL)
        status = 84;
    if (vm->champion_list)
        destroy_list(vm->champion_list, destroy_champion);
    destroy_vm(vm);
    return status;
}