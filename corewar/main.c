/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** main
*/

#include "corewar.h"

int main(int argc, char **argv)
{
    if (parse_args(argv) == 0)
        bprintf("This is fine\n");
    else {
        bprintf("ERRORED\n");
        return 84;
    }
    return 0;
}
