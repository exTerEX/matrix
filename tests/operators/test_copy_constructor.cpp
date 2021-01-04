#include "libmatrix/matrix.hpp"
#include <cassert>

// Test matrix
libmatrix::Matrix<int> m({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});

void assignment() {
  libmatrix::Matrix<int> expected = m;
  libmatrix::Matrix<int> result = m;

  assert(expected == result);
}

int main() { assignment(); }
