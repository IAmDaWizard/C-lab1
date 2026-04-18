#include "../include/delete_node.h"
#include "../include/create_node.h"
#include "../include/get_height.h"
#include "../include/left_in_right.h"
#include "../include/balance.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

node *delete_node(node *root, char *key) {
    if (root == NULL) return NULL;
    if (strcmp(key, root->key) < 0) {
        root->left = delete_node(root->left, key);
    } else if (strcmp(key, root->key) > 0) {
        root->right = delete_node(root->right, key);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root->key);
            free(root);
            return NULL;
        }
        if (root->left == NULL && root->right != NULL) {
            node *tmp = root->right;
            free(root->key);
            free(root);
            return tmp;
        }
        if (root->right == NULL && root->left != NULL) {
            node *tmp = root->left;
            free(root->key);
            free(root);
            return tmp;
        } else {
            node *new_root = left_in_right(root);
            root->value = new_root->value;
            free(root->key);
            root->key = strdup(new_root->key);
            root->right = delete_node(root->right, new_root->key);
        }
    }
    root->height = 1 + (get_height(root->left) > get_height(root->right)
                            ? get_height(root->left)
                            : get_height(root->right));

    return balance(root);
}
