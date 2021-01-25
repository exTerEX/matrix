#include "libmatrix/matrix.hpp"
#include <cassert>

// Test matrix
Matrix::Matrix<int> m({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});

// Test m(x, y)
void round_bracket() {
  int x = 1;
  int y = 1;

  int expected = 5;
  int result = m(x, y);

  assert(expected == result);
}

int main() { round_bracket(); }
