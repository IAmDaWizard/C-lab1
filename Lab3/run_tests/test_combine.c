#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../include/add.h"


void test_combine_terms() {
    int count = 3;
    int *coeffs = malloc(3 * sizeof(int));
    char **keys = malloc(3 * sizeof(char *));
    coeffs[0] = 1;
    keys[0] = strdup("a");
    coeffs[1] = 2;
    keys[1] = strdup("a");
    coeffs[2] = 5;
    keys[2] = strdup("CONST");

    combine_terms(coeffs, keys, &count);
    assert(count == 2);
    assert(coeffs[0] == 3);
    assert(strcmp(keys[0], "a") == 0);
    assert(coeffs[1] == 5);
    assert(strcmp(keys[1], "CONST") == 0);


    count = 3;
    coeffs = malloc(3 * sizeof(int));
    keys = malloc(3 * sizeof(char *));
    coeffs[0] = 1;
    keys[0] = strdup("b");
    coeffs[1] = -1;
    keys[1] = strdup("b");
    coeffs[2] = 7;
    keys[2] = strdup("CONST");

    combine_terms(coeffs, keys, &count);
    assert(count == 1);
    assert(coeffs[0] == 7);
    assert(strcmp(keys[0], "CONST") == 0);
}
