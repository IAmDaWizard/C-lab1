#include "../include/create_node.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


node *create_node(node *left, node *right, char *key, float value) {
    node *new_node = malloc(sizeof(node));
    if (!new_node) {
        printf("Allocating memory error");
        return NULL;
    }
    new_node->key = malloc(7 * sizeof(char));
    if (!new_node->key) {
        printf("Allocating memory error");
        return NULL;
    }
    new_node->key = strdup(key);
    new_node->value = value;
    new_node->left = left;
    new_node->right = right;
    new_node->height = 1;
    return new_node;
}
