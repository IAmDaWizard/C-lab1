#include <assert.h>
#include <stdio.h>
#include "../include/add_node.h"
#include "../include/get_height.h"
#include "../include/delete_node.h"

void test_get_height() {
    node *root = NULL;

    assert(get_height(root) == 0);

    root = add_node(root, "ye", 3.1f);
    assert(get_height(root) == 1);

    root = add_node(root, "left", 1.67f);
    assert(get_height(root) == 2);

    root = add_node(root, "z", 44.4f);
    assert(get_height(root) == 2);

    root = add_node(root, "drake", 11.1f);
    assert(get_height(root) == 3);

    root = add_node(root, "cli", 77.7f);
    assert(get_height(root) == 3);

    root = delete_node(root, "cli");
    root = delete_node(root, "drake");
    root = delete_node(root, "left");
    root = delete_node(root, "z");
    root = delete_node(root, "ye");
}