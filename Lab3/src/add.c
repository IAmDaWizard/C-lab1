#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/create_node.h"


int is_number_token(char *s) {
    //OK
    if (s == NULL || s[0] == '\0') {
        return 0;
    }

    int i = 0;
    if (s[0] == '-') i = 1;
    for (; s[i]; i++) {
        if (!isdigit((unsigned char) s[i])) return 0;
    }
    return 1;
}


char *tree_to_string(node *root) {
    if (!root) {
        return "#";
    }

    if (!root->left && !root->right) {
        char *s = malloc(strlen(root->value) + 1);
        strcpy(s, root->value);
        return s;
    }

    char *left = tree_to_string(root->left);
    char *right = tree_to_string(root->right);

    int len = strlen(left) + strlen(root->value) + strlen(right) + 3;
    char *s = malloc(len);
    sprintf(s, "(%s%s%s)", left, root->value, right);

    free(left);
    free(right);
    return s;
}


void add_term(int coeff, char *key, int **coeffs, char ***keys, int *count) {
    int *new_coeffs = realloc(*coeffs, (*count + 1) * sizeof(int));
    char **new_keys = realloc(*keys, (*count + 1) * sizeof(char *));
    if (!new_coeffs || !new_keys) {
        printf("Memory error\n");
        exit(1);
    }

    *coeffs = new_coeffs;
    *keys = new_keys;

    (*coeffs)[*count] = coeff;
    (*keys)[*count] = key;
    (*count)++;
}

// разобрать один член
void split_term(node *root, int sign, int **coeffs, char ***keys, int *count) {
    // число
    if (!root->left && !root->right && is_number_token(root->value)) {
        add_term(sign * atoi(root->value), strdup("CONST"), coeffs, keys, count);
        return;
    }

    // переменная
    if (!root->left && !root->right && isalpha((unsigned char) root->value[0])) {
        add_term(sign, strdup(root->value), coeffs, keys, count);
        return;
    }

    // число * переменная
    if (strcmp(root->value, "*") == 0) {
        if (root->left && is_number_token(root->left->value) &&
            !root->left->left && !root->left->right) {
            char *key = tree_to_string(root->right);
            add_term(sign * atoi(root->left->value), key, coeffs, keys, count);
            return;
        }

        if (root->right && is_number_token(root->right->value) &&
            !root->right->left && !root->right->right) {
            char *key = tree_to_string(root->left);
            add_term(sign * atoi(root->right->value), key, coeffs, keys, count);
            return;
        }
    }

    char *key = tree_to_string(root);
    add_term(sign, key, coeffs, keys, count);
}

/* собрать все слагаемые */
void collect_terms(node *root, int sign, int **coeffs, char ***keys, int *count) {
    if (!root) return;

    if (strcmp(root->value, "+") == 0) {
        collect_terms(root->left, sign, coeffs, keys, count);
        collect_terms(root->right, sign, coeffs, keys, count);
    } else if (strcmp(root->value, "-") == 0) {
        collect_terms(root->left, sign, coeffs, keys, count);
        collect_terms(root->right, -sign, coeffs, keys, count);
    } else {
        split_term(root, sign, coeffs, keys, count);
    }
}

// объединить одинаковые
void combine_terms(int *coeffs, char **keys, int *count) {
    for (int i = 0; i < *count; i++) {
        if (coeffs[i] == 0) continue;
        for (int j = i + 1; j < *count; j++) {
            if (coeffs[j] == 0) continue;
            if (strcmp(keys[i], keys[j]) == 0) {
                coeffs[i] += coeffs[j];
                coeffs[j] = 0;
            }
        }
    }

    int write = 0;
    for (int i = 0; i < *count; i++) {
        if (coeffs[i] != 0) {
            coeffs[write] = coeffs[i];
            keys[write] = keys[i];
            write++;
        } else {
            free(keys[i]);
        }
    }
    *count = write;
}


void print_result(int *coeffs, char **keys, int count) {
    if (count == 0) {
        printf("0\n");
        return;
    }

    int first = 1;

    for (int i = 0; i < count; i++) {
        int c = coeffs[i];

        if (strcmp(keys[i], "CONST") == 0) {
            if (!first) {
                if (c >= 0) printf("+");
            }
            printf("%d", c);
        } else {
            if (!first) {
                if (c >= 0) printf("+");
            }

            if (c == 1) {
                printf("%s", keys[i]);
            } else if (c == -1) {
                printf("-%s", keys[i]);
            } else {
                printf("%d*%s", c, keys[i]);
            }
        }

        first = 0;
    }

    printf("\n");
}

void simplify_and_print(node *root) {
    int *coeffs = NULL;
    char **keys = NULL;
    int count = 0;

    collect_terms(root, 1, &coeffs, &keys, &count);
    combine_terms(coeffs, keys, &count);
    print_result(coeffs, keys, count);

    for (int i = 0; i < count; i++) {
        free(keys[i]);
    }
    free(keys);
    free(coeffs);
}
