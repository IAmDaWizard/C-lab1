#include "../include/print_tree.h"
#include "../include/create_node.h"
#include <stdio.h>

void print_tree(node *root) {
    if (root == NULL) return;
    print_tree(root->left);
    printf("Key: %s, Value: %f, Height: %d\n", root->key, root->value, root->height);
    if (root->left != NULL) {
        printf("\tLeft Child: %f\n", root->left->value);
    }
    if (root->right != NULL) {
        printf("\tRight Child: %f\n", root->right->value);
    }
    print_tree(root->right);
}
