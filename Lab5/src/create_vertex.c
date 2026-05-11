#include "../include/create_vertex.h"

#include <stdio.h>

#include "../include/matrix.h"
#include <stdlib.h>
#include <string.h>


void create_vertex(matrix *matr, float val) {
    int **tmp = realloc(matr->vertices, (matr->size + 2) * sizeof(int *));
    if (!tmp) {
        return;
    }
    int j = 0;
    for (; j < matr->size + 1; j++) {
        int *tmp_inside = realloc(tmp[j], (matr->size + 2) * sizeof(int));
        if (!tmp_inside) {
            return;
        }
        tmp[j] = tmp_inside;
        tmp[j][matr->size + 1] = 0;
    }
    tmp[matr->size + 1] = calloc(matr->size + 2, sizeof(int));
    if (!tmp[matr->size + 1]) {
        return;
    }
    float *tmp_num = realloc(matr->numbers, (matr->size + 2) * sizeof(float));
    if (!tmp_num) {
        return;
    }
    matr->numbers = tmp_num;
    matr->vertices = tmp;
    matr->numbers[matr->size] = val;
    matr->size++;
    while (1) {
        char *num = NULL;
        size_t len = 0;
        fprintf(stderr, "Which node do you wanna tie up it? Text a value or NO to exit: ");
        ssize_t read = getline(&num, &len, stdin);
        if (read == -1) {
            fprintf(stderr, "Invalid input. Please try again.\n");
            free(num);
            continue;
        }
        num[strcspn(num, "\n")] = '\0';
        if (strcmp(num, "NO") == 0) {
            free(num);
            break;
        }
        char *dir = NULL;
        size_t len_dir = 0;
        fprintf(stderr, "Choose a direction between vertices (new to existing/existing to new/no): ");
        ssize_t s_dir = getline(&dir, &len_dir, stdin);
        dir[strcspn(dir, "\n")] = '\0';
        if (s_dir == -1 || strcmp(dir, "new to existing") * strcmp(dir, "existing to new") * strcmp(dir, "no") != 0) {
            fprintf(stderr, "Invalid input of direction. Please try again.\n");
            free(num);
            free(dir);
            continue;
        }
        char *end = NULL;
        float num_val = strtof(num, &end);
        if (end == num || *end != '\0') {
            fprintf(stderr, "Invalid input. Please try again.\n");
            free(num);
            continue;
        }
        if (strcmp(dir, "no") != 0) {
            int flag = 0;
            int elem = 0; //индекс узла с которым связываем таргет-узел
            for (; elem < matr->size; elem++) {
                if (matr->numbers[elem] == num_val) {
                    if (strcmp(dir, "new to existing") == 0) matr->vertices[matr->size - 1][elem] += 1;
                    else if (strcmp(dir, "existing to new") == 0) matr->vertices[elem][matr->size - 1] += 1;
                    flag++;
                    break;
                }
            }
            if (!flag) {
                fprintf(stderr, "Node not found.\n");
            }
        }
        free(num);
        free(dir);
    }
}
