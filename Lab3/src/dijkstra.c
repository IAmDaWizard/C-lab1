#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *dijkstra(char *str, ssize_t len) {
    if (len > 0 && str[len - 1] == '\n') str[len - 1] = '\0';
    int s = 0;
    char *stack = malloc(len * sizeof(char));
    if (!stack) {
        printf("Error allocating memory\n");
        return NULL;
    }
    int i = 0, l = 0;
    char *new_str = malloc(sizeof(char) * (len * 2 + 1));
    if (!new_str) {
        free(stack);
        printf("Error allocating memory\n");
        return NULL;
    }
    new_str[l] = '\0';
    for (; str[i] != '\0' && str[i] != '\n'; i++) {
        if (str[i] == ' ') continue;
        if (isdigit(str[i]) || isalpha(str[i])) {
            if (l == 0 || (i > 0 && isdigit(str[i]) && isdigit(str[i - 1]))) {
                new_str[l] = str[i];
                l++;
            } else {
                new_str[l] = ' ';
                l++;
                new_str[l] = str[i];
                l++;
            }
        } else if (str[i] == '(') {
            stack[s] = str[i];
            s++;
        } else if (s == 0 || stack[s - 1] == '(' ||
                   (((stack[s - 1] == '+' || stack[s - 1] == '-') &&
                     (str[i] == '*' || str[i] == '/' || str[i] == '^')) ||
                    ((stack[s - 1] == '/' || stack[s - 1] == '*') && str[i] == '^') ||
                    (stack[s - 1] != '^' && str[i] == '^'))) {
            stack[s] = str[i];
            s++;
        } else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^') {
            while (s > 0 && stack[s - 1] != '(' &&
                   (((str[i] == '+' || str[i] == '-') &&
                     (stack[s - 1] == '+' || stack[s - 1] == '-' || stack[s - 1] == '*' || stack[s - 1] == '/' || stack[
                          s - 1] == '^')) ||
                    ((str[i] == '*' || str[i] == '/') &&
                     (stack[s - 1] == '*' || stack[s - 1] == '/' || stack[s - 1] == '^')) ||
                    (str[i] == '^' && stack[s - 1] == '^'))) {
                new_str[l] = ' ';
                l++;
                new_str[l] = stack[s - 1];
                l++;
                stack[s - 1] = '\0';
                s--;
            }
            stack[s] = str[i];
            s++;
        } else if (str[i] == ')') {
            while (s > 0 && stack[s - 1] != '(') {
                new_str[l] = ' ';
                l++;
                new_str[l] = stack[s - 1];
                stack[s - 1] = '\0';
                s--;
                l++;
            }
            if (s > 0 && stack[s - 1] == '(') {
                stack[s - 1] = '\0';
                s--;
            }
        } else {
            printf("Non-valid operation in input! ");
            break;
        }
    }
    while (s > 0) {
        new_str[l] = ' ';
        l++;
        new_str[l] = stack[s - 1];
        l++;
        stack[s - 1] = '\0';
        s--;
    }
    new_str[l] = '\0';
    free(stack);
    return new_str;
}