#include "libmatrix/matrix.hpp"
#include <cassert>

// Test matrix
libmatrix::Matrix<int> m({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});

libmatrix::Matrix<int> expected_m({{2, 4, 6}, {8, 10, 12}, {14, 16, 18}});

libmatrix::Matrix<int> n({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});

libmatrix::Matrix<int> expected_n({{4, 8, 12}, {16, 20, 24}, {28, 32, 36}});

int main(int argc, char **argv) {
  m *= 2;

  assert(m == expected_m);

  libmatrix::Matrix<int> result = n * 4;

  assert(result == expected_n);
}
