#include "../include/add_node.h"
#include "../include/create_node.h"
#include "../include/get_height.h"
#include "../include/balance.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

node *add_node(node *root, char *key, float value) {
    if (root == NULL) {
        node *new_root = create_node(NULL, NULL, key, value);
        return new_root;
    }
    if (strcmp(root->key, key) > 0) {
        root->left = add_node(root->left, key, value);
    } else if (strcmp(root->key, key) < 0) {
        root->right = add_node(root->right, key, value);
    } else if (strcmp(root->key, key) == 0) printf("Key already exists\n");

    root->height = 1 + (get_height(root->left) > get_height(root->right)
                            ? get_height(root->left)
                            : get_height(root->right));
    return balance(root);
}
