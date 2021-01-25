#include "libmatrix/matrix.hpp"
#include <cassert>

// Test matrix
Matrix::Matrix<int> m({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});

void assignment() {
  Matrix::Matrix<int> expected = m;
  Matrix::Matrix<int> result = m;

  assert(expected == result);
}

int main() { assignment(); }
