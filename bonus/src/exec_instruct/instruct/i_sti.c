/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** instruct
*/

#include "corewar.h"

static bool verif_args(unsigned char indicator)
{
    if (verif_nbr_param(indicator, 3))
        return 1;
    if (!verif_act_param(indicator, 0, I_REG))
        return 1;
    if (!verif_act_param(indicator, 1, I_REG) &&
        !verif_act_param(indicator, 1, I_DIR) &&
        !verif_act_param(indicator, 1, I_IND))
        return 1;
    if (!verif_act_param(indicator, 2, I_DIR) &&
        !verif_act_param(indicator, 2, I_REG))
        return 1;
    return 0;
}

static void exec_sti(vm_t *vm, champion_t *champion, process_t *process,
    params_t *params)
{
    int value_1 = get_value(vm, process, params[0], 1);
    int value_2 = get_value(vm, process, params[1], 1);
    int value_3 = get_value(vm, process, params[2], 1);

    write_int_mem(vm, champion, (coord_t){process->coord_pc.x,
        process->coord_pc.y + (value_2 + value_3) % IDX_MOD}, value_1);
}

static int init_sti(vm_t *vm, champion_t *champion, process_t *process,
    unsigned char indicator)
{
    params_t *params = NULL;
    int size_skip = 0;

    if (verif_args(indicator))
        return T_ID;
    size_skip += T_ID + T_INFO;
    params = get_params(vm, process, indicator, 3);
    if (params == NULL)
        return -1;
    size_skip += params[0].type + params[1].type + params[2].type;
    if (verif_all_params(params)) {
        free(params);
        return size_skip;
    }
    exec_sti(vm, champion, process, params);
    free(params);
    return size_skip;
}

int i_sti(vm_t *vm, champion_t *champion, process_t *process)
{
    unsigned char indicator = (unsigned char)get_param(vm, process->coord_pc.x,
        process->coord_pc.y + T_ID, T_INFO);
    int size_skip = init_sti(vm, champion, process, indicator);

    if (size_skip == -1)
        return 1;
    increase_coord(process, size_skip);
    return 0;
}
