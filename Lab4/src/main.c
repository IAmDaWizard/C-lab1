#include <stdio.h>
#include <stdlib.h>
#include "../include/create_node.h"
#include "../include/add_node.h"
#include "../include/bin_search.h"
#include "../include/delete_node.h"
#include "../include/print_tree.h"


int main() {
    node *root = NULL;
    int cmd = 5;
    while (1) {
        printf("Enter what do you wanna do and corresponding values? (add node(1)/delete_node(2)/print_tree(3)/search_node(4)/exit(5)) ");
        int len_cmd = scanf("%d", &cmd);
        if (!len_cmd) {
            printf("Error! Try again bro. \n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            continue;
        }
        if (cmd == 5) return 0;
        if (cmd == 1) {
            char key[99];
            float value = 0;
            int len = scanf("%98s %f", key, &value);
            if (len != 2) {
                printf("Error! Try again bro. \n");
                int c;
                while ((c = getchar()) != '\n' && c != EOF) {
                }
                continue;
            }
            node *new_node = add_node(root, key, value);
            root = new_node;
            printf("Node is created! Key: %s, Value: %f\n", key, value);
        } else if (cmd == 4) {
            char key[99];
            int len = scanf("%98s", key);
            if (len != 1) {
                printf("Error! Try again bro. \n");
                int c;
                while ((c = getchar()) != '\n' && c != EOF) {
                }
                continue;
            }
            node *node = bin_search(root, key);
            if (node == NULL) {
                continue;
            }
            printf("Node found! Key: %s, Value: %f\n", node->key, node->value);
            if (node->left) printf("Left Child: %s\n", node->left->key);
            if (node->right) printf("Right Child: %s\n", node->right->key);
        } else if (cmd == 3) {
            print_tree(root);
        } else if (cmd == 2) {
            if (!root) {
                printf("There's no nodes. \n");
                continue;
            }
            char key[99];
            int len = scanf("%98s", key);
            if (len != 1) {
                printf("Error! Try again bro. \n");
                int c;
                while ((c = getchar()) != '\n' && c != EOF) {
                }
                continue;
            }
            root = delete_node(root, key);
            if (!root) {
                printf("Tree is empty! \n");
                continue;
            }
            printf("Node deleted! New root of tree is: Key: %s, Value: %f\n", root->key, root->value);
            if (root->left) printf("Left Child: %s\n", root->left->key);
            if (root->right) printf("Right Child: %s\n", root->right->key);
        } else printf("Undefined action! Try again! \n");
    }
}
