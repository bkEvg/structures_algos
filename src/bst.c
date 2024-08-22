#include "bst.h"

struct t_btree *bstree_create_node(int item, struct t_btree *root) {
    struct t_btree *new_node = (struct t_btree *)(malloc(sizeof(struct t_btree)));
    if (new_node == NULL) {
        return NULL;
    }
    
    new_node->left = new_node->right = NULL;
    new_node->value = item;
    new_node->parent = root;
    return new_node;
}

void bstree_insert(struct t_btree *root, int item, int (*cmp)(int, int)) {
    if (root == NULL) {
        return;
    }

    struct t_btree *current = root;
    struct t_btree *parent = NULL;

    while (current != NULL) {
        parent = current;
        if (cmp(item, current->value) < 0) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (cmp(item, parent->value) < 0) {
        parent->left = bstree_create_node(item, parent);
        printf("ВСТАВИЛ %d СЛЕВА ОТ %d\n", item, parent->value);
    } else {
        parent->right = bstree_create_node(item, parent);
        printf("ВСТАВИЛ %d СПРАВА ОТ %d\n", item, parent->value);
    }
}

void bstree_apply_infix(struct t_btree *root, void (*applyf)(int)) {
    if (root == NULL) {
        return;
    }
    bstree_apply_infix(root->left, applyf);
    applyf(root->value);
    bstree_apply_infix(root->right, applyf);
}

void bstree_apply_prefix(struct t_btree *root, void (*applyf)(int)) {
    if (root == NULL) {
        return;
    }
    applyf(root->value);
    bstree_apply_prefix(root->left, applyf);
    bstree_apply_prefix(root->right, applyf);
}

void bstree_apply_postfix(struct t_btree *root, void (*applyf)(int)) {
    if (root == NULL) {
        return;
    }
    bstree_apply_postfix(root->left, applyf);
    bstree_apply_postfix(root->right, applyf);
    applyf(root->value);
}
void bstree_free(struct t_btree *root) {
    if (root == NULL) {
        return;
    }
    bstree_free(root->left);
    bstree_free(root->right);
    free(root);
}