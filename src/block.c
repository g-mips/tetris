#include <stdlib.h>

#include "block.h"

static enum block_type
type_randomizer(void)
{
    return(rand() % NUM_BLOCK_TYPES);
}

struct block
block_generate(void)
{
    struct block blk = { .color = 0, .type = type_randomizer() };
    return(blk);
}
