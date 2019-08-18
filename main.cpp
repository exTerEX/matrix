#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <limits>
#include <stdint.h>

#include "src/MatrixTemplate.h"

int main(int argc, char** argv) {
    int size = 2;
    int value = 1;

    Matrix<int, unsigned>A(size, size);
    A.print();

    Matrix<int, unsigned>B(size, size, value);
    B.print();

    std::vector<std::vector<int>> matrix_test({{2, 0, 1, 0}, {1, 2, 0, 4}});
    Matrix<int, unsigned>C(matrix_test);
    C.print();

    std::vector<int> a({1, 2, 3, 4});
    Matrix<int, unsigned> D(a);
    D.print();
}

