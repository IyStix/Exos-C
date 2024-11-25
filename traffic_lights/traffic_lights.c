#include "traffic_lights.h"

void init(unsigned char *lights)
{
    *lights = 0;
}

void turn_on(unsigned char *lights, unsigned char light_num)
{
    unsigned char tamp = 1 << (light_num - 1);
    *lights |= tamp;
}

void turn_off(unsigned char *lights, unsigned char light_num)
{
    unsigned char tamp = ~(1 << (light_num - 1));
    *lights &= tamp;
}
void next_step(unsigned char *lights)
{
    *lights = ((*lights << 1) | (*lights >> 3)) & 0x0F;
}

void reverse(unsigned char *lights)
{
    *lights = (~*lights) & 0x0F;
}

void swap(unsigned char *lights_1, unsigned char *lights_2)
{
    unsigned char temp = *lights_1;
    *lights_1 = *lights_2;
    *lights_2 = temp;
}
