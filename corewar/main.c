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
    vm_t *vm = NULL;

    if (argc <= 2)
        return 84;

    if (vm == NULL)
        status = 84;
    else status = vm_loop(vm);
    destroy_all(vm);
    return status;
}