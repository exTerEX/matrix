#include "include/libmatrix/matrix.hpp"
#include <iostream>
#include <vector>

std::vector<std::vector<int>> arr({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});

int main(int argc, char **argv) {
  libmatrix::matrix<int> m({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});

  m.print();
}
