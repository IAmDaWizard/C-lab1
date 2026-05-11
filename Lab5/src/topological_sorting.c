#include "../include/topological_sorting.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int topological_sort(matrix *matr) {
    int n = matr->size;

    FILE *file = fopen("topological_sort_result.txt", "w");

    if (!file) {
        fprintf(stderr, "ERROR: cannot open topological_sort_result.txt\n");
        return 0;
    }

    int *in_degree = calloc(n, sizeof(int));
    int *used = calloc(n, sizeof(int));

    if (!in_degree || !used) {
        fprintf(stderr, "ERROR: memory allocation failed\n");
        free(in_degree);
        free(used);
        fclose(file);
        return 0;
    }

    for (int j = 0; j < n; j++) {
        if (isnan(matr->numbers[j])) continue;

        for (int i = 0; i < n; i++) {
            if (!isnan(matr->numbers[i]) && matr->vertices[i][j] != 0) {
                in_degree[j]++;
            }
        }
    }

    int printed = 0;

    fprintf(file, "Topological sort: ");

    while (1) {
        int vertex = -1;

        for (int i = 0; i < n; i++) {
            if (!isnan(matr->numbers[i]) && !used[i] && in_degree[i] == 0) {
                vertex = i;
                break;
            }
        }

        if (vertex == -1) {
            break;
        }

        fprintf(file, "%f ", matr->numbers[vertex]);

        used[vertex] = 1;
        printed++;

        for (int to = 0; to < n; to++) {
            if (!isnan(matr->numbers[to]) && matr->vertices[vertex][to] != 0) {
                in_degree[to]--;
            }
        }
    }

    int vertex_count = 0;

    for (int i = 0; i < n; i++) {
        if (!isnan(matr->numbers[i])) {
            vertex_count++;
        }
    }

    int result = 1;

    if (printed != vertex_count) {
        fprintf(file, "\nERROR: topological sort is impossible, graph has cycle\n");
        result = 0;
    } else {
        fprintf(file, "\n");
    }

    free(in_degree);
    free(used);
    fclose(file);

    printf("Topological sort result was saved to topological_sort_result.txt\n");

    return result;
}