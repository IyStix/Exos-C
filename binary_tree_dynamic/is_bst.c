#include <limits.h>
#include <stddef.h>

#include "binary_tree.h"

static int is_bst_helper(const struct binary_tree *tree, int min, int max)
{
    if (tree == NULL)
        return 1;
    if (tree->data < min || tree->data > max)
        return 0;
    return is_bst_helper(tree->left, min, tree->data - 1)
        && is_bst_helper(tree->right, tree->data + 1, max);
}

int is_bst(const struct binary_tree *tree)
{
    return is_bst_helper(tree, INT_MIN, INT_MAX);
}
