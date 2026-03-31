#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../include/main.h"
#include "../include/create_node.h"
#include "../include/add.h"

void test_tree_to_string() {
    node *a = create_node("a", NULL, NULL);
    char *s1 = tree_to_string(a);
    assert(strcmp(s1, "a") == 0);
    free(s1);
    free_tree(a);

    node *mul = create_node("*",
                            create_node("2", NULL, NULL),
                            create_node("x", NULL, NULL)
    );
    char *s2 = tree_to_string(mul);
    assert(strcmp(s2, "(2*x)") == 0);
    free(s2);
    free_tree(mul);

    node *pow = create_node("^",
                            create_node("x", NULL, NULL),
                            create_node("2", NULL, NULL)
    );
    char *s3 = tree_to_string(pow);
    assert(strcmp(s3, "(x^2)") == 0);
    free(s3);
    free_tree(pow);

    node *sum = create_node("+",
                            create_node("a", NULL, NULL),
                            create_node("b", NULL, NULL)
    );
    char *s4 = tree_to_string(sum);
    assert(strcmp(s4, "(a+b)") == 0);
    free(s4);
    free_tree(sum);

    node *expr = create_node("*",
                             create_node("+", create_node("a", NULL, NULL), create_node("b", NULL, NULL)),
                             create_node("c", NULL, NULL)
    );
    char *s5 = tree_to_string(expr);
    assert(strcmp(s5, "((a+b)*c)") == 0);
    free(s5);
    free_tree(expr);
}
