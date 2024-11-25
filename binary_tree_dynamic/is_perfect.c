#include <stddef.h>

#include "binary_tree.h"

static int is_perfect_helper(const struct binary_tree *tree, int depth,
                             int level)
{
    if (tree == NULL)
        return 1;
    if (tree->left == NULL && tree->right == NULL)
        return depth == level + 1;
    if (tree->left == NULL || tree->right == NULL)
        return 0;
    return is_perfect_helper(tree->left, depth, level + 1)
        && is_perfect_helper(tree->right, depth, level + 1);
}

int is_perfect(const struct binary_tree *tree)
{
    int depth = height(tree);
    return is_perfect_helper(tree, depth, -1);
}
