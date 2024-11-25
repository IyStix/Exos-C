#ifndef TRIE_H
#define TRIE_H

#define ROOT -1

#include <stdbool.h>

struct trie
{
    // Value of the trie node
    int key;
    // Boolean indicating whether this node is the end of a word
    bool of_interest;
    // First child of the node
    struct trie *first_child;
    // Next sibling of the node
    struct trie *next_sibling;
};

struct trie *create_trie(void);
void add_word(struct trie *trie, const char *word);
bool is_present(const struct trie *trie, const char *word);
bool remove_word(struct trie *trie, const char *word);
void delete_trie(struct trie *trie);
void depth_print(const struct trie *trie);

#endif /* ! TRIE_H */
