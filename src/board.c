#include <string.h>

#include "block.h"

#include "board.h"

struct position
{
    int x;
    int y;
};

static struct position current_block_pos = { 0 };
static struct block current_block = { 0 };

/*
 * board_position_current_block:
 *     Takes in new position coordinates and updates the current block's
 *   internal positions.
 */
void
board_position_current_block(int y, int x)
{
    current_block_pos.y = y;
    current_block_pos.x = x;
}

/*
 * board_set_current_block:
 *     Sets the current block to the new block given
 */
void
board_set_current_block(struct block new_block)
{
    memcpy(&current_block, &new_block, sizeof(new_block));
}

void
board_fini(void)
{

}

/*
 * board_init:
 *     Initializes the board
 */
void
board_init(void)
{

}
