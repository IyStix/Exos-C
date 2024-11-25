#include <criterion/criterion.h>

#include "fifo.h"

#define CATEGORY Test

TestSuite(CATEGORY, .timeout = 15);

Test(CATEGORY, simple_init)
{
    struct fifo *l = fifo_init();
    cr_expect_eq(l->head, NULL);
    cr_expect_eq(l->tail, NULL);
    cr_expect_eq(l->size, 0);
    free(l);
}

Test(CATEGORY, empty_size)
{
    struct fifo *l = fifo_init();
    cr_expect_eq(fifo_size(l), 0);
    free(l);
}

Test(CATEGORY, simple_push_destroy)
{
    struct fifo *l = fifo_init();
    fifo_push(l, 1);
    cr_expect_eq(l->head->data, 1);
    fifo_destroy(l);
}

Test(CATEGORY, simple_pop)
{
    struct fifo *l = fifo_init();
    fifo_push(l, 1);
    fifo_pop(l);
    cr_expect_eq(l->head, NULL);
    cr_expect_eq(l->tail, NULL);
    cr_expect_eq(l->size, 0);
    free(l);
}

Test(CATEGORY, simple_clear)
{
    struct fifo *l = fifo_init();
    fifo_push(l, 1);
    fifo_push(l, 2);
    fifo_clear(l);
    cr_expect_eq(l->head, NULL);
    cr_expect_eq(l->tail, NULL);
    cr_expect_eq(l->size, 0);
    free(l);
}

int main(int argc, char *argv[])
{
    struct criterion_test_set *tests = criterion_initialize();

    int result = 0;
    if (criterion_handle_args(argc, argv, true))
        result = !criterion_run_all_tests(tests);

    criterion_finalize(tests);
    return result;
}