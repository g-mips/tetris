#include "../../src/board.c"

#include <check.h>

#include "test_board.h"

START_TEST (test_board_set_current_block_success)
{
    struct block new_block = {
        .color = 0xFF00FF,
        .type = 0x00FF0D
    };

    board_set_current_block(new_block);

    ck_assert_mem_eq(&new_block, &current_block, sizeof(struct block));
}
END_TEST

Suite *
test_board_suite(void)
{
    Suite *s = suite_create("Board");

    TCase *tc_set_current_block = tcase_create("Set Current Block");

    tcase_add_test(tc_set_current_block, test_board_set_current_block_success);

    suite_add_tcase(s, tc_set_current_block);

    return s;
}
