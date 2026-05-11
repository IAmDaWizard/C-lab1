#include <stdio.h>
#include <stdlib.h>
#include "../include/matrix.h"
#include "../include/create_vertex.h"
#include "../include/delete_vertex.h"
#include "../include/print_graph.h"
#include "../include/topological_sorting.h"

void init_matrix(matrix *matr) {
    matr->size = 0;
    matr->vertices = calloc(1, sizeof(int *));
    matr->numbers = calloc(1, sizeof(float));

    if (!matr->vertices || !matr->numbers) {
        fprintf(stderr, "ERROR: memory allocation failed\n");
        exit(1);
    }

    matr->vertices[0] = calloc(1, sizeof(int));

    if (!matr->vertices[0]) {
        fprintf(stderr, "ERROR: memory allocation failed\n");
        exit(1);
    }
}

void free_matrix(matrix *matr) {
    for (int i = 0; i < matr->size + 1; i++) {
        free(matr->vertices[i]);
    }

    free(matr->vertices);
    free(matr->numbers);
}

int main(void) {
    matrix matr;
    init_matrix(&matr);

    int command;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add vertex\n");
        printf("2. Delete vertex\n");
        printf("3. Print graph\n");
        printf("4. Topological sort\n");
        printf("0. Exit\n");
        printf("Choose command: ");

        if (scanf("%d", &command) != 1) {
            fprintf(stderr, "Invalid input\n");
            break;
        }

        if (command == 0) {
            break;
        }

        if (command == 1) {
            float val;
            printf("Enter vertex value: ");

            if (scanf("%f", &val) != 1) {
                fprintf(stderr, "Invalid input\n");
                break;
            }

            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}

            create_vertex(&matr, val);
        } else if (command == 2) {
            float val;
            printf("Enter vertex value to delete: ");

            if (scanf("%f", &val) != 1) {
                fprintf(stderr, "Invalid input\n");
                break;
            }

            delete_vertex(&matr, val);
        } else if (command == 3) {
            print_graph(&matr);
        } else if (command == 4) {
            topological_sort(&matr);
        } else {
            printf("Unknown command\n");
        }
    }

    free_matrix(&matr);
    return 0;
}