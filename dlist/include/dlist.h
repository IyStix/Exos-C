#ifndef DLIST_H
#define DLIST_H

#include <stddef.h>

struct dlist_item
{
    int data;
    struct dlist_item *next;
    struct dlist_item *prev;
};

struct dlist
{
    size_t size;
    struct dlist_item *head;
    struct dlist_item *tail;
};

struct dlist *dlist_init(void);
size_t dlist_size(const struct dlist *list);
int dlist_push_front(struct dlist *list, int element);
int dlist_push_back(struct dlist *list, int element);
void dlist_print(const struct dlist *list);
int dlist_get(const struct dlist *list, size_t index);
int dlist_insert_at(struct dlist *list, int element, size_t index);
struct dlist_item *dlist_find(const struct dlist *list, int element);
int dlist_pop_front(struct dlist *list);
int dlist_pop_back(struct dlist *list);
int dlist_remove(struct dlist *list, struct dlist_item *to_remove);
void dlist_clear(struct dlist *list);

#endif /* ! DLIST_H */
