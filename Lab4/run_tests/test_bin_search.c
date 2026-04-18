#include <assert.h>
#include <string.h>
#include "../include/add_node.h"
#include "../include/bin_search.h"
#include "../include/delete_node.h"

void test_bin_search() {
    node *root = NULL;

    root = add_node(root, "ye", 3.1f);
    root = add_node(root, "left", 1.67f);
    root = add_node(root, "z", 44.4f);
    root = add_node(root, "drake", 11.1f);
    root = add_node(root, "cli", 77.7f);

    node *found_1 = bin_search(root, "ye");
    assert(found_1 != NULL);
    assert(strcmp(found_1->key, "ye") == 0);
    assert(found_1->value == 3.1f);

    node *found_2 = bin_search(root, "drake");
    assert(found_2 != NULL);
    assert(strcmp(found_2->key, "drake") == 0);
    assert(found_2->value == 11.1f);

    node *found_3 = bin_search(root, "cli");
    assert(found_3 != NULL);
    assert(strcmp(found_3->key, "cli") == 0);
    assert(found_3->value == 77.7f);

    node *not_found = bin_search(root, "unknown");
    assert(not_found == NULL);

    root = delete_node(root, "cli");
    root = delete_node(root, "drake");
    root = delete_node(root, "left");
    root = delete_node(root, "z");
    root = delete_node(root, "ye");
}