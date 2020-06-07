#include <stdlib.h>

#include <check.h>

#include "test_block.h"

SRunner *
setup_runner(void)
{
    SRunner *sr = srunner_create(test_block_generate_suite());
    return sr;
}

int
run(SRunner *sr)
{
    srunner_run_all(sr, CK_VERBOSE);
    return srunner_ntests_failed(sr);
}

int
main(void)
{
    srand(time(NULL));

    SRunner *sr = setup_runner();
    int number_failed = run(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
