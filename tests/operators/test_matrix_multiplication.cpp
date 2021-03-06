#include "libmatrix/matrix.hpp"
#include <cassert>

// Test matrix
Matrix::Matrix<int> m1({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
Matrix::Matrix<int> n1({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});

Matrix::Matrix<int> m2({{1, 2}, {3, 4}, {5, 6}});
Matrix::Matrix<int> n2({{1, 2, 3}, {4, 5, 6}});

Matrix::Matrix<int> m3({{1, 2, 3}, {4, 5, 6}});
Matrix::Matrix<int> n3({{1, 2}, {3, 4}, {5, 6}});

void square_multiplication() {
  Matrix::Matrix<int> expected1({{30, 36, 42}, {66, 81, 96}, {102, 126, 150}});
  Matrix::Matrix<int> result1 = m1 * n1;

  assert(expected1 == result1);

  Matrix::Matrix<int> expected2({{9, 12, 15}, {19, 26, 33}, {29, 40, 51}});
  Matrix::Matrix<int> result2 = m2 * n2;

  assert(expected2 == result2);

  Matrix::Matrix<int> expected3({{22, 28}, {49, 64}});
  Matrix::Matrix<int> result3 = m3 * n3;

  assert(expected3 == result3);
}

int main() { square_multiplication(); }
