#include <stddef.h>

unsigned char rol(unsigned char value, unsigned char roll)
{
    roll = roll % 8;

    for (unsigned char i = 0; i < roll; i++)
    {
        unsigned char x = (value & 0x80) >> 7;
        value = (value << 1) | x;
    }

    return value;
}
