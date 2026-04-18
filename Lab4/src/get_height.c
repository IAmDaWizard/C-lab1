#include "../include/get_height.h"
#include "../include/create_node.h"
#include <stdio.h>
#include <stdlib.h>

int get_height(node *root) {
    if (root == NULL) return 0;
    return root->height;
}
