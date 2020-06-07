#include <stdlib.h>

#include "block.h"

static inline enum block_type type_randomizer(void);

// The order matches the block_type enumeration
static unsigned int const block_colors[] = {
    0x008000, // Green
    0xFF0000, // Red
    0xFFA500, // Orange
    0x0000FF, // Blue
    0xFFFF00, // Yellow
    0x00FFFF, // Cyan
    0x800080 // Purple
};
_Static_assert(
    ((sizeof(block_colors) / sizeof(block_colors[0])) == NUM_BLOCK_TYPES),
    "Size of block_colors must equal the number of blocks");

static inline enum block_type
type_randomizer(void)
{
    return(rand() % NUM_BLOCK_TYPES);
}

/*
 * block_generate
 *     Generates a random block from the block_type enumeration.
 *  The color for the block is based on what the block type is.
 *
 *  Returns this block.
 */
struct block
block_generate(void)
{
    struct block blk = { .color = 0, .type = type_randomizer() };

    // Just for security, but it should never not get through this if statement
    if (blk.type < sizeof(block_colors))
    {
        blk.color = block_colors[blk.type];
    }

    return(blk);
}

/*
 * block_get_color
 *    Returns the color of the block type given.
 *
 *    Will return 0xFFFFFF if not a valid block_type
 */
unsigned int
block_get_color(enum block_type b_type)
{
    if (b_type >= NUM_BLOCK_TYPES || b_type < BLOCK_TYPE_S_BLOCK)
    {
        return 0xFFFFFF;
    }

    return block_colors[b_type];
}
