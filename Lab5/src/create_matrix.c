#include "../include/create_matrix.h"
#include "../include/matrix.h"
#include <stdio.h>
#include <stdlib.h>

matrix *create_matrix() {
    matrix *Matrix = malloc(sizeof(matrix));
    if (!Matrix) return NULL;
    int **vertices = malloc(sizeof(int *));
    if (!vertices) {
        free(Matrix);
        return NULL;
    }
    int size = 0;
    float *tmp = malloc(sizeof(float));
    if (!tmp) {
        free(Matrix);
        free(vertices);
        return NULL;
    }
    float *numbers = tmp;
    int i = 0;
    for (; i < size + 1; i++) {
        vertices[i] = malloc(sizeof(int));
        vertices[0][0] = 0;
        if (!vertices[i]) {
            int j = 0;
            for (; j < i; j++) free(vertices[j]);
            free(vertices);
            free(Matrix);
            free(numbers);
            return NULL;
        }
    }
    Matrix->vertices = vertices;
    Matrix->numbers = numbers;
    Matrix->size = size;
    return Matrix;
}
