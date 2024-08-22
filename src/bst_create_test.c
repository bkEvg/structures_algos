#include <stdio.h>

#include "bst.h"

void test_bstree_create_node() {
    struct t_btree *root = bstree_create_node(10, NULL);
    if (root != NULL && root->value == 10 && root->left == NULL && root->right == NULL &&
        root->parent == NULL) {
        printf("Test 1 SUCCESS.\n");
    } else {
        printf("Test 1 FAIL.\n");
    }

    struct t_btree *child = bstree_create_node(20, root);
    if (child != NULL && child->value == 20 && child->left == NULL && child->right == NULL &&
        child->parent == root) {
        printf("Test 2 SUCCESS.\n");
    } else {
        printf("Test 2 FAIL.\n");
    }

    free(child);
    free(root);
}

int cmp(int a, int b) { return a - b; }

void print_node(int value) { printf("%d ", value); }

void test_bstree_insert(void) {
    struct t_btree *root = bstree_create_node(10, NULL);
    bstree_insert(root, 5, cmp);
    bstree_insert(root, 15, cmp);

    if (root->left != NULL && root->left->value == 5 && root->right != NULL && root->right->value == 15) {
        printf("Test 1 SUCCESS.\n");
    } else {
        printf("Test 1 FAIL.\n");
    }

    bstree_insert(root, 12, cmp);
    bstree_insert(root, 18, cmp);

    if (root->right->left != NULL && root->right->left->value == 12 && root->right->right != NULL &&
        root->right->right->value == 18) {
        printf("Test 2 SUCCESS.\n");
    } else {
        printf("Test 2 FAIL.\n");
    }

    free(root->right->right);
    free(root->right->left);
    free(root->right);
    free(root->left);
    free(root);
}

void test_bstree_traversal() {
    struct t_btree *root = bstree_create_node(10, NULL);
    bstree_insert(root, 5, cmp);
    bstree_insert(root, 15, cmp);
    bstree_insert(root, 12, cmp);
    bstree_insert(root, 18, cmp);

    printf("Infix:");
    bstree_apply_infix(root, print_node);
    printf("\n");

    printf("Prefix:");
    bstree_apply_prefix(root, print_node);
    printf("\n");

    printf("Postfix:");
    bstree_apply_postfix(root, print_node);
    printf("\n");

    bstree_free(root);
}

int main() {
#ifdef QUEST_3
    test_bstree_create_node();
#endif
#ifdef QUEST_4
    test_bstree_insert();
#endif
#ifdef QUEST_5
    test_bstree_traversal();
#endif
    return 0;
}
