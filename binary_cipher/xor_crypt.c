#include <stddef.h>

void my_xor_crypt(void *data, size_t data_len, const void *key, size_t key_len)
{
    char *db = data;
    const char *kb = key;
    for (size_t i = 0; i < data_len; i++)
    {
        db[i] ^= kb[i % key_len];
    }
}
