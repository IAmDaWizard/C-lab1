//
// Created by Александр on 3/30/26.
//

#ifndef C_LAB1_MAIN_H
#define C_LAB1_MAIN_H

#include "node.h"


int is_operator(char *token);

node *build_tree(char *postfix);

void free_tree(node *root);

int main();

#endif //C_LAB1_MAIN_H
