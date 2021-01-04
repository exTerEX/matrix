#include "libmatrix/matrix.hpp"
#include <cassert>

// Test matrix
libmatrix::Matrix<int> m({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
libmatrix::Matrix<int> n({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});

void test() {
  m.print();
  n.print();

  libmatrix::Matrix<int> expected({{2, 4, 6}, {8, 10, 12}, {14, 16, 18}});
  libmatrix::Matrix<int> result = m + n;

  result.print();

  assert(expected == result);
}

int main() { test(); }
