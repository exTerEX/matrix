#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <limits>
#include <stdint.h>

#include "src/MatrixTemplate.h"

int main(int argc, char** argv) {
    // Interaction tests
    Matrix<int, unsigned>A({{2, 0}, {1, 8}});
    A.print();

    Matrix<int, unsigned>B({{8, 9}, {-2, -1}});
    B.print();

    Matrix<int, unsigned>plus = A + B;
    plus.print();

    Matrix<int, unsigned>minus = A - B;
    minus.print();

    Matrix<int, unsigned>product = A*B;
    product.print();

    Matrix<int, unsigned>test_transpose({{1, 2}, {3, 4}, {5, 6}});
    test_transpose.print();

    Matrix<int, unsigned>transposed_matrix = test_transpose.transpose();
    transposed_matrix.print();

    
}