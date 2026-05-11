#include "test_helpers.h"

extern "C" {
#include "../include/create_vertex.h"
}

TEST(CreateVertex, AddsVertexWithoutEdges) {
    matrix matr = make_matrix(0);

    int old_stdin_fd;
    set_stdin_text("NO\n", &old_stdin_fd);

    create_vertex(&matr, 10.0f);

    dup2(old_stdin_fd, STDIN_FILENO);
    close(old_stdin_fd);

    ASSERT_EQ(matr.size, 1);
    EXPECT_FLOAT_EQ(matr.numbers[0], 10.0f);
    EXPECT_EQ(matr.vertices[0][0], 0);

    free_matrix_test(&matr);
}

TEST(CreateVertex, AddsDirectedEdgeFromNewToExisting) {
    matrix matr = make_matrix(1);

    matr.numbers[0] = 5.0f;

    int old_stdin_fd;
    set_stdin_text("5\nnew to existing\nNO\n", &old_stdin_fd);

    create_vertex(&matr, 10.0f);

    dup2(old_stdin_fd, STDIN_FILENO);
    close(old_stdin_fd);

    ASSERT_EQ(matr.size, 2);
    EXPECT_FLOAT_EQ(matr.numbers[0], 5.0f);
    EXPECT_FLOAT_EQ(matr.numbers[1], 10.0f);

    EXPECT_EQ(matr.vertices[1][0], 1);
    EXPECT_EQ(matr.vertices[0][1], 0);

    free_matrix_test(&matr);
}