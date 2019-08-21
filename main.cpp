#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <limits>
#include <stdint.h>

#include "src/MatrixTemplate.h"

int main(int argc, char** argv) {
    // Interaction tests
    Matrix<int, unsigned>A(3);
    A.print();

    Matrix<int, unsigned>B(3, 2);
    B.print();

    Matrix<int, unsigned>C(3, 4, 2);
    C.print();

    Matrix<int, unsigned>D = B;
    D.print();


    Matrix<int, unsigned>E({1, 2, 3, 4, 5});
    E.print();

    std::vector<std::vector<int>>test_matrix({{1, 2, 3}, {1, 2, 3}});
    Matrix<int, unsigned>F(test_matrix);
    F.print();

    // Operator tests

}

