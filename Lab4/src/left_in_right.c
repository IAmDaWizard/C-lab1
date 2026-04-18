#include "../include/left_in_right.h"
#include "../include/create_node.h"
#include <stdlib.h>
#include <stdio.h>

node *left_in_right(node *root) {
    root = root->right;
    while (root->left != NULL) { root = root->left; }
    return root;
}
