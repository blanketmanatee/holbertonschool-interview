#include "binary_trees.h"

/**
 * binary_tree_node - add a node to the binary tree
 * @parent: parent node
 * @value: value to put in new node
 * Return: Ptr to new node or NULL if fail
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value) {
    heap_t *node;

    node = malloc(sizeof(heap_t));
    if (node == NULL)
            return (NULL);

    node->n = value;
    node->parent = parent;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

