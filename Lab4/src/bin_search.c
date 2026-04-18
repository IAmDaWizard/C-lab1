#include "../include/bin_search.h"
#include "../include/create_node.h"
#include <stdio.h>
#include <string.h>

node *bin_search(node *root, char *key) {
    if (root == NULL) {
        printf("Key not found\n");
        return NULL;
    }
    if (strcmp(key, root->key) > 0) return bin_search(root->right, key);
    else if (strcmp(key, root->key) < 0) return bin_search(root->left, key);
    else {
        if (root->left != NULL) printf("\tLeft Child: %f\n", root->left->value);
        if (root->right != NULL) printf("\tRight Child: %f\n", root->right->value);
        return root;
    }
}
