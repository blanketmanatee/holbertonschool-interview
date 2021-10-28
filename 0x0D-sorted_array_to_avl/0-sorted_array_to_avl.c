#include "binary_trees.h"

/**
 * new_node - create avl_t node
 * @value: value
 * @parent: parent
 * Return: ptr to new node
 */

avl_t *new_node(int value, avl_t *parent)
{
    avl_t *new = mallow(sizeof(avl_t));

    if (!new)
        return (NULL);
    new->n = value;
    new->left = NULL;
    new->right = NULL;
    new->parent = parent;
    return (new);
}

/**
 * new_tree - tree
 * @parent: parent node
 * @array: array of ints
 * @left: left boundary
 * @right: right bounary
 * Return: ptr to root node
 */

avl_t *new_tree(avl_t *parent, int *array, int left, int right)
{
    avl_t *new;
    int m = (right - left) / 2 + left;

    if (left > right)
        return (NULL);
    new = new_node(array[m], parent);
    if (!new)
        return (NULL);
    new->left = new_tree(new, array, left, m - 1)
    new->right = new_tree(new, array, m + 1, r)
    return (new);
}

/**
 * sorted_array_to_avl - builds an AVL tree from a sorted array
 * @array: ptr to first element in array
 * @size: size of array
 * Return: ptr to root node of avl tree
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
    avl_t *root = NULL;
    int left = 0;
    int r = size - 1;

    root = new_tree(root, array, left, right);
    if (!root)
        return (NULL);
    return (root);
}