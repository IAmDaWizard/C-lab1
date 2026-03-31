#include <stdio.h>

void test_collect_terms();

void test_split_term();

void test_dijkstra();

void test_build_tree();

void test_combine_terms();

void test_is_number_token();

void test_tree_to_string();

int main() {
    printf("Running tests...\n");

    test_collect_terms();
    printf("collect_terms OK\n");

    test_split_term();
    printf("split_term OK\n");

    test_dijkstra();
    printf("dijkstra OK\n");

    test_build_tree();
    printf("build_tree OK\n");

    test_combine_terms();
    printf("combine_terms OK\n");

    test_tree_to_string();
    printf("tree_to_string OK\n");

    test_is_number_token();
    printf("number_is_toker OK\n");

    printf("All tests passed\n");
    return 0;
}
