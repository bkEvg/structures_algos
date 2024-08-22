#if !defined(TREE_HEADER)
#define TREE_HEADER

#include <stdio.h>
#include <stdlib.h>
struct t_btree {
    int value;
    struct t_btree *left;
    struct t_btree *right;
    struct t_btree *parent;
};

struct t_btree *bstree_create_node(int item, struct t_btree *root);
void bstree_insert(struct t_btree *root, int item, int (*cmp)(int, int));
void test_bstree_insert(void);

void bstree_apply_infix(struct t_btree *root, void (*applyf)(int));
void bstree_apply_prefix(struct t_btree *root, void (*applyf)(int));
void bstree_apply_postfix(struct t_btree *root, void (*applyf)(int));
void bstree_free(struct t_btree *root);

#endif  // TREE_HEADER
