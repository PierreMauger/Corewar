/*
** EPITECH PROJECT, 2021
** include corewar
** File description:
** op
*/

#ifndef _OP_H_
#define _OP_H_

#define MEM_SIZE                (6*1024)
#define IDX_MOD                 512   /* modulo of the index < */
#define IDX_NBR                 12    /* nbr of index < */
#define MAX_ARGS_NUMBER         4     /* this may not be changed 2^*IND_SIZE */

#define COMMENT_CHAR            '#'
#define LABEL_CHAR              ':'
#define DIRECT_CHAR             '%'
#define SEPARATOR_CHAR          ','

#define LABEL_CHARS             "abcdefghijklmnopqrstuvwxyz_0123456789"

#define NAME_CMD_STRING         ".name"
#define COMMENT_CMD_STRING      ".comment"

/* regs */

#define REG_NUMBER     16              /* r1 <--> rx */

/* ** */

typedef char args_type_t;

#define I_REG   0b01000000
#define I_DIR   0b10000000
#define I_IND   0b11000000

#define I_INFO  0b11000000

#define T_ID     1
#define T_INFO   1

#define T_REG    1     /* register */
#define T_DIR    2     /* direct  (ld  #1,r1  put 1 into r1) */
#define T_IND    4     /* indirect always relative */
/* ( ld 1,r1 put what's in the address (1+pc) into r1 (4 bytes )) */

#define T_LAB    8     /* LABEL */

typedef enum {
    I_LIVE = 1,
    I_LD,
    I_ST,
    I_ADD,
    I_SUB,
    I_AND,
    I_OR,
    I_XOR,
    I_ZJMP,
    I_LDI,
    I_STI,
    I_FORK,
    I_LLD,
    I_LLDI,
    I_LFORK,
    I_AFF,
} instruct_e;

typedef struct {
    char         *mnemonique;
    char         nbr_args;
    args_type_t  type[MAX_ARGS_NUMBER];
    char         code;
    int          nbr_cycles;
    char         *comment;
} op_t;

/* size (in bytes) */

#define IND_SIZE    2
#define DIR_SIZE    4
#define REG_SIZE    DIR_SIZE

/* op_tab */
extern op_t op_tab[];

/* header */
#define PROG_NAME_LENGTH  128
#define COMMENT_LENGTH    2048

#define COREWAR_EXEC_MAGIC 0xea83f3

typedef struct {
    int  magic;
    char prog_name[PROG_NAME_LENGTH + 1];
    int  prog_size;
    char comment[COMMENT_LENGTH + 1];
} header_t;

/* live */
#define CYCLE_TO_DIE    1536    /* number of cycle before beig declared dead */
#define CYCLE_DELTA     5
#define NBR_LIVE        40

#endif
