#include "libmatrix/matrix.hpp"
#include <cassert>

// Test matrix
Matrix::Matrix<int> m({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
Matrix::Matrix<int> n({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});

void test() {
  Matrix::Matrix<int> expected({{0, 0, 0}, {0, 0, 0}, {0, 0, 0}});
  Matrix::Matrix<int> result = m - n;

  assert(expected == result);
}

int main() { test(); }
