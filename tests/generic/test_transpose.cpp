#include "libmatrix/matrix.hpp"
#include <cassert>

// Test matrix
Matrix::Matrix<int> m({{1, 2}, {3, 4}, {5, 6}});

void test() {
  Matrix::Matrix<int> expected({{1, 3, 5}, {2, 4, 6}});
  Matrix::Matrix<int> result = m.transpose();

  assert(expected == result);
}

int main() { test(); }
