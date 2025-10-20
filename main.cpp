#include <iostream>

int** create(size_t rows, size_t cols);
void remove(int** m, size_t rows, size_t cols);
void input(int** m, size_t rows, size_t cols);
void output(const int* const* m, size_t rows, size_t cols);

int main()
{
    size_t rows = 0, cols = 0;
    std::cin >> rows >> cols;
    if (!std::cin) {
        return 1;
    }

    int** m = nullptr;

    try {
        m = create(rows, cols);
    } catch (...) {
        return 2;
    }

    for (size_t i = 0; i < rows && std::cin; ++i) {
        for (size_t j = 0; j < cols && std::cin; ++j) {
            std::cin >> m[i][j];
        }
    }

    if (!std::cin) {
        remove(m, rows, cols);
        return 1;
    }

    output(m, rows, cols);

    remove(m, rows, cols);

    return 0;
}

void input(int** m, size_t rows, size_t cols) {}

void output(const int* const* m, size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            std::cout << m[i][j];
            if (j + 1 < cols) std::cout << " ";
        }
        std::cout << "\n";
    }
}

int** create(size_t rows, size_t cols) {
    int** result = new int*[rows];
    size_t i = 0;
    try {
        for (; i < rows; ++i) {
            result[i] = new int[cols];
        }
    }
    catch (...) {
        for (size_t j = 0; j < i; ++j) {
            delete[] result[j];
        }
        delete[] result;
        throw;
    }
    return result;
}

void remove(int** m, size_t rows, size_t /*cols*/) {
    if (m == nullptr) return;
    for (size_t i = 0; i < rows; ++i) {
        delete[] m[i];
    }
    delete[] m;
}
