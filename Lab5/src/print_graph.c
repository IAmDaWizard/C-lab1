#include "../include/print_graph.h"
#include <stdio.h>
#include "../include/matrix.h"
#include <math.h>

void print_graph(matrix *matr) {
    FILE *file = fopen("graph.txt", "w");

    if (!file) {
        fprintf(stderr, "ERROR: cannot open graph.txt\n");
        return;
    }

    for (int ver = 0; ver < matr->size; ver++) {
        if (isnan(matr->numbers[ver])) continue;

        fprintf(file, "Vertex: %f\n", matr->numbers[ver]);

        for (int ch = 0; ch < matr->size; ch++) {
            if (matr->vertices[ver][ch] == 1) {
                fprintf(file, "%f -> %f\n", matr->numbers[ver], matr->numbers[ch]);
            }
            if (matr->vertices[ver][ch] == 2) {
                fprintf(file, "%f <-> %f\n", matr->numbers[ver], matr->numbers[ch]);
            }
        }

        fprintf(file, "\n");
    }

    fclose(file);
    printf("Graph was saved to graph.txt\n");
}