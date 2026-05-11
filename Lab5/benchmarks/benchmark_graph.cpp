#include <benchmark/benchmark.h>
#include <cstdlib>
#include <cmath>

extern "C" {
#include "../include/matrix.h"
#include "../include/delete_vertex.h"
#include "../include/topological_sorting.h"
}

static matrix make_matrix(int size) {
    matrix matr{};
    matr.size = size;

    matr.numbers = static_cast<float *>(calloc(size + 1, sizeof(float)));
    matr.vertices = static_cast<int **>(calloc(size + 1, sizeof(int *)));

    for (int i = 0; i < size + 1; i++) {
        matr.vertices[i] = static_cast<int *>(calloc(size + 1, sizeof(int)));
    }

    for (int i = 0; i < size; i++) {
        matr.numbers[i] = static_cast<float>(i + 1);
    }

    return matr;
}

static void free_matrix_bench(matrix *matr) {
    for (int i = 0; i < matr->size + 1; i++) {
        free(matr->vertices[i]);
    }

    free(matr->vertices);
    free(matr->numbers);

    matr->vertices = nullptr;
    matr->numbers = nullptr;
    matr->size = 0;
}

static void fill_dag(matrix *matr) {
    for (int i = 0; i < matr->size; i++) {
        for (int j = i + 1; j < matr->size; j++) {
            if ((i + j) % 5 == 0) {
                matr->vertices[i][j] = 1;
            }
        }
    }
}

static void BM_DeleteVertex(benchmark::State &state) {
    int n = static_cast<int>(state.range(0));

    for (auto _: state) {
        matrix matr = make_matrix(n);
        fill_dag(&matr);

        delete_vertex(&matr, static_cast<float>(n / 2 + 1));

        benchmark::DoNotOptimize(matr.size);

        free_matrix_bench(&matr);
    }
}

static void BM_TopologicalSort(benchmark::State &state) {
    int n = static_cast<int>(state.range(0));

    for (auto _: state) {
        matrix matr = make_matrix(n);
        fill_dag(&matr);

        int result = topological_sort(&matr);
        benchmark::DoNotOptimize(result);

        benchmark::DoNotOptimize(matr.size);

        free_matrix_bench(&matr);
    }
}

BENCHMARK(BM_DeleteVertex)->Arg(10)->Arg(50)->Arg(100)->Arg(300)->Arg(500);
BENCHMARK(BM_TopologicalSort)->Arg(10)->Arg(50)->Arg(100)->Arg(300)->Arg(500);

BENCHMARK_MAIN();
