#include <assert.h>
#include <string.h>
#include "../include/add_node.h"
#include "../include/bin_search.h"
#include "../include/delete_node.h"
#include "../include/get_height.h"

void test_delete_node() {
    node *root = NULL;

    root = add_node(root, "ye", 3.1f);
    root = add_node(root, "left", 1.67f);
    root = add_node(root, "z", 44.4f);
    root = add_node(root, "drake", 11.1f);
    root = add_node(root, "cli", 77.7f);

    root = delete_node(root, "cli");
    assert(bin_search(root, "cli") == NULL);

    root = delete_node(root, "left");
    assert(bin_search(root, "left") == NULL);

    root = delete_node(root, "ye");
    assert(bin_search(root, "ye") == NULL);

    assert(bin_search(root, "drake") != NULL);
    assert(bin_search(root, "z") != NULL);

    assert(root != NULL);
    assert(get_height(root) >= 1);

    root = delete_node(root, "drake");
    root = delete_node(root, "z");

    assert(root == NULL);
}
