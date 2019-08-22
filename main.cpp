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

    Matrix<int, unsigned>B(3, 4);
    B.print();

    Matrix<int, unsigned>C(3, 4, 3);
    C.print();

     Matrix<int, unsigned>D = B;
    D.print();

    Matrix<int, unsigned>E({1, 2, 3, 4});
    E.print();

    Matrix<int, unsigned> F({{2, 0, 1, 0}, {1, 2, 0, 4}});
    F.print();

    Matrix<int, unsigned>minus = A - B;
    minus.print();

    Matrix<int, unsigned>product = A*B;
    product.print();

    Matrix<int, unsigned>test_transpose({{1, 2}, {3, 4}, {5, 6}});
    test_transpose.print();

    Matrix<int, unsigned>transposed_matrix = test_transpose.transpose();
    transposed_matrix.print();


}