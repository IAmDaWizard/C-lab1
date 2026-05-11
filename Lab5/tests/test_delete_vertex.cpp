#include "test_helpers.h"
#include <cmath>
extern "C" {
#include "../include/delete_vertex.h"
}

TEST(DeleteVertex, DeletesMiddleVertexAndShiftsNumbers) {
    matrix matr = make_matrix(3);

    matr.numbers[0] = 1.0f;
    matr.numbers[1] = 2.0f;
    matr.numbers[2] = 3.0f;

    matr.vertices[0][1] = 1;
    matr.vertices[1][2] = 1;

    delete_vertex(&matr, 2.0f);

    ASSERT_EQ(matr.size, 2);
    EXPECT_FLOAT_EQ(matr.numbers[0], 1.0f);
    EXPECT_FLOAT_EQ(matr.numbers[1], 3.0f);
    EXPECT_TRUE(std::isnan(matr.numbers[2]));

    EXPECT_EQ(matr.vertices[0][0], 0);
    EXPECT_EQ(matr.vertices[0][1], 0);
    EXPECT_EQ(matr.vertices[1][0], 0);
    EXPECT_EQ(matr.vertices[1][1], 0);

    free_matrix_test(&matr);
}

TEST(DeleteVertex, PrintsMessageIfVertexNotFound) {
    matrix matr = make_matrix(2);

    matr.numbers[0] = 10.0f;
    matr.numbers[1] = 20.0f;

    std::string out = capture_stdout([&]() {
        delete_vertex(&matr, 100.0f);
    });

    EXPECT_NE(out.find("Vertex is not found"), std::string::npos);
    EXPECT_EQ(matr.size, 2);

    free_matrix_test(&matr);
}