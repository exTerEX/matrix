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

<<<<<<< HEAD
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
=======
    Matrix<int, unsigned>B(3, 4);
    B.print();

    Matrix<int, unsigned>C(3, 4, 3);
    C.print();

     Matrix<int, unsigned>D = B;
    D.print();
>>>>>>> 080c5369a9f01da3cb7f91b6124b6e6920242a6b

    Matrix<int, unsigned>E({1, 2, 3, 4});
    E.print();

    Matrix<int, unsigned> F({{2, 0, 1, 0}, {1, 2, 0, 4}});
    F.print();

    // Operator tests
    std::cout << F(1, 2) << std::endl;

    Matrix<int, unsigned>G(3, 4, 8);
    G.print();

    Matrix<int, unsigned>plus = G + C;
    plus.print();

    Matrix<int, unsigned>minus = G - C;
    minus.print();

    /*Matrix<int, unsigned>product = G*C;
    product.print();*/
}