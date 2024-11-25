#include <stddef.h>

#include "binary_tree.h"

static int is_complete_helper(const struct binary_tree *tree, int index,
                              int node_count)
{
    if (tree == NULL)
        return 1;
    if (index >= node_count)
        return 0;
    return is_complete_helper(tree->left, 2 * index + 1, node_count)
        && is_complete_helper(tree->right, 2 * index + 2, node_count);
}

int is_complete(const struct binary_tree *tree)
{
    int node_count = size(tree);
    return is_complete_helper(tree, 0, node_count);
}
