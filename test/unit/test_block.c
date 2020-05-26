#include "../../src/block.c"

#include <stdio.h>

#include <check.h>

enum block_type __real_type_randomizer(void);

static int use_real_randomizer = 0;
static enum block_type type_randomizer_expected_ret = 0;

enum block_type __real_type_randomizer(void)
{
    printf("OKAY\n");
    return BLOCK_TYPE_S_BLOCK;
}

enum block_type __wrap_type_randomizer(void)
{
    printf("WHAT\n");
    enum block_type b_type = 0;
    if (use_real_randomizer)
    {
        
        b_type = __real_type_randomizer();
    }
    else
    {
        b_type = type_randomizer_expected_ret;
    }

    return b_type;
}

/******** block_generate TESTS ********/
START_TEST (test_block_generate_BLOCK_TYPE_S_BLOCK)
{
    type_randomizer_expected_ret = BLOCK_TYPE_S_BLOCK;
    struct block tetris_blk = block_generate();
    ck_assert_int_eq(tetris_blk.type, BLOCK_TYPE_S_BLOCK);
}
END_TEST

START_TEST (test_block_generate_BLOCK_TYPE_Z_BLOCK)
{
    struct block tetris_blk = block_generate();
    ck_assert_int_eq(tetris_blk.type, BLOCK_TYPE_Z_BLOCK);
}
END_TEST

START_TEST (test_block_generate_BLOCK_TYPE_L_BLOCK)
{
    struct block tetris_blk = block_generate();
    ck_assert_int_eq(tetris_blk.type, BLOCK_TYPE_L_BLOCK);
}
END_TEST

START_TEST (test_block_generate_BLOCK_TYPE_J_BLOCK)
{
    struct block tetris_blk = block_generate();
    ck_assert_int_eq(tetris_blk.type, BLOCK_TYPE_J_BLOCK);
}
END_TEST

START_TEST (test_block_generate_BLOCK_TYPE_SQUARE)
{
    struct block tetris_blk = block_generate();
    ck_assert_int_eq(tetris_blk.type, BLOCK_TYPE_SQUARE);
}
END_TEST

START_TEST (test_block_generate_BLOCK_TYPE_I_BLOCK)
{
    struct block tetris_blk = block_generate();
    ck_assert_int_eq(tetris_blk.type, BLOCK_TYPE_I_BLOCK);
}
END_TEST

START_TEST (test_block_generate_BLOCK_TYPE_T_BLOCK)
{
    struct block tetris_blk = block_generate();
    ck_assert_int_eq(tetris_blk.type, BLOCK_TYPE_T_BLOCK);
}
END_TEST

Suite *
test_block_generate_suite(void)
{
    Suite *s = NULL;
    TCase *tc_generate = NULL;

    s = suite_create("Block");

    tc_generate = tcase_create("Generate");

    tcase_add_test(tc_generate, test_block_generate_BLOCK_TYPE_S_BLOCK);
    tcase_add_test(tc_generate, test_block_generate_BLOCK_TYPE_Z_BLOCK);
    tcase_add_test(tc_generate, test_block_generate_BLOCK_TYPE_L_BLOCK);
    tcase_add_test(tc_generate, test_block_generate_BLOCK_TYPE_J_BLOCK);
    tcase_add_test(tc_generate, test_block_generate_BLOCK_TYPE_SQUARE);
    tcase_add_test(tc_generate, test_block_generate_BLOCK_TYPE_I_BLOCK);
    tcase_add_test(tc_generate, test_block_generate_BLOCK_TYPE_T_BLOCK);

    suite_add_tcase(s, tc_generate);

    return s;
}
