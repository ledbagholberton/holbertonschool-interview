#ifndef avl_h_
#define avl_h_
#include <stdlib.h>
#include <math.h>

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
typedef struct binary_tree_s avl_t;

avl_t *sorted_array_to_avl(int *array, size_t size);
avl_t *create_avl(avl_t *parent, int *array, size_t ini, size_t end);
void binary_tree_print(const binary_tree_t *tree);
#endif
