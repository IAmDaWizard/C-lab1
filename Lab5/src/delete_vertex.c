#include "../include/delete_vertex.h"
#include <stdio.h>
#include "../include/matrix.h"
#include <stdlib.h>
#include <math.h>

void delete_vertex(matrix *matr, float num) {
    int k = 0, ind = -1;
    for (; k < matr->size; k++) {
        if (matr->numbers[k] == num) {
            ind = k;
            if (k != matr->size - 1) {
                int j = k;
                for (; j < matr->size - 1; j++) {
                    matr->numbers[j] = matr->numbers[j + 1];
                }
            }
            matr->numbers[matr->size - 1] = NAN;
            break;
        }
    }
    if (ind != -1) {
        free(matr->vertices[ind]);

        for (int t = ind; t < matr->size; t++) {
            matr->vertices[t] = matr->vertices[t + 1];
        }

        for (int r1 = 0; r1 < matr->size; r1++) {
            for (int r2 = ind; r2 < matr->size; r2++) {
                matr->vertices[r1][r2] = matr->vertices[r1][r2 + 1];
            }
            matr->vertices[r1][matr->size] = 0;
        }
        matr->size--;
        return;
    }
    printf("Vertex is not found\n");
}