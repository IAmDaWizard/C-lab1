#include "../include/turns.h"
#include "../include/create_node.h"
#include "../include/get_height.h"

node *left_left(node *root) {
    node *new_root = root->left;
    node *child = root->left->right;
    new_root->right = root;
    new_root->right->left = child;
    root->height = 1 + (get_height(root->left) > get_height(root->right)
                            ? get_height(root->left)
                            : get_height(root->right));

    new_root->height = 1 + (
                           get_height(new_root->left) > get_height(new_root->right)
                               ? get_height(new_root->left)
                               : get_height(new_root->right)
                       );

    return new_root;
}

node *right_right(node *root) {
    node *new_root = root->right;
    node *child = root->right->left;
    new_root->left = root;
    new_root->left->right = child;
    root->height = 1 + (
                       get_height(root->left) > get_height(root->right)
                           ? get_height(root->left)
                           : get_height(root->right)
                   );

    new_root->height = 1 + (
                           get_height(new_root->left) > get_height(new_root->right)
                               ? get_height(new_root->left)
                               : get_height(new_root->right)
                       );

    return new_root;
}

node *right_left(node *root) {
    root->right = left_left(root->right);
    return right_right(root);
}

node *left_right(node *root) {
    root->left = right_right(root->left);
    return left_left(root);
}
