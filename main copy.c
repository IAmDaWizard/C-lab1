#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} node;

node *add(int value, node *root) {
    node *n = NULL;
    node *tmp = malloc(sizeof(node));
    if (!tmp) {
        free(tmp);
        printf("Ошибка! \n");
        return NULL;
    }
    n = tmp;
    n->value = value;
    n->left = NULL;
    n->right = NULL;
    if (root == NULL) { return n; }
    node *cur = root;
    while (1) {
        if (value < cur->value) {
            if (cur->left == NULL) {
                cur->left = n;
                break;
            }
            cur = cur->left;
        } else if (value > cur->value) {
            if (cur->right == NULL) {
                cur->right = n;
                break;
            }
            cur = cur->right;
        } else {
            printf("Узел с таким значением уже имеется. \n");
            free(n);
            return NULL;
        }
    }
    return n;
}


void delete(int value, node **root, int val) {
    if (value == val) {
        printf("Нельзя удалить корень дерева. \n");
        return;
    }
    node **link = root;
    int ptr = 0;
    if (*root == NULL) return;
    while (1) {
        if (value < (*link)->value) {
            if ((*link)->left == NULL) {
                printf("Нe существует такого узла");
                break;
            }
            link = &((*link)->left);
            ptr = 0;
            continue;
        } else if (value > (*link)->value) {
            if ((*link)->right == NULL) {
                printf("Нe существует такого узла");
                break;
            }
            link = &((*link)->right);
            ptr = 1;
            continue;
        }
        if ((*link)->left == NULL && (*link)->right == NULL) {
            if (ptr == 0) {
                node *v = *link;
                *link = NULL;
                free(v);
                break;
            } else {
                node *v = *link;
                *link = NULL;
                free(v);
                break;
            }
        } else if ((*link)->left != NULL && (*link)->right == NULL) {
            node *v = *link;
            *link = ((*link)->left);
            free(v);
            break;
        } else if ((*link)->right != NULL && (*link)->left == NULL) {
            node *v = *link;
            *link = ((*link)->right);
            free((v));
            break;
        } else {
            delete((*link)->left->value, &(*link)->left, val);
            delete((*link)->right->value, &(*link)->right, val);
            node *v = *link;
            *link = NULL;
            free((v));
        }
        break;
    }
    return;
}

void traversal_lkp(node *root) {
    if (root == NULL) return;
    traversal_lkp(root->left);
    printf("%d\n", root->value);
    traversal_lkp(root->right);
}


void traversal_lpk(node *root) {
    if (root == NULL) return;
    traversal_lpk(root->left);
    traversal_lpk(root->right);
    printf("%d\n", root->value);
}

void traversal_klp(node *root) {
    if (root == NULL) return;
    printf("%d\n", root->value);
    traversal_klp(root->left);
    traversal_klp(root->right);
}

int best_val = 0, max_depth = -1;

void mdv(node *root, int depth) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) return;
    if (root->left != NULL || root->right != NULL) {
        if (depth > max_depth) {
            best_val = root->value;
            max_depth = depth;
        }
    }
    mdv(root->left, depth + 1);
    mdv(root->right, depth + 1);
}


int main(void) {
    char str[10];
    int value, val;
    scanf("%d", &val);
    node *root = add(val, NULL);
    while (1) {
        if (scanf("%9s", str) != 1) {
            printf("Ошибка.");
            break;
        } else if (strcmp(str, "add") == 0) {
            scanf("%d", &value);
            add(value, root);
        } else if (strcmp(str, "delete") == 0) {
            scanf("%d", &value);
            delete(value, &root, val);
        } else if (strcmp(str, "traversal") == 0) {
            scanf("%s", str);
            if (strcmp(str, "ЛКП") == 0) {
                traversal_lkp(root);
            } else if (strcmp(str, "КЛП") == 0) {
                traversal_klp(root);
            } else if (strcmp(str, "ЛПК") == 0) {
                traversal_lpk(root);
            } else printf("Не существует такого обхода. Выберите из списка ЛКП, КЛП, ЛПК. \n");
        } else if (strcmp(str, "mdv") == 0) {
            mdv(root, 0);
            printf("%d\n", best_val);
        } else if (strcmp(str, "exit") == 0) break;
        else printf("Не существует такого метода. \n");
    }
    return 0;
}
