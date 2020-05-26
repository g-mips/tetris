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
    BLOCK_TYPE_T_BLOCK
};

struct block
{
    int color;
    int type;
};

struct block block_generate(void);

#endif // __INCLUDE__BLOCK_H
