#ifndef __INCLUDE__BOARD_H
#define __INCLUDE__BOARD_H

void board_position_current_block(int y, int x);
void board_set_current_block(struct block);
void board_fini(void);
void board_init(void);

#endif // __INCLUDE__BOARD_H
