#ifndef C_LAB1_CREATE_NODE_H
#define C_LAB1_CREATE_NODE_H


typedef struct Node {
    char *key;
    float value;
    struct Node *left;
    struct Node *right;
    int height;
} node;

node *create_node(node *left, node *right, char *key, float value);



#endif //C_LAB1_CREATE_NODE_H