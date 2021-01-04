/*
 * MIT License
 *
 * Copyright (c) 2019 Andreas Sagen
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <iostream>
#include <utility>
#include <vector>

#ifndef MATRIX_HPP
#define MATRIX_HPP

namespace libmatrix {

template <class T> // (T)ype
class Matrix {
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
  Matrix(unsigned size, T fill = 0) {
    rows = size;
    cols = size;

    fill_matrix(fill);
  }

  Matrix(unsigned rowSize, unsigned colSize, T fill = 0) {
    rows = rowSize;
    cols = colSize;

    fill_matrix(fill);
  }

  /*~Matrix()
  {
  }*/

  Matrix(const Matrix &m) {
    rows = m.getRowSize();
    cols = m.getColSize();
    data = m.data;
  }

  Matrix(std::vector<T> m) {
    rows = m.size();
    cols = 1;

    data.resize(rows);
    for (unsigned i = 0; i < rows; i++) {
      data[i].resize(cols, m[i]);
    }
  }

  Matrix(std::vector<std::vector<T>> m) {
    rows = m.size();
    cols = m[0].size();
    data = m;
  }

  /**
   * @brief Copy constructor of class Matrix<T> created to copy-and-swap.
   *
   * @param m A matrix to be copied.
   * @return Matrix& The assigned matrix.
   */
  Matrix &operator=(Matrix m) {
    std::swap(cols, m.cols);
    std::swap(rows, m.rows);
    std::swap(data, m.data);
    return *this;
  }

  T operator()(unsigned row, unsigned col) { return this->data[row][col]; }

  Matrix operator+(const Matrix &m) {
    Matrix product(rows, cols);
    for (unsigned i = 0; i < rows; i++) {
      for (unsigned j = 0; j < cols; j++) {
        product(i, j) = this->data[i][j] + m.data[i][j];
      }
    }
    return product;
  }

  Matrix operator*(T n) {
    Matrix product(rows, cols);

    for (unsigned i = 0; i < rows; i++) {
      for (unsigned j = 0; j < cols; j++) {
        product(i, j) = this->data[i][j] * n;
      }
    }
    return product;
  }

  Matrix operator*(const Matrix &m) {
    Matrix product(rows, m.getColSize());

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

  Matrix operator^(int n) {
    Matrix product(this->data);
    for (unsigned index = 1; index <= n; index++) {
      product *= product;
    }
    return product;
  }

  Matrix transpose() {
    Matrix product(rows, cols);
    for (unsigned i = 0; i < cols; i++) {
      for (unsigned j = 0; j < rows; j++) {
        product(i, j) = this->data[j][i];
      }
    }
    return product;
  }

  Matrix inverse(const Matrix &m) {
    Matrix product(rows, cols);

    if (cols == m.getRowSize()) {
      for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
          product(i, j) =
              0; // TODO: Some math shit that need to be implemented...
        }
      }
    } else {
      throw "Cannot find inverse of this Matrix.";
    }
    return product;
  }

  T determinant(const Matrix &) {}

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

  bool operator==(const Matrix &m) {
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

  bool operator!=(const Matrix &m) {
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
