#include <stdio.h>
#include "../include/create_node.h"
#include "../include/add_node.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>

void test_add_node() {
    char *key = strdup("ye");
    float value = 3.1f;
    node *root = add_node(NULL, key, value);
    assert(
        root->value == 3.1f && strcmp(root->key, "ye") == 0 && root->left == NULL && root->right ==
        NULL && root->height == 1);
    free(key);

    float val_left_1 = 1.67f;
    char *key_left_1 = strdup("left");
    root = add_node(root, key_left_1, val_left_1);
    node *left_child = root->left;

    assert(root->height == 2);

    float val_right_1 = 44.4f;
    char *key_right_1 = strdup("z");
    root = add_node(root, key_right_1, val_right_1);
    node *right_child = root->right;

    assert(left_child->value == 1.67f);
    assert(strcmp(left_child->key, "left")==0);
    assert(left_child -> height == 1);
    assert(left_child->left == NULL && left_child->right == NULL);
    assert(root->height==2);

    assert(right_child->value == 44.4f);
    assert(strcmp(right_child->key, "z")==0);
    assert(right_child -> height == 1);
    assert(right_child->left == NULL && right_child->right == NULL);

    float val_left_2 = 11.1f;
    char *key_left_2 = strdup("drake");

    float val_left_3 = 77.7f;
    char *key_left_3 = strdup("cli");

    root = add_node(root, key_left_2, val_left_2);
    root = add_node(root, key_left_3, val_left_3);
    node *left_child_2 = root->left;
    node *left_child_3 = root->left->left;

    assert(root->height == 3);
    assert(
        root->right == right_child && root->left->right == left_child);
    assert(
        left_child_2->value == 11.1f && left_child->height == 1 && left_child_2->right == left_child && left_child_2->
        left == left_child_3 && strcmp(left_child_2->key, "drake")==0);
    assert(
        left_child_3->value == 77.7f && left_child_3->height == 1 && left_child_3->right == NULL && left_child_3->
        left == NULL && strcmp(left_child_3->key, "cli")==0);
    assert(strcmp(root->left->right->key, "left")==0 && strcmp(root->right->key, "z")==0);
    assert(root->right->height == 1 && root->left->height == 2);
}
