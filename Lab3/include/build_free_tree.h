#ifndef C_LAB1_BUILD_FREE_TREE_H
#define C_LAB1_BUILD_FREE_TREE_H

int is_operator(char *token);

node *build_tree(char *postfix);

void free_tree(node *root);

#endif //C_LAB1_BUILD_FREE_TREE_H
