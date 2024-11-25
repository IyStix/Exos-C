#include "hash_map.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hash_map *hash_map_init(size_t size)
{
    struct hash_map *map = malloc(sizeof(struct hash_map));
    if (!map)
        return NULL;

    map->data = calloc(size, sizeof(struct pair_list *));
    if (!map->data)
    {
        free(map);
        return NULL;
    }

    map->size = size;
    return map;
}

bool hash_map_insert(struct hash_map *hash_map, const char *key, char *value,
                     bool *updated)
{
    if (!hash_map || !key || !value)
        return false;

    if (hash_map->size == 0)
    {
        return false;
    }

    size_t index = hash(key) % hash_map->size;
    struct pair_list *current = hash_map->data[index];

    while (current)
    {
        if (strcmp(current->key, key) == 0)
        {
            current->value = value;
            if (updated)
                *updated = true;
            return true;
        }
        current = current->next;
    }

    struct pair_list *new_pair = malloc(sizeof(struct pair_list));
    if (!new_pair)
        return false;

    new_pair->key = key;
    new_pair->value = value;
    new_pair->next = hash_map->data[index];
    hash_map->data[index] = new_pair;

    if (updated)
        *updated = false;
    return true;
}

void hash_map_free(struct hash_map *hash_map)
{
    if (!hash_map)
        return;

    for (size_t i = 0; i < hash_map->size; i++)
    {
        struct pair_list *current = hash_map->data[i];
        while (current)
        {
            struct pair_list *next = current->next;
            free(current);
            current = next;
        }
    }

    free(hash_map->data);
    free(hash_map);
}

void hash_map_dump(struct hash_map *hash_map)
{
    if (!hash_map)
        return;

    for (size_t i = 0; i < hash_map->size; i++)
    {
        struct pair_list *current = hash_map->data[i];
        if (current)
        {
            while (current)
            {
                printf("%s: %s", current->key, current->value);
                if (current->next)
                    printf(", ");
                current = current->next;
            }
            printf("\n");
        }
    }
}

const char *hash_map_get(const struct hash_map *hash_map, const char *key)
{
    if (!hash_map || !key || hash_map->size == 0)
        return NULL;

    size_t index = hash(key) % hash_map->size;
    struct pair_list *current = hash_map->data[index];

    while (current)
    {
        if (strcmp(current->key, key) == 0)
            return current->value;
        current = current->next;
    }

    return NULL;
}

bool hash_map_remove(struct hash_map *hash_map, const char *key)
{
    if (!hash_map || !key || hash_map->size == 0)
        return false;

    size_t index = hash(key) % hash_map->size;
    struct pair_list *current = hash_map->data[index];
    struct pair_list *prev = NULL;

    while (current)
    {
        if (strcmp(current->key, key) == 0)
        {
            if (prev)
                prev->next = current->next;
            else
                hash_map->data[index] = current->next;

            free(current);
            return true;
        }
        prev = current;
        current = current->next;
    }

    return false;
}
