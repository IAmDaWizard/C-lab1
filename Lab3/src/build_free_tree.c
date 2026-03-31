#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/create_node.h"
#include "../include/add.h"

int is_operator(char *token) {
    return strcmp(token, "+") == 0 || strcmp(token, "-") == 0 || strcmp(token, "*") == 0 || strcmp(token, "/") == 0 ||
           strcmp(token, "^") == 0;
}


node *build_tree(char *postfix) {
    if (!postfix) {
        return NULL;
    }
    char *copy = malloc(strlen(postfix) + 1);
    if (!copy) {
        return NULL;
    }
    strcpy(copy, postfix);
    size_t capacity = strlen(postfix) + 1;
    node **stack = malloc(capacity * sizeof(node *));
    if (!stack) {
        free(copy);
        return NULL;
    }
    int top = 0;
    char *token = strtok(copy, " ");
    while (token) {
        if (!is_operator(token)) {
            node *leaf = create_node(token, NULL, NULL);
            if (!leaf) {
                free(stack);
                free(copy);
                return NULL;
            }
            stack[top++] = leaf;
        } else {
            if (top < 2) {
                free(stack);
                free(copy);
                return NULL;
            }
            node *right = stack[--top];
            node *left = stack[--top];
            node *op = create_node(token, left, right);
            if (!op) {
                free(stack);
                free(copy);
                return NULL;
            }
            stack[top++] = op;
        }
        token = strtok(NULL, " ");
    }
    node *root = stack[0];

    free(stack);
    free(copy);

    return root;
}


void free_tree(node *root) {
    //OK
    if (!root) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root->value);
    free(root);
}
