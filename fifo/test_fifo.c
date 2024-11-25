#include <stdio.h>
#include <assert.h>
#include "fifo.h"

void test_fifo_init(void);
void test_fifo_push_and_size(void);
void test_fifo_head(void);
void test_fifo_pop(void);
void test_fifo_clear(void);
void test_fifo_print(void);

void test_fifo_init(void) {
    struct fifo *f = fifo_init();
    assert(f != NULL);
    assert(fifo_size(f) == 0);
    fifo_destroy(f);
    printf("test_fifo_init: PASS\n");
}

void test_fifo_push_and_size(void) {
    struct fifo *f = fifo_init();
    fifo_push(f, 1);
    assert(fifo_size(f) == 1);
    fifo_push(f, 2);
    assert(fifo_size(f) == 2);
    fifo_destroy(f);
    printf("test_fifo_push_and_size: PASS\n");
}

void test_fifo_head(void) {
    struct fifo *f = fifo_init();
    fifo_push(f, 10);
    fifo_push(f, 20);
    assert(fifo_head(f) == 10);
    fifo_destroy(f);
    printf("test_fifo_head: PASS\n");
}

void test_fifo_pop(void) {
    struct fifo *f = fifo_init();
    fifo_push(f, 1);
    fifo_push(f, 2);
    fifo_pop(f);
    assert(fifo_size(f) == 1);
    assert(fifo_head(f) == 2);
    fifo_pop(f);
    assert(fifo_size(f) == 0);
    fifo_destroy(f);
    printf("test_fifo_pop: PASS\n");
}

void test_fifo_clear(void) {
    struct fifo *f = fifo_init();
    fifo_push(f, 1);
    fifo_push(f, 2);
    fifo_clear(f);
    assert(fifo_size(f) == 0);
    fifo_destroy(f);
    printf("test_fifo_clear: PASS\n");
}

void test_fifo_print(void) {
    struct fifo *f = fifo_init();
    fifo_push(f, 1);
    fifo_push(f, 2);
    fifo_push(f, 3);
    printf("Expected output:\n1\n2\n3\n");
    printf("Actual output:\n");
    fifo_print(f);
    fifo_destroy(f);
    printf("test_fifo_print: Check visually\n");
}

int main(void) {
    test_fifo_init();
    test_fifo_push_and_size();
    test_fifo_head();
    test_fifo_pop();
    test_fifo_clear();
    test_fifo_print();
    printf("All tests completed.\n");
    return 0;
}
