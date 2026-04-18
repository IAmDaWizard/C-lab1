#include "../include/balance.h"
#include "../include/turns.h"
#include "../include/get_height.h"
#include <stdio.h>

node *balance(node *root) {
    if (root == NULL) return root;
    int left_height = get_height(root->left);
    int right_height = get_height(root->right);
    node *new_node = NULL;
    if (right_height - left_height > 1) {
        if (get_height(root->right->left) > get_height(root->right->right)) {
            new_node = right_left(root);
        } else {
            new_node = right_right(root);
        }
    } else if (left_height - right_height > 1) {
        if (get_height(root->left->right) > get_height(root->left->left)) {
            new_node = left_right(root);
        } else {
            new_node = left_left(root);
        }
    } else return root;
    return new_node;
}
