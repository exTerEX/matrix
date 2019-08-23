#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <limits>
#include <stdint.h>

#include "src/MatrixTemplate.h"

int main(int argc, char** argv) {
    Matrix<int, unsigned> test_square_init(2);
    test_square_init.print();

    Matrix<int, unsigned> test_row_col_init(2, 3);
    test_row_col_init.print();

    Matrix<int, unsigned> test_row_col_data_init(2, 3, 5);
    test_row_col_data_init.print();

    Matrix<int, unsigned> test_vector_init({1, 2, 3, 4});
    test_vector_init.print();

    Matrix<int, unsigned> test_vector_vector_init({{10, -6},{-8, 19}});
    test_vector_vector_init.print();

    Matrix<int, unsigned> test_another_vector_vector_init({{5, 8},{9, 3}});
    test_another_vector_vector_init.print();

    Matrix<int, unsigned> test_plus_operator = test_vector_vector_init + test_another_vector_vector_init;
    test_plus_operator.print();
    
    Matrix<int, unsigned> test_minus_operator = test_vector_vector_init - test_another_vector_vector_init;
    test_minus_operator.print();

    Matrix<int, unsigned> test_multiply_operator = test_vector_vector_init*test_another_vector_vector_init;
    test_multiply_operator.print();

    Matrix<int, unsigned> test_transpose_operator = test_minus_operator.transpose();
    test_transpose_operator.print();

}