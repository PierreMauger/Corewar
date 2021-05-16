/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** main
*/

#include "corewar.h"

void print_usage(void)
{
    bdprintf(STDERR_FILENO, "Bad arguments.\nUSAGE\n");
    bprintf("./corewar [-dump nbr_cycle] [[-n prog_number] ");
    bprintf("[-a load_address] prog_name] ...\n");
}

int main(int argc, char **argv)
{
    int status = 0;
    size_t dump = get_dump(argc, argv);
    list_t *coord = get_info_champion(argv, (bool)dump);
    vm_t *vm = NULL;

    vm = init_all(coord, dump);
    if (vm == NULL)
        status = 84;
    // else status = vm_loop(vm);
    destroy_all(vm);
    return status;
}