#include "libmatrix/matrix.hpp"
#include <cassert>

// Test matrix
libmatrix::Matrix<int> m({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
libmatrix::Matrix<int> n({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});

void square_multiplication() {
  libmatrix::Matrix<int> expected(
      {{30, 36, 42}, {66, 81, 96}, {102, 126, 150}});
  libmatrix::Matrix<int> result = m * n;

  assert(expected == result);
}

int main() { square_multiplication(); }
