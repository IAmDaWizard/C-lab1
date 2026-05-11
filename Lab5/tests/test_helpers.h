#pragma once
#include <gtest/gtest.h>
#include <unistd.h>
#include <fcntl.h>
#include <string>
#include <functional>

extern "C" {
#include "../include/matrix.h"
}

static matrix make_matrix(int size) {
    matrix matr{};
    matr.size = size;
    matr.numbers = static_cast<float *>(calloc(size + 1, sizeof(float)));
    matr.vertices = static_cast<int **>(calloc(size + 1, sizeof(int *)));

    for (int i = 0; i < size + 1; i++) {
        matr.vertices[i] = static_cast<int *>(calloc(size + 1, sizeof(int)));
    }

    return matr;
}

static void free_matrix_test(matrix *matr) {
    for (int i = 0; i < matr->size + 1; i++) {
        free(matr->vertices[i]);
    }

    free(matr->vertices);
    free(matr->numbers);

    matr->vertices = nullptr;
    matr->numbers = nullptr;
    matr->size = 0;
}

static std::string capture_stdout(const std::function<void()> &func) {
    testing::internal::CaptureStdout();
    func();
    return testing::internal::GetCapturedStdout();
}

static void set_stdin_text(const char *text, int *old_stdin_fd) {
    FILE *tmp = tmpfile();
    fputs(text, tmp);
    rewind(tmp);

    *old_stdin_fd = dup(STDIN_FILENO);
    dup2(fileno(tmp), STDIN_FILENO);
}