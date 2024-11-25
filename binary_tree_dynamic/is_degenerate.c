#include <stddef.h>

#include "binary_tree.h"

int is_degenerate(const struct binary_tree *tree)
{
    if (tree == NULL || (tree->left == NULL && tree->right == NULL))
        return 1;
    if (tree->left != NULL && tree->right != NULL)
        return 0;
    return (tree->left != NULL) ? is_degenerate(tree->left)
                                : is_degenerate(tree->right);
}
