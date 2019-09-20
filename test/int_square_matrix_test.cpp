#include "src/Matrix.h"

int main(int argc, char** argv) {
    
}

void test_init() {
    // Init square matrix
    Matrix<int> test_matrix_int(5);
    // Print instant result
    test_matrix_int.print();

    // Input float values
    Matrix<float> test_matrix_float(5);
    // Print updated matrix
    test_matrix_float.print();

    // Input double values
    Matrix<double> test_matrix_double(5);

    // print updated matrix
    test_matrix_double.print();
}