//
// Created by Александр on 3/30/26.
//

#ifndef C_LAB1_ADD_H
#define C_LAB1_ADD_H

#include "node.h"

int is_number_token(char *s);
char *tree_to_string(node *root);
void add_term(int coeff, char *key, int **coeffs, char ***keys, int *count);
void split_term(node *root, int sign, int **coeffs, char ***keys, int *count);
void collect_terms(node *root, int sign, int **coeffs, char ***keys, int *count);
void combine_terms(int *coeffs, char **keys, int *count);
void simplify_and_print(node *root);
void print_result(int *coeffs, char **keys, int count);


#endif //C_LAB1_ADD_H