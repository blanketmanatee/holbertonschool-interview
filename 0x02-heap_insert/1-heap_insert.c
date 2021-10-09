#include "binary_trees.h"

/**
 * heap_insert - inserts a value into a max binary heap
 * @root: double pointer to root node
 * @value: value stored in node to be inserted
 * Return: pointer to new node
 */

heap_t *heap_insert(heap_t **root, int value)
{
heap_t *node;

if (*root == NULL)
{
*root = binary_tree_node(NULL, value);
return (*root);
}
node = insert(*root, value, 0, tree_size(*root) + 1);
while (node->parent && node->n > node->parent->n)
{
node->n = node->parent->n;
node->parent->n = value;
node = node->parent;
}

return (node);
}

/**
 * tree_size - function to find size of the tree
 * @tree: tree
 * Return: size of tree
 */

size_t tree_size(const binary_tree_t *tree)
{
size_t size = 0, right = 0, left = 0;

if (tree == NULL)
{
return (0);
}
else
{
left = tree_size(tree->left);
right = tree_size(tree->right);
size = right + left + 1;
}

return (size);
}

/**
 * insert - inserts node
 * @tree: ptr
 * @value: value of the node
 * @index: index of the node
 * @leaf: node array position
 * Return: node inserted
 */

heap_t *insert(binary_tree_t *tree, int value, int index, int leaf)
{
heap_t *node;

if (tree == NULL)
{
return (NULL);
}
if (index + 1 == leaf / 2)
{
if (leaf & 1)
{
tree->right = binary_tree_node(tree, value);
return (tree->right);
}
else
{
tree->left = binary_tree_node(tree, value);
return (tree->left);
}
}
node = insert(tree->left, value, 2 * index + 1, leaf);
if (node != 0)
{
return (node);
}
else
{
return (insert(tree->right, value, 2 * index + 2, leaf));
}
}
