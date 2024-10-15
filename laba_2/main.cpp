#include <iostream>
#include <random>
#include <set>
#include <fmt/color.h>

constexpr int MAX_SIZE = 20;
const fmt::text_style AQUA_COLOR = fg(fmt::color::aqua);
const fmt::text_style INDIAN_RED_COLOR = fg(fmt::color::indian_red);

char CharRandomGenerator();

size_t NumberCount(char** matrix, int rows, int cols) {
    std::set<char> charSet;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            charSet.insert(matrix[i][j]);
        }
    }

    return charSet.size();
}

int GetSize() {
    int size {};
    std::wstring answer {};
    std::wcin >> answer;

    while (swscanf(answer.c_str(), L"%d", &size) != 1 || size < 1 || size > MAX_SIZE) {
        fmt::print(INDIAN_RED_COLOR, "Нельзя ввести такой размер!\n");
        fmt::print(AQUA_COLOR, "> ");
        std::wcin >> answer;
    }

    return size;
}

int main() {
    setlocale(LC_ALL, "");
    int rows;
    int cols;

    fmt::print("Введите количество строк:\n");
    fmt::print(AQUA_COLOR, "> ");
    rows = GetSize();

    fmt::print("Введите количество столбцов:\n");
    fmt::print(AQUA_COLOR, "> ");
    cols = GetSize();

    char** matrix = new char*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new char[cols];
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = CharRandomGenerator();
        }
    }

    fmt::print("\nМатрица:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            fmt::print("{} ", matrix[i][j]);
        }
        fmt::print("\n");
    }

    fmt::print("\nКоличество различных элементов: {}\n", NumberCount(matrix, rows, cols));

    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}

char CharRandomGenerator() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<char> dist(33, 126);

    return dist(mt);
}
