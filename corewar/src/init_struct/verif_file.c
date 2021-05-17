/*
** EPITECH PROJECT, 2021
** utils for args parsing
** File description:
** parsing_utils
*/

#include "corewar.h"

static bool verif_magic(unsigned char *file, size_t len, size_t adv)
{
    int id = 0;

    id = (int)get_n_bytes(adv, file, len, sizeof(COREWAR_EXEC_MAGIC));
    if (id != COREWAR_EXEC_MAGIC)
        return 1;
    return 0;
}

bool verif_file(parsing_t *pars_temp)
{
    unsigned char *file = (unsigned char *)pars_temp->file->file;
    size_t len = pars_temp->file->len;
    size_t adv = 0;
    char *temp = NULL;

    if (len <= sizeof(header_t) || verif_magic(file, len, adv))
        return 1;
    adv += sizeof(COREWAR_EXEC_MAGIC);
    free(pars_temp->name);
    pars_temp->name = bstrndup_forced((char *)(file + adv),
        adv_to_next(adv, file, len) - adv);
    if (!pars_temp->name)
        return 1;
    temp = bstrndup_forced((char *)(file + adv), len - sizeof(header_t));
    free(pars_temp->file->file);
    pars_temp->file->file = temp;
    if (!temp)
        return 1;
    return 0;
}
