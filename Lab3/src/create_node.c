#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *value;
    struct Node *left;
    struct Node *right;
} node;

node *create_node(char *value, node *left, node *right) {
    node *new_node = malloc(sizeof(*new_node));
    if (!new_node) return NULL;

    new_node->value = malloc(strlen(value) + 1);
    if (!new_node->value) {
        free(new_node);
        return NULL;
    }

    strcpy(new_node->value, value);
    new_node->left = left;
    new_node->right = right;
    return new_node;
}
