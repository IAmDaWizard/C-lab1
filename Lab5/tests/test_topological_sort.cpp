#include "test_helpers.h"

extern "C" {
#include "../include/topological_sorting.h"
}

TEST(TopologicalSort, SortsSimpleDag) {
    matrix matr = make_matrix(4);

    matr.numbers[0] = 1.0f;
    matr.numbers[1] = 2.0f;
    matr.numbers[2] = 3.0f;
    matr.numbers[3] = 4.0f;

    matr.vertices[0][2] = 1;
    matr.vertices[1][2] = 1;
    matr.vertices[2][3] = 1;

    int result = topological_sort(&matr);

    EXPECT_EQ(result, 1);

    free_matrix_test(&matr);
}

TEST(TopologicalSort, DetectsCycle) {
    matrix matr = make_matrix(2);

    matr.numbers[0] = 1.0f;
    matr.numbers[1] = 2.0f;

    matr.vertices[0][1] = 1;
    matr.vertices[1][0] = 1;

    int result = topological_sort(&matr);

    EXPECT_EQ(result, 0);

    free_matrix_test(&matr);
}