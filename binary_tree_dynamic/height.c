#include <stddef.h>

#include "binary_tree.h"

int height(const struct binary_tree *tree)
{
    if (tree == NULL)
        return -1;
    int left_height = height(tree->left);
    int right_height = height(tree->right);
    return 1 + (left_height > right_height ? left_height : right_height);
}
