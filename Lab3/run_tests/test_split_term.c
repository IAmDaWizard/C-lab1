#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/main.h"
#include "../include/create_node.h"
#include "../include/add.h"

void test_split_term() {
    int *coeffs = NULL;
    char **keys = NULL;
    int count = 0;

    node *n1 = create_node("5", NULL, NULL);
    split_term(n1, 1, &coeffs, &keys, &count);
    assert(count == 1);
    assert(coeffs[0] == 5);
    assert(strcmp(keys[0], "CONST") == 0);
    free_tree(n1);

    coeffs = NULL;
    keys = NULL;
    count = 0;
    node *n2 = create_node("a", NULL, NULL);
    split_term(n2, 1, &coeffs, &keys, &count);
    assert(count == 1);
    assert(coeffs[0] == 1);
    assert(strcmp(keys[0], "a") == 0);
    free_tree(n2);

    coeffs = NULL;
    keys = NULL;
    count = 0;
    node *n3 = create_node("*", create_node("2", NULL, NULL), create_node("x", NULL, NULL));
    split_term(n3, 1, &coeffs, &keys, &count);
    assert(count == 1);
    assert(coeffs[0] == 2);
    assert(strcmp(keys[0], "x") == 0);
    free_tree(n3);

    coeffs = NULL;
    keys = NULL;
    count = 0;
    node *n4 = create_node("*", create_node("x", NULL, NULL), create_node("2", NULL, NULL));
    split_term(n4, 1, &coeffs, &keys, &count);
    assert(count == 1);
    assert(coeffs[0] == 2);
    assert(strcmp(keys[0], "x") == 0);
    free_tree(n4);

    coeffs = NULL;
    keys = NULL;
    count = 0;
    node *n5 = create_node("*",
                           create_node("2", NULL, NULL),
                           create_node("^", create_node("x", NULL, NULL), create_node("2", NULL, NULL))
    );
    split_term(n5, 1, &coeffs, &keys, &count);
    assert(count == 1);
    assert(coeffs[0] == 2);
    assert(strcmp(keys[0], "(x^2)") == 0);
    free_tree(n5);
}


