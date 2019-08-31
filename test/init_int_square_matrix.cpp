#include "src/Matrix.h"

int main(int argc, char** argv) {
    // Init square matrix
    Matrix<int> test_matrix(5);
    // Print instant result
    test_matrix.print();

    // Manipulate the content

    // Print the updated matrix
    test_matrix.print();

    // Input float/double values

    // Print updated matrix
    test_matrix.print();

    // Input unsupported values

    // print updated matrix
    test_matrix.print();
}