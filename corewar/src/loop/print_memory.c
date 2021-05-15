/*
** EPITECH PROJECT, 2021
** utils for args parsing
** File description:
** parsing_utils
*/

#include "corewar.h"

void print_all(vm_t *vm)
{
    char *hex = NULL;

    bprintf("\033c");
    for (size_t x = 0; x < IDX_NBR; x++) {
        for (size_t y = 0; y < IDX_MOD; y++) {
            hex = bitoa_base((int)vm->memory[x][y], HEXA_BASE);
            if (bstrlen(hex) == 1)
                bprintf("0%s ", hex);
            else bprintf("%s ", hex);
            free(hex);
            if ((y + 1) % 32 == 0)
                bprintf("\n");
        }
    }
    bprintf("\n");
}

void print_memory(vm_t *vm)
{
    static size_t it_require = 0;

    if (it_require < vm->dump) {
        it_require++;
        return;
    }
    print_all(vm);
    it_require = 0;
}