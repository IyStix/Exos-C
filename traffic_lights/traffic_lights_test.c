#include <stdio.h>
#include <assert.h>
#include "traffic_lights.h"

#define TEST(name) printf("Testing %s... ", name)
#define PASS printf("PASSED\n")

void test_init(void) {
    TEST("init");
    unsigned char lights = 0xFF;
    init(&lights);
    assert(lights == 0x00);
    PASS;
}

void test_turn_on(void) {
    TEST("turn_on");
    unsigned char lights = 0x00;
    turn_on(&lights, 0);
    assert(lights == 0x01);
    turn_on(&lights, 2);
    assert(lights == 0x05);
    turn_on(&lights, 1);
    turn_on(&lights, 3);
    assert(lights == 0x0F);
    PASS;
}

void test_turn_off(void) {
    TEST("turn_off");
    unsigned char lights = 0x0F;  // All lights on
    turn_off(&lights, 1);
    assert(lights == 0x0D);
    turn_off(&lights, 3);
    assert(lights == 0x05);
    turn_off(&lights, 0);
    turn_off(&lights, 2);
    assert(lights == 0x00);  // All lights should be off
    PASS;
}

void test_next_step(void) {
    TEST("next_step");
    unsigned char lights = 0x01;
    next_step(&lights);
    assert(lights == 0x02);
    next_step(&lights);
    assert(lights == 0x04);
    next_step(&lights);
    assert(lights == 0x08);
    next_step(&lights);
    assert(lights == 0x01);
    PASS;
}

void test_reverse(void) {
    TEST("reverse");
    unsigned char lights = 0x05;
    reverse(&lights);
    assert(lights == 0x0A);
    reverse(&lights);
    assert(lights == 0x05);
    PASS;
}

void test_swap(void) {
    TEST("swap");
    unsigned char lights1 = 0x05, lights2 = 0x0A;
    swap(&lights1, &lights2);
    assert(lights1 == 0x0A && lights2 == 0x05);
    PASS;
}

int main(void) {
    test_init();
    test_turn_on();
    test_turn_off();
    test_next_step();
    test_reverse();
    test_swap();
    printf("All tests passed successfully!\n");
    return 0;
}
