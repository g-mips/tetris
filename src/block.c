#include "block.h"

enum block_type
type_randomizer(void)
{
    return(-1);
}

struct block
block_generate(void)
{
    struct block blk = { .color = 0, .type = type_randomizer() };
    return(blk);
}
