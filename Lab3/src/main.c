#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/dijkstra.h"
#include "../include/add.h"
#include "../include/build_free_tree.h"


int main() {
    size_t count = 0;
    char *str = NULL;
    fprintf(stderr, "Введите выражение: ");
    ssize_t len = getline(&str, &count, stdin);
    if (len == -1) {
        printf("Строка выражений не записалась! ");
        free(str);
        return 0;
    }
    char *new_s = dijkstra(str, len);
    if (!new_s) {
        free(str);
        return 0;
    }


    node *root = build_tree(new_s);
    if (!root) {
        printf("Tree build failed\n");
        free(new_s);
        free(str);
        return 0;
    }
    printf("Postfix: %s\n", new_s);
    printf("Result: ");
    simplify_and_print(root);

    free_tree(root);
    free(new_s);
    free(str);
}
