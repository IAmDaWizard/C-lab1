#include "test_helpers.h"
#include <fstream>
#include <string>
#include <cstdio>

extern "C" {
#include "../include/print_graph.h"
}

static std::string read_file(const char *filename) {
    std::ifstream file(filename);
    std::string content;
    std::string line;

    while (std::getline(file, line)) {
        content += line + "\n";
    }

    return content;
}

TEST(PrintGraph, WritesDirectedEdgesToFile) {
    matrix matr = make_matrix(3);

    matr.numbers[0] = 1.0f;
    matr.numbers[1] = 2.0f;
    matr.numbers[2] = 3.0f;

    matr.vertices[0][1] = 1;
    matr.vertices[1][2] = 1;

    print_graph(&matr);

    std::string out = read_file("graph.txt");

    EXPECT_NE(out.find("Vertex: 1.000000"), std::string::npos);
    EXPECT_NE(out.find("1.000000 -> 2.000000"), std::string::npos);
    EXPECT_NE(out.find("2.000000 -> 3.000000"), std::string::npos);

    std::remove("graph.txt");
    free_matrix_test(&matr);
}

TEST(PrintGraph, DoesNotWriteDeletedVertexToFile) {
    matrix matr = make_matrix(2);

    matr.numbers[0] = NAN;
    matr.numbers[1] = 5.0f;

    print_graph(&matr);

    std::string out = read_file("graph.txt");

    EXPECT_EQ(out.find("Vertex: nan"), std::string::npos);
    EXPECT_NE(out.find("Vertex: 5.000000"), std::string::npos);

    std::remove("graph.txt");
    free_matrix_test(&matr);
}