#ifndef __BINTREE_H__
#define __BINTREE_H__
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
  int n;
  struct binary_tree_s *parent;
  struct binary_tree_s *left;
  struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;
void bt_preorder(heap_t *tree, heap_t **node, size_t h, size_t level);
size_t bt_height(heap_t *tree);
int heap_extract(heap_t **root);
void binary_tree_print(const binary_tree_t *);

#endif
