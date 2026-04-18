#include <assert.h>
#include <string.h>
#include "../include/add_node.h"
#include "../include/left_in_right.h"
#include "../include/delete_node.h"

void test_left_in_right() {
    node *root = NULL;

    root = add_node(root, "m", 1.0f);
    root = add_node(root, "c", 2.0f);
    root = add_node(root, "t", 3.0f);
    root = add_node(root, "p", 4.0f);
    root = add_node(root, "z", 5.0f);
    root = add_node(root, "n", 6.0f);
    node *min_right = left_in_right(root);

    assert(min_right != NULL);
    assert(strcmp(min_right->key, "t") == 0);

    root = delete_node(root, "n");
    root = delete_node(root, "p");
    root = delete_node(root, "z");
    root = delete_node(root, "t");
    root = delete_node(root, "c");
    root = delete_node(root, "m");
}
