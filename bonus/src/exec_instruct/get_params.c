/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** instruct
*/

#include "corewar.h"

static bool is_index(process_t *process)
{
    if (process->id_instruct >= 8 && process->id_instruct <= 14 &&
        process->id_instruct != 12)
        return 1;
    return 0;
}

void get_one_param(vm_t *vm, params_t *params, coord_t coord,
    info_size_t info)
{
    params[info.adv].param = (unsigned int)get_param(vm, coord.x,
        coord.y, info.size_read);
    params[info.adv].type = info.size_read;
}

params_t *get_params(vm_t *vm, process_t *process,
    unsigned char indicator, size_t nbr_args)
{
    params_t *params = create_params(MAX_ARGS_NUMBER);
    coord_t coord = {process->coord_pc.x, process->coord_pc.y +
        T_ID + T_INFO + params[0].type + params[1].type};
    info_size_t info = {0, 0};

    if (!params)
        return NULL;
    for (; info.adv < nbr_args; info.adv++) {
        coord.y = process->coord_pc.y +
        T_ID + T_INFO + params[0].type + params[1].type;
        if (verif_act_param(indicator, info.adv, I_REG))
            info.size_read = T_REG;
        else if (verif_act_param(indicator, info.adv, I_DIR))
            if (is_index(process))
                info.size_read = DIR_SIZE_INDEX;
            else info.size_read = DIR_SIZE;
        else if (verif_act_param(indicator, info.adv, I_IND))
            info.size_read = IND_SIZE;
        get_one_param(vm, params, coord, info);
    }
    return params;
}

size_t get_param(vm_t *vm, size_t x, size_t y, size_t size_to_get)
{
    size_t result = 0;

    for (size_t adv = 0; adv < size_to_get; adv++) {
        if (y >= IDX_MOD) {
            x += (y / IDX_MOD);
            y %= IDX_MOD;
            x %= IDX_NBR;
        }
        result |= GET_ACT_CASE(vm, x, y);
        if (adv + 1 < size_to_get)
            result <<= 8;
        y++;
    }
    return result;
}
