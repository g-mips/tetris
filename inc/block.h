#ifndef __INCLUDE__BLOCK_H
#define __INCLUDE__BLOCK_H

enum block_type
{
    BLOCK_TYPE_S_BLOCK,
    BLOCK_TYPE_Z_BLOCK,
    BLOCK_TYPE_L_BLOCK,
    BLOCK_TYPE_J_BLOCK,
    BLOCK_TYPE_SQUARE,
    BLOCK_TYPE_I_BLOCK,
    BLOCK_TYPE_T_BLOCK,

    NUM_BLOCK_TYPES
};
_Static_assert((BLOCK_TYPE_S_BLOCK == 0),
    "Block types have shifted positions."
    " Please reevaluate code");

struct block
{
    unsigned int color;
    unsigned int type;
};

struct block block_generate(void);

#endif // __INCLUDE__BLOCK_H
