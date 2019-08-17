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

    Matrix<int>A(size, size, value);
    A.print();

    Matrix<int>B(size, size, value + 3);
    B.print();

    std::vector<std::vector<int>> matrix_test({{2, 1}, {1, 0}});

    Matrix<int>C(matrix_test);
    C.print();

    std::cout << C(1, 0) << std::endl;

    Matrix<int>D = C;
    C.print();

    Matrix<int> E = C + D;
    E.print();

    Matrix<int> F = C - D;
    F.print();

    // std::cout << F.shape() << std::endl;

    // Matrix<int> G = C * D;
    // G.print();
}

