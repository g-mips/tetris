#include "../../src/block.c"

#include <stddef.h>
#include <stdio.h>
#include <time.h>

#include <check.h>

static int idx_start = 0;
static int idx_end = 0;
static int use_real_rand = 0;
static int rand_expected_ret = 0;

int __real_rand(void);

int __wrap_rand(void)
{
    int rand_ret = 0;
    if (use_real_rand)
    {
        rand_ret = __real_rand();
    }
    else
    {
        rand_ret = rand_expected_ret;
    }

    return(rand_ret);
}

static int create_rand_return(enum block_type b_type, size_t idx)
{
    return(b_type + ((size_t)NUM_BLOCK_TYPES * idx));
}

/******** block_generate TESTS ********/
START_TEST (test_block_generate_BLOCK_TYPE_S_BLOCK)
{
    // Run through different multiples
    for (size_t idx = idx_start; idx < idx_end; ++idx)
    {
        rand_expected_ret = create_rand_return(BLOCK_TYPE_S_BLOCK, idx);
        struct block tetris_blk = block_generate();
        ck_assert_int_eq(tetris_blk.type, BLOCK_TYPE_S_BLOCK);
    }
}
END_TEST

START_TEST (test_block_generate_BLOCK_TYPE_Z_BLOCK)
{
    // Run through different multiples
    for (size_t idx = idx_start; idx < idx_end; ++idx)
    {
        rand_expected_ret = create_rand_return(BLOCK_TYPE_Z_BLOCK, idx);
        struct block tetris_blk = block_generate();
        ck_assert_int_eq(tetris_blk.type, BLOCK_TYPE_Z_BLOCK);
    }
}
END_TEST

START_TEST (test_block_generate_BLOCK_TYPE_L_BLOCK)
{
    // Run through different multiples
    for (size_t idx = idx_start; idx < idx_end; ++idx)
    {
        rand_expected_ret = create_rand_return(BLOCK_TYPE_L_BLOCK, idx);
        struct block tetris_blk = block_generate();
        ck_assert_int_eq(tetris_blk.type, BLOCK_TYPE_L_BLOCK);
    }
}
END_TEST

START_TEST (test_block_generate_BLOCK_TYPE_J_BLOCK)
{
    // Run through different multiples
    for (size_t idx = idx_start; idx < idx_end; ++idx)
    {
        rand_expected_ret = create_rand_return(BLOCK_TYPE_J_BLOCK, idx);
        struct block tetris_blk = block_generate();
        ck_assert_int_eq(tetris_blk.type, BLOCK_TYPE_J_BLOCK);
    }
}
END_TEST

START_TEST (test_block_generate_BLOCK_TYPE_SQUARE)
{
    // Run through different multiples
    for (size_t idx = idx_start; idx < idx_end; ++idx)
    {
        rand_expected_ret = create_rand_return(BLOCK_TYPE_SQUARE, idx);
        struct block tetris_blk = block_generate();
        ck_assert_int_eq(tetris_blk.type, BLOCK_TYPE_SQUARE);
    }
}
END_TEST

START_TEST (test_block_generate_BLOCK_TYPE_I_BLOCK)
{
    // Run through different multiples
    for (size_t idx = idx_start; idx < idx_end; ++idx)
    {
        rand_expected_ret = create_rand_return(BLOCK_TYPE_I_BLOCK, idx);
        struct block tetris_blk = block_generate();
        ck_assert_int_eq(tetris_blk.type, BLOCK_TYPE_I_BLOCK);
    }
}
END_TEST

START_TEST (test_block_generate_BLOCK_TYPE_T_BLOCK)
{
    // Run through different multiples
    for (size_t idx = idx_start; idx < idx_end; ++idx)
    {
        rand_expected_ret = create_rand_return(BLOCK_TYPE_T_BLOCK, idx);
        struct block tetris_blk = block_generate();
        ck_assert_int_eq(tetris_blk.type, BLOCK_TYPE_T_BLOCK);
    }
}
END_TEST

Suite *
test_block_generate_suite(void)
{
    srand(time(NULL));

    int iterations_modifier = (__real_rand() % 150000) + 400000;
    int num_iterations = RAND_MAX / iterations_modifier;

    int done = 0;
    while (!done)
    {
        idx_start = __real_rand();
        if ((idx_start + num_iterations) < (RAND_MAX / NUM_BLOCK_TYPES))
        {
            done = 1;
        }
    }
    idx_end = idx_start + num_iterations;

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
