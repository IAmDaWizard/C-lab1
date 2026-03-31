#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/main.h"
#include "../include/create_node.h"
#include "../include/add.h"

void test_collect_terms() {
    int *coeffs = NULL;
    char **keys = NULL;
    int count = 0;

    node *t1 = build_tree("a a +");
    collect_terms(t1, 1, &coeffs, &keys, &count);
    assert(count == 2);
    assert(coeffs[0] == 1 && strcmp(keys[0], "a") == 0);
    assert(coeffs[1] == 1 && strcmp(keys[1], "a") == 0);
    free_tree(t1);

    coeffs = NULL;
    keys = NULL;
    count = 0;
    node *t2 = build_tree("a b -");
    collect_terms(t2, 1, &coeffs, &keys, &count);
    assert(count == 2);
    assert(coeffs[0] == 1 && strcmp(keys[0], "a") == 0);
    assert(coeffs[1] == -1 && strcmp(keys[1], "b") == 0);
    free_tree(t2);

    coeffs = NULL;
    keys = NULL;
    count = 0;
    node *t3 = build_tree("a 2 a * +");
    collect_terms(t3, 1, &coeffs, &keys, &count);
    assert(count == 2);
    assert(coeffs[0] == 1 && strcmp(keys[0], "a") == 0);
    assert(coeffs[1] == 2 && strcmp(keys[1], "a") == 0);
    free_tree(t3);

    coeffs = NULL;
    keys = NULL;
    count = 0;
    node *t4 = build_tree("3 1 x 2 ^ * - 2 x 2 ^ * +");
    collect_terms(t4, 1, &coeffs, &keys, &count);
    assert(count == 3);
    assert(coeffs[0] == 3 && strcmp(keys[0], "CONST") == 0);
    assert(coeffs[1] == -1 && strcmp(keys[1], "(x^2)") == 0);
    assert(coeffs[2] == 2 && strcmp(keys[2], "(x^2)") == 0);
    free_tree(t4);

    coeffs = NULL;
    keys = NULL;
    count = 0;
    node *t5 = build_tree("5 2 -");
    collect_terms(t5, 1, &coeffs, &keys, &count);
    assert(count == 2);
    assert(coeffs[0] == 5 && strcmp(keys[0], "CONST") == 0);
    assert(coeffs[1] == -2 && strcmp(keys[1], "CONST") == 0);
    free_tree(t5);
}
