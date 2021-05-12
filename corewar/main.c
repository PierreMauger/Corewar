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
    int champ_count = 0;
    vm_t *vm = NULL;

    if (argc == 1)
        return 84;
    champ_count = parse_champ_args(argv);
    if (champ_count == -1) {
        print_usage();
        return 84;
    }
    vm = init_vm(champ_count, argv);
    if (vm == NULL)
        status = 84;
    destroy_all(vm);
    return status;
}