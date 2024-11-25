#include "vector.h"

#include <stdio.h>
#include <stdlib.h>

struct vector *vector_init(size_t n)
{
    struct vector *v = malloc(sizeof(struct vector));
    if (!v)
        return NULL;

    v->data = calloc(n, sizeof(int));
    if (!v->data)
    {
        free(v);
        return NULL;
    }

    v->size = 0;
    v->capacity = n;
    return v;
}

void vector_destroy(struct vector *v)
{
    if (v)
    {
        free(v->data);
        free(v);
    }
}

struct vector *vector_resize(struct vector *v, size_t n)
{
    if (!v)
        return NULL;

    int *new_data = realloc(v->data, n * sizeof(int));
    if (!new_data)
        return NULL;

    v->data = new_data;
    v->capacity = n;
    if (v->size > n)
        v->size = n;

    return v;
}

struct vector *vector_append(struct vector *v, int elt)
{
    if (!v)
        return NULL;

    if (v->size == v->capacity)
    {
        size_t new_capacity = v->capacity * 2;
        if (!vector_resize(v, new_capacity))
            return NULL;
    }

    v->data[v->size++] = elt;
    return v;
}

void vector_print(const struct vector *v)
{
    if (!v || v->size == 0)
    {
        printf("\n");
        return;
    }

    for (size_t i = 0; i < v->size - 1; i++)
        printf("%d,", v->data[i]);
    printf("%d\n", v->data[v->size - 1]);
}

struct vector *vector_reset(struct vector *v, size_t n)
{
    if (!v)
        return NULL;

    free(v->data);
    v->data = calloc(n, sizeof(int));
    if (!v->data)
        return NULL;

    v->size = 0;
    v->capacity = n;
    return v;
}

struct vector *vector_insert(struct vector *v, size_t i, int elt)
{
    if (!v || i > v->size)
        return NULL;

    if (v->size == v->capacity)
    {
        size_t new_capacity = v->capacity * 2;
        if (!vector_resize(v, new_capacity))
            return NULL;
    }

    for (size_t j = v->size; j > i; j--)
        v->data[j] = v->data[j - 1];

    v->data[i] = elt;
    v->size++;
    return v;
}

struct vector *vector_remove(struct vector *v, size_t i)
{
    if (!v || i >= v->size)
        return NULL;

    for (size_t j = i; j < v->size - 1; j++)
        v->data[j] = v->data[j + 1];

    v->size--;

    if (v->size < v->capacity / 2)
    {
        size_t new_capacity = v->capacity / 2;
        if (!vector_resize(v, new_capacity))
            return NULL;
    }

    return v;
}
