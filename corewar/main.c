/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** main
*/

#include "corewar.h"

int main(int argc, char **argv)
{
    vm_t *vm = NULL;

    if (argc == 1)
        return 84;
    if (parse_args(argv) == 0)
        bprintf("This is fine\n");
    else {
        bprintf("ERRORED\n");
        return 84;
    }
    vm = create_vm();
    vm->champion_list = store_champ_arguments(argv, vm);
    printf("dump = %ld\n", vm->dump);
    free(vm);
    return 0;
}
