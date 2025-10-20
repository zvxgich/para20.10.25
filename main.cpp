#include <iostream>

int** create(size_t rows, size_t cols);
void remove(int** m, size_t rows, size_t cols);
void input(int** m, size_t rows, size_t cols);
void output(const int* const* m, size_t rows, size_t cols);
int** convert(const int* t, size_t n, const size_t* lns, size_t rows);

int main()
{
    size_t rows = 0, cols = 0;

    std::cout << "Введите количество строк и столбцов матрицы\n";
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

    std::cout << "Введите элементы матрицы построчно\n";
    for (size_t i = 0; i < rows && std::cin; ++i) {
        for (size_t j = 0; j < cols && std::cin; ++j) {
            std::cin >> m[i][j];
        }
    }

    if (!std::cin) {
        remove(m, rows, cols);
        return 1;
    }

    std::cout << "Ваша матрица\n";
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

int** convert(const int* t, size_t n, const size_t* lns, size_t rows){
    int** res = new int*[rows];
    const int* position = t;
    for (size_t i =0; i < rows; ++i){
        size_t len = lns[i];
        res[i] = new int[len];
        for (size_t j=0; j<len; ++j){
            res[i][j] = *position;
            ++position;
        }
    }
    return res;
}
