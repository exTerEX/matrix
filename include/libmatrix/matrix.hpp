/********************************************************************************

MIT License

Copyright (c) 2019 Andreas Sagen

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

********************************************************************************/

#include <iostream>
#include <vector>

#ifndef MATRIX_HPP
#define MATRIX_HPP

namespace libmatrix {

template <class T> // (T)ype
class matrix {
private:
  unsigned rows, cols;
  std::vector<std::vector<T>> data;

  void fill_matrix(T n) {
    data.resize(rows);
    for (unsigned i = 0; i < rows; i++) {
      data[i].resize(cols, n);
    }
  }

protected:
  unsigned getRowSize() const { return this->rows; }

  unsigned getColSize() const { return this->cols; }

public:
  matrix(unsigned size, T fill = 0) {
    rows = size;
    cols = size;

    fill_matrix(fill);
  }

  matrix(unsigned rowSize, unsigned colSize, T fill = 0) {
    rows = rowSize;
    cols = colSize;

    fill_matrix(fill);
  }

  /*~matrix()
  {
  }*/

  matrix(const matrix &m) {
    rows = m.getRowSize();
    cols = m.getColSize();
    data = m.data;
  }

  matrix(std::vector<T> m) {
    rows = m.size();
    cols = 1;

    data.resize(rows);
    for (unsigned i = 0; i < rows; i++) {
      data[i].resize(cols, m[i]);
    }
  }

  matrix(std::vector<std::vector<T>> m) {
    rows = m.size();
    cols = m[0].size();
    data = m;
  }

  matrix operator()(unsigned row, unsigned col) { return this->data[row][col]; }

  matrix operator+(const matrix &m) {
    matrix product(rows, cols);
    for (unsigned i = 0; i < rows; i++) {
      for (unsigned j = 0; j < cols; j++) {
        product(i, j) = this->data[i][j] + m.data[i][j];
      }
    }
    return product;
  }

  matrix operator*(T n) {
    matrix product(rows, cols);

    for (unsigned i = 0; i < rows; i++) {
      for (unsigned j = 0; j < cols; j++) {
        product(i, j) = this->data[i][j] * n;
      }
    }
    return product;
  }

  matrix operator*(const matrix &m) {
    matrix product(rows, m.getColSize());

    if (cols == m.getRowSize()) {
      T temp = 0.0;
      for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < m.getColSize(); j++) {
          temp = 0.0;
          for (unsigned k = 0; k < cols; k++) {
            temp += data[i][k] * m.data[i][j];
          }
          product(i, j) = temp;
        }
      }
      return product;
    } else {
      throw "Cannot multiply these matricies!";
    }
  }

  matrix operator^(T n) {}

  matrix transpose() {
    matrix product(rows, cols);
    for (unsigned i = 0; i < cols; i++) {
      for (unsigned j = 0; j < rows; j++) {
        product(i, j) = this->data[j][i];
      }
    }
    return product;
  }

  matrix inverse(const matrix &m) {
    matrix product(rows, cols);

    if (cols == m.getRowSize()) {
      for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
          product(i, j) =
              0; // TODO: Some math shit that need to be implemented...
        }
      }
    } else {
      throw "Cannot find inverse of this matrix.";
    }
    return product;
  }

  T determinant(const matrix &) {}

  unsigned shape() const { return 0; }

  void print() const {
    std::cout << "Matrix: " << std::endl;

    for (unsigned i = 0; i < rows; i++) {
      for (unsigned j = 0; j < cols; j++) {
        std::cout << "[" << data[i][j] << "]";
      }
      std::cout << std::endl;
    }
  }

  bool operator==(const matrix &m) {
    if (cols == m.getColSize() && rows == m.getRowSize()) {
      for (unsigned i = 0; i < m.getColSize(); i++) {
        for (unsigned j = 0; j < m.getRowSize(); j++) {
          if (data[i][j] != m.data[i][j]) {
            return false;
          }
        }
      }
      return true;
    } else {
      return false;
    }
  }

  bool operator!=(const matrix &m) {
    if (cols == m.getColSize() && rows == m.getRowSize()) {
      for (unsigned i = 0; i < m.getColSize(); i++) {
        for (unsigned j = 0; j < m.getRowSize(); j++) {
          if (data[i][j] != m.data[i][j]) {
            return true;
          }
        }
      }
      return false;
    } else {
      return true;
    }
  }
};
} // namespace libmatrix
#endif
