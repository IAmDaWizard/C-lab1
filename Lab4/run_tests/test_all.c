#include <stdio.h>

void test_add_node();
void test_bin_search();
void test_delete_node();
void test_get_height();
void test_left_in_right();

int main() {
    test_add_node();
    printf("test_add_node passed\n");

    test_bin_search();
    printf("test_bin_search passed\n");

    test_get_height();
    printf("test_get_height passed\n");

    test_left_in_right();
    printf("test_left_in_right passed\n");

    test_delete_node();
    printf("test_delete_node passed\n");

    printf("All tests passed\n");
    return 0;
}